#include <iostream>
#include <fstream>
#include "tree.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Need exactly one filename!" << std::endl;
	} else {
		std::ifstream file;

		file.open(argv[1]);
		if (file.fail()) {
			std::cout << "File does not exist!" << std::endl;
			return 1;
		}

		Tree t;

		int in;
		while (true) {
			file >> in;
			if (file.fail()) {
				break;
			}

			t.insert(in);
		}

		t.printTree();
	}

	return 0;
}
