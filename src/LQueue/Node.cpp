#include "LQueue.h"

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
