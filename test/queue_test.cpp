#include "gtest/gtest.h"
#include "AQueue/AQueue.h"
#include "LQueue/LQueue.h"
#include "VQueue/VQueue.h"

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

TEST(LQueueTest, Constructor) {
	LQueue* q = new LQueue();

	EXPECT_EQ(q->size(), 0);

	delete q;
}

TEST(LQueueTest, Enqueue) {
	LQueue* q = new LQueue();

	for (int i = 0; i < 150; ++i) {
		q->enqueue(i);
	}

	EXPECT_EQ(q->size(), 150);
}

TEST(LQueueTest, Dequeue) {
	LQueue* q = new LQueue();

	for (int i = 1; i <= 15; ++i) {
		q->enqueue(i);
	}

	for (int i = 15; i <= 1; --i) {
		EXPECT_EQ(i, q->dequeue());
	}

	delete q;
}

TEST(LQueueTest, IsEmpty) {
	LQueue* q = new LQueue();

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
/*
TEST(VQueueTest, Constructor) {
	VQueue* q = new VQueue();

	EXPECT_EQ(q->size(), 0);

	delete q;
}

TEST(VQueueTest, Enqueue) {
	VQueue* q = new VQueue();

	for (int i = 0; i < 150; ++i) {
		q->enqueue(i);
	}

	EXPECT_EQ(q->size(), 150);
}

TEST(VQueueTest, Dequeue) {
	VQueue* q = new VQueue();

	for (int i = 1; i <= 15; ++i) {
		q->enqueue(i);
	}

	for (int i = 15; i <= 1; --i) {
		EXPECT_EQ(i, q->dequeue());
	}

	delete q;
}

TEST(VQueueTest, IsEmpty) {
	VQueue* q = new VQueue();

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
*/
