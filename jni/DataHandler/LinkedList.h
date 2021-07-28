//
// Created by YangHui on 2021/7/28.
//

#ifndef SERIALSCREENCORE_LINKEDLIST_H
#define SERIALSCREENCORE_LINKEDLIST_H

#include "cstdlib"
#include "string"

using namespace std;

template<typename V>
class LinkedList {
private:
    typedef struct Struct_Node {
        V value;
        Struct_Node *next;
        Struct_Node *pre;
    } Node;
public:
    Node *head = NULL; // head是一个实际存在的，不存放任何数据的头指针
    Node *rear = NULL; // rear是一个不分配内存，指向最后一个元素的指针，当列表为空，rear指向head所指向的元素
public:
    int size;
    LinkedList();
    LinkedList(V *list, int len);
    ~LinkedList();
    void addFirst(V value);
    void addLast(V value);
    void addLastAll(LinkedList<V> *list);
    V removeFirst();
    V getFirst();
    V removeLast();
    V getLast();
    V get(int num);
    LinkedList<V> *getFirst(int num);
    LinkedList<V> *getLast(int num);
    LinkedList<V> *removeFirst(int num);
    LinkedList<V> *removeLast(int num);
    V *pop();
    V *toV();
    void push(V value);
};

class LinkedListNotEnoughException : exception {
};

template<typename V>
LinkedList<V>::LinkedList() {
	size = 0;
    head = new Node();
    head->next = NULL;
    head->pre = NULL;
    rear = head;
}


template<typename V>
LinkedList<V>::LinkedList(V *list, int len) {
	size = 0;
    head = new Node();
    head->next = NULL;
    head->pre = NULL;
    rear = head;
    for (int i = 0; i < len; i++) {
        this->addLast(list[i]);
    }
}

template<typename V>
LinkedList<V>::~LinkedList() {
    while (rear != head) {
        Node *p = rear;
        rear = rear->pre;
        free(p);
    }
    free(head);
}

template<typename V>
void LinkedList<V>::addFirst(V value) {
    Node *newNode = new Node();
    newNode->value = value;
    newNode->pre = head;
    newNode->next = head->next;
    if (head->next != NULL) {
        head->next->pre = newNode;
    }
    head->next = newNode;
    if (rear == head) {
        rear = newNode;
    }

    size++;
}

template<typename V>
void LinkedList<V>::addLast(V value) {
    Node *newNode = new Node();
    newNode->value = value;
    rear->next = newNode;
    newNode->pre = rear;
    newNode->next = NULL;
    rear = newNode;
    size++;
}

template<typename V>
V LinkedList<V>::removeFirst() {
    Node *p = head->next;
    if (p != NULL) {
        head->next = p->next;
        if (p->next != NULL) {
            p->next->pre = head;
        }
        V value = p->value;
        size--;
        if(size == 0) rear = head;
        free(p);
        return value;
    } else {
        throw LinkedListNotEnoughException();
    }
}

template<typename V>
V LinkedList<V>::removeLast() {
    Node *p = rear;
    if (p != head) {
        rear->pre->next = NULL;
        rear = rear->pre;
        V value = p->value;
        size--;
        free(p);
        return value;
    } else {
        throw LinkedListNotEnoughException();
    }
}


template<typename V>
void LinkedList<V>::addLastAll(LinkedList<V> *list) {
	Node *p = list->head;
	for (; p != list->rear; p = p->next) {
		if (p == list->head) {
		    continue;
		}
		this->addLast(p->value);
	}
	this->addLast(p->value);
}

template<typename V>
V LinkedList<V>::get(int num) {
	if (num >= size) {
		throw LinkedListNotEnoughException();
	}
	Node *p = head->next;
	for (int i = 0;i < num;i ++) {
		p = p->next;
	}
	return p->value;
}

template<typename V>
V LinkedList<V>::getFirst() {
    if (head->next != NULL) {
        return head->next->value;
    }
    throw LinkedListNotEnoughException();
}

template<typename V>
V *LinkedList<V>::toV() {
	V *list = (V *) malloc (size * sizeof(V));
	for (int i = 0;i < size;i ++) {
		list[i] = get(i);
	}
	return list;
}

template<typename V>
V LinkedList<V>::getLast() {
    if (rear != head) {
        return rear->value;
    }
    throw LinkedListNotEnoughException();
}

template<typename V>
LinkedList<V> *LinkedList<V>::getFirst(int num) {
    if (this->size < num) {
        throw LinkedListNotEnoughException();
    }
    LinkedList<V> *list = new LinkedList<V>();
    Node *p = head->next;

    for (int i = 0; i < num; i++) {
        list->addFirst(p->value);
        p = p->next;
    }
    return list;
}

template<typename V>
LinkedList<V> *LinkedList<V>::getLast(int num) {
    if (this->size < num) {
        throw LinkedListNotEnoughException();
    }
    LinkedList<V> *list = new LinkedList<V>();
    Node *p = rear;
    for (int i = num - 1; i >= 0; i--) {
        list->addLast(p->value);
        p = p->pre;
    }
    return list;
}

template<typename V>
LinkedList<V> *LinkedList<V>::removeFirst(int num) {
    if (this->size < num) {
        throw LinkedListNotEnoughException();
    }
    LinkedList<V> *list = new LinkedList<V>();
    for (int i = 0; i < num; i++) {
        list->addLast(this->removeFirst());
    }
    return list;
}

template<typename V>
LinkedList<V> *LinkedList<V>::removeLast(int num) {
    if (this->size < num) {
        throw LinkedListNotEnoughException();
    }
    LinkedList<V> *list = new LinkedList<V>();
    for (int i = 0; i < num; i++) {
        list->addFirst(this->removeLast());
    }
    return list;
}

template<typename V>
V *LinkedList<V>::pop() {
    return removeLast();
}

template<typename V>
void LinkedList<V>::push(V value) {
    addLast(value);
}

#endif //SERIALSCREENCORE_LINKEDLIST_H
