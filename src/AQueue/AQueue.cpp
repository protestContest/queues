#include "AQueue.h"
#include <assert.h>
#include <cmath>

Queue::Queue() {
	capacity = 10;
	ringbuffer = new int[capacity];
	front = 0;
	back = 0;
	queue_size = 0;
}

Queue::~Queue() {
	delete[] ringbuffer;
}

void Queue::enqueue(int i) {
	if (queue_size >= capacity) {
		int* newbuffer = new int[capacity*2];
		int* oldbuffer = ringbuffer;
		for (int i = 0; i < capacity; ++i) {
			newbuffer[i] = oldbuffer[(front+i)%capacity];
		}
		ringbuffer = newbuffer;
		delete[] oldbuffer;
		front = 0;
		back = queue_size;
		capacity *= 2;
	}

	assert(queue_size < capacity);

	ringbuffer[back] = i;
	back = (++back) % capacity;

	++queue_size;
}

int Queue::dequeue() {
	assert(queue_size > 0);

	if (queue_size <= 0.25*capacity) {
		int* newbuffer = new int[(int) ceil(0.25*capacity)];
		int* oldbuffer = ringbuffer;
		for (int i = 0; i < queue_size; ++i) {
			newbuffer[i] = oldbuffer[(front+i)%capacity];
		}
		ringbuffer = newbuffer;
		delete[] oldbuffer;
		front = 0;
		back = queue_size;
		capacity = (int) ceil(0.25*capacity);
	}

	assert(queue_size > 0.25*capacity);

	int temp = ringbuffer[front];
	front = ++front % capacity;
	--queue_size;
	return temp;
}

int Queue::size() {
	return queue_size;
}

bool Queue::isEmpty() {
	return queue_size == 0;
}
