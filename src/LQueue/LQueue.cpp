#include "LQueue.h"
#include "Node.h"
#include <assert.h>

LQueue::LQueue() {
	front = 0;
	back = 0;
	num_elements = 0;
}

LQueue::~LQueue() {
	if (front != 0) {
		if (front->hasNext()) {
			deleteList(front->getNext());
			delete front->getNext();
		}

		delete front;
	}
}

// recursive magic
void LQueue::deleteList(Node* n) {
	if (n->hasNext()) {
		deleteList(n->getNext());
		delete n->getNext();
	}

	return;
}

bool LQueue::isEmpty() {
	return num_elements == 0;
}

int LQueue::size() {
	return num_elements;
}

void LQueue::enqueue(int i) {
	Node* newNode = new Node(i);
	if (back != 0) {
		back->setNext(newNode);
	}
	back = newNode;
	if (front == 0) {
		front = newNode;
	}
	++num_elements;
}

int LQueue::dequeue() {
	assert(!isEmpty());
	assert(front != 0);

	Node* curNode = front;
	int val = curNode->getValue();
	front = curNode->getNext();
	delete curNode;
	--num_elements;

	return val;
}
