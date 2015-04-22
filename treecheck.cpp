#include <iostream>
#include "tree.h"

int main()
{
	Tree t;

	int in;
	while (true) {
		std::cin >> in;
		if(std::cin.fail()) {
			break;
		}
		
		t.insertTree(in);
	}

	t.printTree();

	return 0;
}
