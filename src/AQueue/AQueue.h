#ifndef __AQUEUE_H__
#define __AQUEUE_H__

class AQueue {
	private:
	int capacity;
	int* ringbuffer;
	int* front;
	int* back;
	int queue_size;
	
	public:
	AQueue();
	~AQueue();
	void enqueue(int i);
	int dequeue();
	int size();

};

#endif
