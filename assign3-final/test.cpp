//============================================================================
// Name        : cse274-assignment3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace ods;

int main() {
	srand(time(NULL));
	ChainedHashTable<int> hash;
	hash.SetLoadFactor(8);
	for(int i = 0; i<= 1000; i++){
		int random = rand() % 10000 + 1;
		hash.add(random);
	}
  cout << "Length: " << hash.getLength() << endl;
  cout << "Average List Size: " << hash.getAverageList() << endl;
	cout << "Longest List: " << hash.GetLongestList() << endl;
	cout << endl;
	cout << endl;

	hash.clear();
	hash.SetLoadFactor(2);
	hash.add(5);
	hash.add(6);
	hash.add(1);
	hash.add(46);
	hash.add(73);
	hash.add(32);
	hash.add(21);
	hash.remove(1);
	hash.remove(5);
	cout << "finding 32: " << hash.find(32) << endl;
	cout << "finding 73: " << hash.find(73) << endl;
	cout << "Size: " << hash.size() << endl;
	cout << endl;
	cout << endl;

	cout << "Linear Hashing..." << endl;

	LinearHashTable<int>* lin = new LinearHashTable<int>(-1,-2);
	for(int i = 0; i<= 1000; i++){
			int rando = rand() % 10000 + 1;
			lin->add(rando);
	}

	cout << "Size: " << lin->size() << endl;

	lin->clear();
	lin->add(4);
	lin->add(11);
	lin->add(1);
	lin->add(3);
	lin->add(9);
	lin->remove(1);
	lin->remove(9);
	cout << "finding: " << lin->find(4) << endl;
  cout << "size: " << lin->size() << endl;

	delete lin;
	return 0;
}
