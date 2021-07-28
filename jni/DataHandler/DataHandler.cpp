/**
* @File     DataHandler.cpp
* @Author   YangHui
* @Date     2021/7/28 13:14
* @Note     TODO       
*/

//
// Created by YangHui on 2021/7/28.
//

#include "DataHandler.h"
#include "LinkedList.h"
#include "utils/Log.h"

uint8_t frameHeader[2] = {0xEB, 0x90};

void emptyHandler(LinkedList<uint8_t> *list) {

}

LinkedList<uint8_t> *DataHandler::buffer = new LinkedList<uint8_t>();
void (* DataHandler::handler)(LinkedList<uint8_t> *) = emptyHandler;

void DataHandler::BufferHandler(LinkedList<uint8_t> *newData) {
    buffer->addLastAll(newData);
    LOGD("BufferSize: %d", buffer->size);
    for (int i = 0;i < buffer->size;i ++) {
    	LOGD("0x%x ", buffer->get(i));
    }
    int dataLen;
    while (true) {
        if (buffer->size < 4) {
            throw DataHandlerException();
        }
        if (buffer->removeFirst() == frameHeader[0]) {
            if (buffer->removeFirst() == frameHeader[1]) {
                dataLen = (buffer->removeFirst() << 8) | (buffer->removeFirst());
                LOGD("%d", dataLen);
                break;
            } else {
                continue;
            }
        } else {
            continue;
        }
    }
    if (buffer->size < dataLen) {
        buffer->addFirst(dataLen & 0xFF);
        buffer->addFirst((dataLen & 0xFF00) >> 8);
        buffer->addFirst(frameHeader[1]);
        buffer->addFirst(frameHeader[0]);
        return;
    }
    handler(buffer->removeFirst(dataLen));
}


