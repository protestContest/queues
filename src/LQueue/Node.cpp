#include "Node.h"

Node::Node(int i) {
	value = i;
	next = 0;
}

Node::~Node() {
	if (next != 0) {
		deleteChain(next);
		delete next;
	}
}

void Node::deleteChain(Node* n) {
	if (n->next != 0) {
		deleteChain(n->next);
		delete n->next;
	}

	return;
}

int Node::getValue() {
	return value;
}

bool Node::hasNext() {
	return next != 0;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* n) {
	next = n;
}
