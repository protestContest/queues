#ifndef __NODE_H__
#define __NODE_H__

class Node {
private:
	int value;
	Node* next;
	void deleteChain(Node*);

public:
	Node(int);
	~Node();
	int getValue();
	bool hasNext();
	Node* getNext();
	void setNext(Node*);

};

#endif
