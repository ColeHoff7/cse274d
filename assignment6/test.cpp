//============================================================================
// Name        : cse274-assignment6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryHeap.h"
#include <time.h>
#include "ArrayStack.h"
using namespace std;
using namespace ods;
int main() {
	srand(time(NULL));
	BinaryHeap<int> heap;
	ArrayStack<int> randList;

	for(int i = 0; i <= 1000; i++){
		int rando = rand() % 10000 + 1;
		randList.add(rando);
	}
	for(int i = 0; i < 1000; i++){
		heap.add(randList.get(i));
		if(heap.checkHeap()){
		  //cout << "Heap Conditions Met..." << endl;
		}
		else{
		  cout << "Heap Conditions NOT Met!" << endl;
		  cout << randList.get(i) << endl;
		  cout << i;
		  return 0;
		}
	}

	int n = 1000;
  for(int i = 0; i <= 100; i++){
  	int rando = rand() % n + 1;
  	heap.remove(rando);

  	if(heap.checkHeap()){
  		cout << "Heap Conditions Met..." << endl;
  	}
  	else{
  		cout << "Heap Conditions NOT Met!" << endl;
  		return 0;
  	}
  	n--;
  }
  cout << "Heap Conditions Were Met On All Removes. Great Success!" << endl;
	return 0;
}
