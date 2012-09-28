#ifndef __LQUEUE_H__
#define __LQUEUE_H__

#include "Node.h"

class Queue {
private:
	Node* front;
	Node* back;
	int num_elements;
	void deleteList(Node*);
	
public:
	Queue();
	~Queue();
	bool isEmpty();
	int size();
	void enqueue(int);
	int dequeue();
};

#endif
