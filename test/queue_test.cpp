#include "gtest/gtest.h"
#include "../src/Queue.h"
#include <iostream>
using std::cout;
using std::endl;

TEST(QueueTest, Constructor) {
	Queue* q = new Queue();

	EXPECT_EQ(q->size(), 0);

	delete q;
}

TEST(QueueTest, Enqueue) {
	Queue* q = new Queue();

	for (int i = 0; i < 150; ++i) {
		q->enqueue(i);
	}

	EXPECT_EQ(q->size(), 150);
}

TEST(QueueTest, Dequeue) {
	Queue* q = new Queue();

	for (int i = 1; i <= 15; ++i) {
		q->enqueue(i);
	}

	for (int i = 15; i <= 1; --i) {
		EXPECT_EQ(i, q->dequeue());
	}

	delete q;
}

TEST(QueueTest, IsEmpty) {
	Queue* q = new Queue();

	EXPECT_EQ(true, q->isEmpty());

	for (int i = 0; i < 50; ++i) {
		q->enqueue(i);
	}

	EXPECT_EQ(false, q->isEmpty());

	for (int i = 0; i < 50; ++i) {
		q->dequeue();
	}

	EXPECT_EQ(true, q->isEmpty());

	delete q;
}

