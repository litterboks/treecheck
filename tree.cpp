#include "tree.h"
#include <algorithm>

Node::Node(int value)
{
	this->value = value;
}

Tree::Tree() {}
Tree::~Tree() {}

Node* Tree::insertInner(int value, Node* node)
{
	if (node == NULL) {
		node = new Node(value);
	} else if (value < node->value) {
		node->left = insertInner(value, node->left);
	} else if (value > node->value) {
		node->right = insertInner(value, node->right);
	} else {
		std::cout << "Value " << value << " does already exist!" << std::endl;
	}
	return node;
}

void Tree::insert(int value)
{
	root = insertInner(value, root);
}

int Tree::printBalance(Node* node) const
{
	if (node == NULL) {
		return 0;
	} else {
		int depthRight = printBalance(node->right);
		int depthLeft = printBalance(node->left);
		int bal = depthRight - depthLeft;
		std::cout << "bal (" << node->value << ") = " << bal << std::endl;
		return 1 + std::max(depthLeft, depthRight);
	}
}

int getMin(Node* node)
{
	if (node->left == NULL) {
		return node->value;
	} else {
		return getMin(node->left);
	}
}

int getMax(Node* node)
{
	if (node->right == NULL) {
		return node->value;
	} else {
		return getMax(node->right);
	}
}

double getAverage(Node* nod)
{
	return 100;
}

void Tree::printTree() const
{
	if (root == NULL) {
		std::cout << "Nothing has been inserted!" << std::endl;
	} else {
		printBalance(root);
		//printIsAvl
		std::cout << "min: " << getMin(root);
		std::cout << ", max: " << getMax(root);
		std::cout << ", avg: " << getAverage(root) << std::endl;
	}
}

