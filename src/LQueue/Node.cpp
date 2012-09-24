#include "Node.h"

Node::Node(int i) {
	value = i;
	next = 0;
}

Node::~Node() {

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
