#include "LQueue.h"
#include "Node.h"

LQueue::LQueue() {
	front = 0;
	back = 0;
	num_elements = 0;
}

LQueue::~LQueue() {
	if (back != 0) {
		if (back->hasNext()) {
			deleteList(back->getNext());
			delete back->getNext();
		}

		delete back;
	}
}

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
	return 0;
}

void LQueue::enqueue(int i) {
	++i;
}

int LQueue::dequeue() {
	return 0;
}
