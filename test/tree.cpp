#include "upp11.h"
#include "../tree.h"
#include <iostream>

void insertMedian(bool low, int upper, int lower, Tree &MedianTree)
{
	int med = (upper - lower) / 2 + lower;
	if (med != upper && med != lower) {
		MedianTree.insert(med);
		if (low) {
			insertMedian(!low, med, lower, MedianTree);
			insertMedian(!low, upper, med, MedianTree);
		}	else {
			insertMedian(!low, upper, med, MedianTree);
			insertMedian(!low, med, lower, MedianTree);
		}
	}
}

bool checkAVL(Tree &TestTree)
{
	std::cout.setstate(std::ios::failbit) ;
	TestTree.printTree();
	std::cout.clear() ;
	return TestTree.isAVL();
}

UP_TEST(AlternatingBigSmall)
{
	Tree TestTree1;
	for (int i = 0; i < 1000 ; i++) {
		TestTree1.insert(1001 + i);
		TestTree1.insert(1000 - i);
	}
	UP_ASSERT(!checkAVL(TestTree1));
}

UP_TEST(Insert20000)
{
	Tree TestTree2;
	for (int i = 0; i < 20000 ; i++) {
		TestTree2.insert(i);
	}
	UP_ASSERT(!checkAVL(TestTree2));
}

UP_TEST(InsertMedian)
{
	Tree TestTree3;
	insertMedian(true, 20, 0, TestTree3);
	UP_ASSERT(checkAVL(TestTree3));
}

