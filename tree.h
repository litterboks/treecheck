#include <iostream>

class Node
{
public:
	Node(int value);

	int value;
	Node* left = NULL;
	Node* right = NULL;
};

class Tree
{
public:
	~Tree();

	void printTree();
	void insert(int value);

private:
	bool AVLflag = false;
	Node* insertInner(int value, Node* node);
	Node* root = NULL;
	int printBalance(Node* node);
	int sumValues(Node* node, int &count) const;
	int getMin(Node* node) const;
	int getMax(Node* node) const;
	double getAverage(Node* node) const;
};
