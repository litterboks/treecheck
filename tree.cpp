#include "tree.h"

Node::Node(int number)
{
	this->number = number;
}

Node::~Node(){}

int Node::getNumber() const
{
	return number;
}

Tree::Tree() {}
Tree::~Tree() {}

void Node::insertNode(int number)
{
	if (number < this->number) {
		if (left != NULL) {
			left->insertNode(number);
		} else {
			*left = Node(number);
		}
	} else if (number > this->number) {
		if (right != NULL) {
			right->insertNode(number);
		} else {
			*right = Node(number);
		}
	}
}

void Tree::insertTree(int number)
{
	if (root == NULL) {
		*root = Node(number);
	} else {
		root->insertNode(number);
	}
}

void Tree::printTree() const{

}
