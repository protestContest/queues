#include "AQueue.h"
#include <assert.h>

AQueue::AQueue() {
	capacity = 10;
	ringbuffer = new int[capacity];
	front = 0;
	back = 0;
	queue_size = 0;
}

AQueue::~AQueue() {
	delete[] ringbuffer;
}

void AQueue::enqueue(int i) {
	if (queue_size >= capacity) {
		int* newbuffer = new int[capacity*2];
// TODO: double capacity here
	}

	assert(queue_size < capacity);

	ringbuffer[back] = i;
	back = (++back) % capacity;

	++queue_size;
}

int AQueue::dequeue() {
	return 0;
}

int AQueue::size() {
	return queue_size;
}
