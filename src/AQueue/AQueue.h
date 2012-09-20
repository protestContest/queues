#ifndef __AQUEUE_H__
#define __AQUEUE_H__

class AQueue {
	private:
	int capacity;	// size of ringbuffer
	int* ringbuffer;	// stores elements
	int front;	// index of element in front
	int back;	// index of next free space at the back
	int queue_size;		// num elements
	
	public:
	AQueue();
	~AQueue();
	void enqueue(int i);	// add to back
	int dequeue();	// take from front
	int size();

};

#endif
