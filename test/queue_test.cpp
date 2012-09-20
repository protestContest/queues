#include "gtest/gtest.h"
#include "AQueue/AQueue.h"

TEST(AQueueTest, Constructor) {
	AQueue* q = new AQueue();

	EXPECT_EQ(q->size(), 0);

	delete q;
}

TEST(AQueueTest, Enqueue) {
	AQueue* q = new AQueue();

	for (int i = 0; i < 150; ++i) {
		q->enqueue(i);
	}

	EXPECT_EQ(q->size(), 150);
}

TEST(AQueueTest, Dequeue) {
	AQueue* q = new AQueue();

	for (int i = 1; i <= 15; ++i) {
		q->enqueue(i);
	}

	for (int i = 15; i <= 1; --i) {
		EXPECT_EQ(i, q->dequeue());
	}

	delete q;
}

TEST(AQueueTest, IsEmpty) {
	AQueue* q = new AQueue();

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
