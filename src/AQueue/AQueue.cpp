#include "AQueue.h"

AQueue::AQueue() {
	capacity = 10;
	ringbuffer = new int[capacity];
	front = ringbuffer;
	back = front;
	queue_size = 0;
}

AQueue::~AQueue() {
	delete[] ringbuffer;
}

void AQueue::enqueue(int i) {
	i++;
}

int AQueue::dequeue() {
	return 0;
}

int AQueue::size() {
	return 0;
}
