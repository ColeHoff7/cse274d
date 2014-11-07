//============================================================================
// Name        : cse274-assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>

#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace ods;


void testPart1(BinarySearchTree<BSTNode1<int>, int> *tree) {
	cout << "Testing Part 1..." << endl;
		cout << "______________________________" << endl;
	cout << "Original Height Function: " << tree->height() << endl;
	cout << "New Height Function: " << tree->height2() << endl;
}

void testPart2(BinarySearchTree<BSTNode1<int>, int> *tree) {
	cout << "Testing Part 2..." << endl;
		cout << "______________________________" << endl;
	if(tree->isBalanced() == 1) cout << "Tree is Balanced" << endl;
	else cout << "Tree is not Balanced" << endl;
}

void testPart3(BinarySearchTree<BSTNode1<int>, int> *tree) {
	cout << "Testing Part 3..." << endl;
	cout << "______________________________" << endl;
	tree->preOrder();
	tree->postOrder();
	tree->inOrder();
	void *u = tree->getNode(4);
	cout << "Orders assigned" << endl;
	cout << "Node with value of 4 is at memory address: " << u << endl;
}

void testPart4(BinarySearchTree<BSTNode1<int>, int> *tree) {
	cout << "Testing Part 4..." << endl;
	cout << "______________________________" << endl;
	DLList<int> list = tree->getLE(10);
	cout << "All items in tree less than 10: ";
	for(int n = 1; n < list.size(); n++){
		cout << list.get(n) << ", ";
	}
	cout << endl;
}

int main() {
	 BinarySearchTree<BSTNode1<int>, int>* tree = new BinarySearchTree<BSTNode1<int>, int>();
  tree->add(10);
  tree->add(12);
  tree->add(3);
  tree->add(9);
  tree->add(7);
  tree->add(2);
  tree->add(43);
  tree->add(4);
  tree->add(29);
  tree->add(37);

  testPart1(tree);
  cout << endl;

  BinarySearchTree<BSTNode1<int>, int>* tree2 = new BinarySearchTree<BSTNode1<int>, int>();
  tree2->add(5);
  tree2->add(4);
  tree2->add(6);
  tree2->add(10);
  tree2->add(11);

  testPart2(tree2);
  cout << endl;

  BinarySearchTree<BSTNode1<int>, int>* tree3 = new BinarySearchTree<BSTNode1<int>, int>();
  tree3->add(5);
  tree3->add(4);
  tree3->add(6);

  testPart2(tree2);
  cout << endl;

  BinarySearchTree<BSTNode1<int>, int>* tree4 = new BinarySearchTree<BSTNode1<int>, int>();
  tree4->add(5);
  tree4->add(12);
  tree4->add(3);
  tree4->add(4);
  tree4->add(9);
  tree4->add(7);
  tree4->add(2);
  tree4->add(13);

  testPart3(tree4);
  cout << endl;

  BinarySearchTree<BSTNode1<int>, int>* tree5 = new BinarySearchTree<BSTNode1<int>, int>();
  tree5->add(10);
  tree5->add(11);
  tree5->add(13);
  tree5->add(9);
  tree5->add(6);
  tree5->add(2);
  tree5->add(3);

  testPart4(tree5);

  delete tree;
  delete tree2;
  delete tree3;
  delete tree5;
  delete tree4;

  return 0;
}
