/*
 * ProtocolData.h
 *
 *  Created on: Sep 7, 2017
 *      Author: guoxs
 */

#ifndef _UART_PROTOCOL_DATA_H_
#define _UART_PROTOCOL_DATA_H_

#include <string>
#include "CommDef.h"

/******************** CmdID ***********************/
#define CMDID_NormalSignal 0x01
#define CMDID_HighDistortion 0x02
#define CMDID_LowDistortion 0x03
#define CMDID_BothDistortion 0x04
#define CMDID_CrossDistortion 0x05
/**************************************************/

/******************** 错误码 Error code ***********************/
#define ERROR_CODE_CMDID			1
/**************************************************/

typedef struct {
	double value;
} SProtocolData;

#endif /* _UART_PROTOCOL_DATA_H_ */
