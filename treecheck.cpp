#include <iostream>
#include "tree.h"

int main()
{
	Tree t;
	//TODO: read from file instead

	int in;
	while (true) {
		std::cin >> in;
		if (std::cin.fail()) {
			break;
		}

		t.insert(in);
	}

	t.printTree();

	return 0;
}
