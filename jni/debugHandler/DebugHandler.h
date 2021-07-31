/*
 * DebugView.h
 *
 *  Created on: 2021年7月30日
 *      Author: HunterLeo
 */

#ifndef JNI_DEBUGHANDLER_DEBUGHANDLER_H_
#define JNI_DEBUGHANDLER_DEBUGHANDLER_H_

#include "../include/control/ZKTextView.h"
#include "../DataHandler/LinkedList.h"

class DebugHandler {

private:
	int size;
	ZKTextView **textViewList;
	LinkedList<char *> *debugMessage;

public:
	DebugHandler(LinkedList<ZKTextView *> *textViewList);
	DebugHandler(int size, ZKTextView **textViewList);
	~DebugHandler();
	void addDebugMessage(char *message);
	void clear();
};


#endif /* JNI_DEBUGHANDLER_DEBUGHANDLER_H_ */
