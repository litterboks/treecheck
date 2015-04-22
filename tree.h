#include <iostream>

class Node
{
public:
	Node(int number);
	~Node();
	
	void insertNode(int number);
	int getNumber() const;

private:
	int number;
	Node* left = NULL;
	Node* right = NULL;
};

class Tree
{
public:
	Tree();
	~Tree();

	void printTree() const;
	void insertTree(int number);

private:
	Node* root = NULL;
};

