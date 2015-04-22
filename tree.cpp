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

void Tree::printTree() const
{
	printBalance(root);
}

