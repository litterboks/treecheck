#include "tree.h"
#include <algorithm>

Node::Node(int value)
{
	this->value = value;
}

void deleteNodes(Node* node){
	if (node!=NULL){
	deleteNodes(node->left);
	deleteNodes(node->right);
	delete node;
	}
}

Tree::~Tree() {
	deleteNodes(root);
}

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

int Tree::printBalance(Node* node)
{
	if (node == NULL) {
		return 0;
	} else {
		int depthRight = printBalance(node->right);
		int depthLeft = printBalance(node->left);

		int bal = depthRight - depthLeft;
		std::cout << "bal (" << node->value << ") = " << bal;

		if (!(-1 <= bal && bal <= 1)) {
			std::cout << " (AVL Violation)";
			AVLflag = false;
		}

		std::cout << std::endl;
		return 1 + std::max(depthLeft, depthRight);
	}
}

int Tree::getMin(Node* node) const
{
	if (node->left == NULL) {
		return node->value;
	} else {
		return getMin(node->left);
	}
}

int Tree::getMax(Node* node) const
{
	if (node->right == NULL) {
		return node->value;
	} else {
		return getMax(node->right);
	}
}

int Tree::sumValues(Node* node, int &count) const
{
	int sum = 0;

	if (node->left != NULL) {
		sum += sumValues(node->left, count);
	}
	if (node->right != NULL) {
		sum += sumValues(node->right, count);
	}

	count++;
	return sum + node->value;
}

double Tree::getAverage(Node* node) const
{
	int sum = 0;
	int count = 0;
	sum = sumValues(root, count);
	return (double)sum / count;
}

void Tree::printTree()
{
	if (root == NULL) {
		std::cout << "Nothing has been inserted!" << std::endl;
	} else {
		printBalance(root);

		std::cout << "AVL: ";
		if (AVLflag) {
			std::cout << "yes";
		} else {
			std::cout << "no";
		}
		std::cout << std::endl;

		std::cout << "min: " << getMin(root);
		std::cout << ", max: " << getMax(root);
		std::cout << ", avg: " << getAverage(root) << std::endl;
	}
}

bool Tree::isAVL()
{
	return AVLflag;
}


