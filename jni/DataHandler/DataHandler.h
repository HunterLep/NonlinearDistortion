//
// Created by YangHui on 2021/7/28.
//

#ifndef SERIALSCREENCORE_DATAHANDLER_H
#define SERIALSCREENCORE_DATAHANDLER_H

#include "LinkedList.h"

class DataHandler {
public:
    static LinkedList<uint8_t> *buffer;
    static void (*handler) (LinkedList<uint8_t> *);
    static void BufferHandler(LinkedList<uint8_t> *newData);
};

class DataHandlerException : exception{};

#endif //SERIALSCREENCORE_DATAHANDLER_H
