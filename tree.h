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
	Tree();
	~Tree();

	void printTree() const;
	void insert(int value);

private:
	Node* insertInner(int value, Node* node);
	Node* root = NULL;
	int printBalance(Node* node) const; 
};

