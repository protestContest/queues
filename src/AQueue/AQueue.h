#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue {
	private:
	int capacity;	// size of ringbuffer
	int* ringbuffer;	// stores elements
	int front;	// index of element in front
	int back;	// index of next free space at the back
	int queue_size;		// num elements
	
	public:
	Queue();
	~Queue();
	void enqueue(int i);	// add to back
	int dequeue();	// take from front
	int size();
	bool isEmpty();

};

#endif
