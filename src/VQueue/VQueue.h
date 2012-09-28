#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <list>
using std::list;

class Queue {
	private:
	std::list<int>* list;
	
	public:
	Queue();
	~Queue();
	void enqueue(int i);	// add to back
	int dequeue();	// take from front
	int size();
	bool isEmpty();

};

#endif
