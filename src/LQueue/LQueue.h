#ifndef __LQUEUE_H__
#define __LQUEUE_H__

class LQueue {
private:
	
public:
	LQueue();
	~LQueue();
	bool isEmpty();
	int size();
	void enqueue(int);
	int dequeue();
};

#endif
