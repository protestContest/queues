#include "./VQueue.h"
#include <assert.h>

Queue::Queue() {
	list = new std::list<int>;
}

Queue::~Queue() {
	delete list;
}

void Queue::enqueue(int i) {
	list->push_back(i);	
}

int Queue::dequeue() {
	int v = list->front();
	list->pop_front();
	return v;
}

int Queue::size() {
	return list->size();
}

bool Queue::isEmpty() {
	return list->empty();
}
