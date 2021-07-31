/*
 * DebugView.cpp
 *
 *  Created on: 2021年7月30日
 *      Author: HunterLeo
 */


#include "DebugHandler.h"

DebugHandler::DebugHandler(LinkedList<ZKTextView *> *list) {
	size = list->size;
	textViewList = list->toV();
	debugMessage = new LinkedList<char *>();
}

DebugHandler::DebugHandler(int size, ZKTextView **list) {
	this->size = size;
	this->textViewList = (ZKTextView **) malloc (this->size * sizeof(ZKTextView *));
	for (int i = 0; i < size;i ++) {
		this->textViewList[i] = list[i];
	}
	debugMessage = new LinkedList<char *>();
}

DebugHandler::~DebugHandler() {
	free(textViewList);
	free(debugMessage);
}

void DebugHandler::addDebugMessage(char *message) {
	if (message == NULL || message[0] == 0)
		return;
	char *newDebugMessage = (char *) malloc (strlen(message));
	memcpy(newDebugMessage, message, strlen(message) + 1);
	if (debugMessage->size < this->size) {
		debugMessage->addLast(newDebugMessage);
	}
	else {
		char *oldMessage = debugMessage->removeFirst();
		free(oldMessage);
		debugMessage->addLast(newDebugMessage);
	}
	for (int i = 0;i < debugMessage->size;i ++) {
		textViewList[i]->setText(debugMessage->get(i));
	}
}

void DebugHandler::clear(){
	debugMessage->removeAll();
	for(int i = 0;i<this->size;i++){
		textViewList[i]->setText("");
	}
}
