/*
 * UartContext.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: guoxs
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <termio.h>
#include <sys/ioctl.h>

#include "uart/UartContext.h"
#include "utils/Log.h"
#include "../DataHandler/DataHandler.h"

#define UART_DATA_BUF_LEN			16384	// 16KB

extern int parseProtocol(const BYTE *pData, UINT len);
extern void parseProtocal(LinkedList<uint8_t> *);

static const char* getBaudRate(UINT baudRate) {
	struct {
		UINT baud;
		const char *pBaudStr;
	} baudInfoTab[] = {
		{ B1200, "B1200" },
		{ B2400, "B2400" },
		{ B4800, "B4800" },
		{ B9600, "B9600" },
		{ B19200, "B19200" },
		{ B38400, "B38400" },
		{ B57600, "B57600" },
		{ B115200, "B115200" },
		{ B230400, "B230400" },
		{ B460800, "B460800" },
		{ B921600, "B921600" }
	};

	int len = sizeof(baudInfoTab) / sizeof(baudInfoTab[0]);
	for (int i = 0; i < len; ++i) {
		if (baudInfoTab[i].baud == baudRate) {
			return baudInfoTab[i].pBaudStr;
		}
	}

	return NULL;
}

UartContext::UartContext() :
	mIsOpen(false),
	mUartID(0),
	mDataBufPtr(NULL),
	mDataBufLen(0) {

}

UartContext::~UartContext() {
	delete[] mDataBufPtr;
	closeUart();
}

bool UartContext::openUart(const char *pFileName, UINT baudRate) {
	LOGD("openUart pFileName = %s, baudRate = %s\n", pFileName, getBaudRate(baudRate));
	mUartID = open(pFileName, O_RDWR|O_NOCTTY);

	if (mUartID <= 0) {
		mIsOpen = false;
	} else {
		struct termios oldtio = { 0 };
		struct termios newtio = { 0 };
		tcgetattr(mUartID, &oldtio);

		newtio.c_cflag = baudRate|CS8|CLOCAL|CREAD;
		newtio.c_iflag = 0;	// IGNPAR | ICRNL
		newtio.c_oflag = 0;
		newtio.c_lflag = 0;	// ICANON
		newtio.c_cc[VTIME] = 0; /* inter-character timer unused */
		newtio.c_cc[VMIN] = 1; /* blocking read until 1 character arrives */
		tcflush(mUartID, TCIOFLUSH);
		tcsetattr(mUartID, TCSANOW, &newtio);

		// 设置为非阻塞 Set to non-blocking
		fcntl(mUartID, F_SETFL, O_NONBLOCK);

		mIsOpen = run("uart");
		if (!mIsOpen) {
			close(mUartID);
			mUartID = 0;
		}

		LOGD("openUart mIsOpen = %d\n", mIsOpen);
	}

	return mIsOpen;
}

void UartContext::closeUart() {
	LOGD("closeUart mIsOpen: %d...\n", mIsOpen);
	if (mIsOpen) {
		requestExit();

		close(mUartID);
		mUartID = 0;
		mIsOpen = false;
	}
}

bool UartContext::sendMessage(const BYTE *pData, UINT len) {
	if (!mIsOpen) {
		return false;
	}

	if (write(mUartID, pData, len) != (int) len) {	// fail
		LOGD("sendMessage Fail\n");
		return false;
	}

//	 success
	LOGD("send Success\n");

	return true;
}

bool UartContext::sendNum(const int *pData, UINT len){
	if (!mIsOpen) {
		return false;
	}

	if (write(mUartID, pData , len) != (int) len) {
		LOGD("sendNumber Fail");
		return false;
	}

	LOGD("send Success\n");

	return true;

}

UartContext* UartContext::getInstance() {
	static UartContext sUC;
	return &sUC;
}

bool UartContext::readyToRun() {
	if (mDataBufPtr == NULL) {
		mDataBufPtr = new BYTE[UART_DATA_BUF_LEN];
	}

	if (mDataBufPtr == NULL) {
		closeUart();
	}

	return (mDataBufPtr != NULL);
}

bool UartContext::threadLoop() {
	if (mIsOpen) {
//		int readNum = read(mUartID, mDataBufPtr + mDataBufLen, UART_DATA_BUF_LEN - mDataBufLen);
		int readNum = read(mUartID, mDataBufPtr, UART_DATA_BUF_LEN);

		if (readNum > 0) {
//			mDataBufLen += readNum;
//			int len = parseProtocol(mDataBufPtr, mDataBufLen);
//			if ((len > 0) && (len < mDataBufLen)) {
//				memcpy(mDataBufPtr, mDataBufPtr + len, mDataBufLen - len);
//			}
//			mDataBufLen -= len;

			LOGD("Received: %d", readNum);
			LinkedList<uint8_t>* readData = new LinkedList<uint8_t>(mDataBufPtr, readNum);
			DataHandler::handler = parseProtocal;
			try{
				DataHandler::BufferHandler(readData);
			} catch (DataHandlerException &e){
				LOGD("Handler Error");
			} catch (LinkedListNotEnoughException &e) {
				LOGD("LinkedList Error");
			}
		} else {
			Thread::sleep(50);
		}

		return true;
	}

	return false;
}
