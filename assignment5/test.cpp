//============================================================================
// Name        : cse274-assingment5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTest.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include <stdlib.h>
#include <time.h>


using namespace std;
using namespace ods;

int main() {
	cout << "Starting..." << endl;

  DataStructureTester<BinarySearchTree<BSTNode1<int>,int> > test;
  //test.AddRandom(10);

  for (int i = 0; i < 50000; i++) {
  	int random = rand() % 100000 + 1;
    test.AddRandom(random);
  }

  DataStructureTester<RedBlackTree<RedBlackNode1<int>,int> > test2;
  //test2.AddRandom(10);
  for (int i = 0; i < 50000; i++) {
    int random = rand() % 100000 + 1;
    test2.AddRandom(random);
  }

  DataStructureTester<ChainedHashTable<int> > test3;
  for (int i = 0; i < 50000; i++) {
    int random = rand() % 100000 + 1;
    test3.AddRandom(random);
  }

  DataStructureTester<LinearHashTable<int> > test4;
  for (int i = 0; i < 50000; i++) {
    int random = rand() % 100000 + 1;
    test4.AddRandom(random);
  }

  cout << "Finished Assigning Randoms..." << endl;
  cout << "___________________________________" << endl;
  cout << "Beginning Tests..." << endl;
  cout << endl;
  cout << "Binary Search Tree Test:" << endl;
  long binary[6][20];
  for(int n = 0; n < 20; n++){
  	binary[0][n] = test.doSequentialAdd(1, 50000, 1);
  	binary[4][n] = test.doSequentialFind(1, 50000, 1);
  	binary[2][n] = test.doSequentialRemove(1, 50000, 1);
  	binary[1][n] = test.doRandomAdd(50000);
  	binary[5][n] = test.doRandomFind(50000);
  	binary[3][n] = test.doRandomRemove(50000);
  }
  long avgSA = 0;
  int avgRA = 0;
  int avgSR = 0;
  int avgRR = 0;
  long avgSF = 0;
  int avgRF = 0;

  for(int x = 0; x < 20; x++){
 		avgSA += binary[0][x];
 	}
  avgSA = avgSA / 20;
  for(int x = 0; x < 20; x++){
  	avgRA += binary[1][x];
  }
  avgRA = avgRA / 20;
  for(int x = 0; x < 20; x++){
  	avgSR += binary[2][x];
  }
  avgSR = avgSR / 20;
  for(int x = 0; x < 20; x++){
    avgRR += binary[3][x];
 	}
  avgRR = avgRR / 20;
  for(int x = 0; x < 20; x++){
    avgSF += binary[4][x];
  }
  avgSF = avgSF / 20;
  for(int x = 0; x < 20; x++){
    avgRF += binary[5][x];
  }
  avgRF = avgRF / 20;

  cout << "    Average Time for Binary Search Tree Sequential Adding: " << avgSA << endl;
  cout << "    Average Time for Binary Search Tree Random Adding: " << avgRA << endl;
  cout << "    Average Time for Binary Search Tree Sequential Removing: " << avgSR << endl;
  cout << "    Average Time for Binary Search Tree Random Removing: " << avgRR << endl;
  cout << "    Average Time for Binary Search Tree Sequential Finding: " << avgSF << endl;
  cout << "    Average Time for Binary Search Tree Random Finding: " << avgRF << endl;
  cout << "__________________________________________" << endl;
  cout << endl;


  cout << endl;
    cout << "Red Black Tree Test:" << endl;
    int r[6][20];
    for(int n = 0; n < 20; n++){
    	r[0][n] = test2.doSequentialAdd(1, 50000, 1);
    	r[4][n] = test2.doSequentialFind(1, 50000, 1);
    	r[2][n] = test2.doSequentialRemove(1, 50000, 1);
    	r[1][n] = test2.doRandomAdd(50000);
    	r[5][n] = test2.doRandomFind(50000);
    	r[3][n] = test2.doRandomRemove(50000);
    }
    avgSA = 0;
    avgRA = 0;
    avgSR = 0;
    avgRR = 0;
    avgSF = 0;
    avgRF = 0;

    for(int x = 0; x < 20; x++){
   		avgSA += r[0][x];
   	}
    avgSA = avgSA / 20;
    for(int x = 0; x < 20; x++){
    	avgRA += r[1][x];
    }
    avgRA = avgRA / 20;
    for(int x = 0; x < 20; x++){
    	avgSR += r[2][x];
    }
    avgSR = avgSR / 20;
    for(int x = 0; x < 20; x++){
      avgRR += r[3][x];
   	}
    avgRR = avgRR / 20;
    for(int x = 0; x < 20; x++){
      avgSF += r[4][x];
    }
    avgSF = avgSF / 20;
    for(int x = 0; x < 20; x++){
      avgRF += r[5][x];
    }
    avgRF = avgRF / 20;

    cout << "    Average Time for Red Black Tree Sequential Adding: " << avgSA << endl;
    cout << "    Average Time for Red Black Tree Random Adding: " << avgRA << endl;
    cout << "    Average Time for Red Black Tree Sequential Removing: " << avgSR << endl;
    cout << "    Average Time for Red Black Tree Random Removing: " << avgRR << endl;
    cout << "    Average Time for Red Black Tree Sequential Finding: " << avgSF << endl;
    cout << "    Average Time for Red Black Tree Random Finding: " << avgRF << endl;
    cout << "__________________________________________" << endl;
    cout << endl;

    cout << endl;
      cout << "Chained Hash Table Test:" << endl;
      int c[6][20];
      for(int n = 0; n < 20; n++){
      	c[0][n] = test3.doSequentialAdd(1, 50000, 1);
      	c[4][n] = test3.doSequentialFind(1, 50000, 1);
      	c[2][n] = test3.doSequentialRemove(1, 50000, 1);
      	c[1][n] = test3.doRandomAdd(50000);
      	c[5][n] = test3.doRandomFind(50000);
      	c[3][n] = test3.doRandomRemove(50000);
      }
      avgSA = 0;
      avgRA = 0;
      avgSR = 0;
      avgRR = 0;
      avgSF = 0;
      avgRF = 0;

      for(int x = 0; x < 20; x++){
     		avgSA += c[0][x];
     	}
      avgSA = avgSA / 20;
      for(int x = 0; x < 20; x++){
      	avgRA += c[1][x];
      }
      avgRA = avgRA / 20;
      for(int x = 0; x < 20; x++){
      	avgSR += c[2][x];
      }
      avgSR = avgSR / 20;
      for(int x = 0; x < 20; x++){
        avgRR += c[3][x];
     	}
      avgRR = avgRR / 20;
      for(int x = 0; x < 20; x++){
        avgSF += c[4][x];
      }
      avgSF = avgSF / 20;
      for(int x = 0; x < 20; x++){
        avgRF += c[5][x];
      }
      avgRF = avgRF / 20;

      cout << "    Average Time for Chained Hash Table Sequential Adding: " << avgSA << endl;
      cout << "    Average Time for Chained Hash Table Random Adding: " << avgRA << endl;
      cout << "    Average Time for Chained Hash Table Sequential Removing: " << avgSR << endl;
      cout << "    Average Time for Chained Hash Table Random Removing: " << avgRR << endl;
      cout << "    Average Time for Chained Hash Table Sequential Finding: " << avgSF << endl;
      cout << "    Average Time for Chained Hash Table Random Finding: " << avgRF << endl;
      cout << "__________________________________________" << endl;
      cout << endl;

      cout << endl;
      cout << "Linear Hash Table Test:" << endl;
      int l[6][20];
      for(int n = 0; n < 20; n++){
      	l[0][n] = test4.doSequentialAdd(1, 50000, 1);
      	l[4][n] = test4.doSequentialFind(1, 50000, 1);
      	l[2][n] = test4.doSequentialRemove(1, 50000, 1);
      	l[1][n] = test4.doRandomAdd(50000);
      	l[5][n] = test4.doRandomFind(50000);
      	l[3][n] = test4.doRandomRemove(50000);
      }
      avgSA = 0;
      avgRA = 0;
      avgSR = 0;
      avgRR = 0;
      avgSF = 0;
      avgRF = 0;

      for(int x = 0; x < 20; x++){
        avgSA += l[0][x];
     	}
      avgSA = avgSA / 20;
      for(int x = 0; x < 20; x++){
        avgRA += l[1][x];
      }
      avgRA = avgRA / 20;
      for(int x = 0; x < 20; x++){
        avgSR += l[2][x];
      }
      avgSR = avgSR / 20;
      for(int x = 0; x < 20; x++){
        avgRR += l[3][x];
      }
      avgRR = avgRR / 20;
      for(int x = 0; x < 20; x++){
        avgSF += l[4][x];
      }
      avgSF = avgSF / 20;
      for(int x = 0; x < 20; x++){
        avgRF += l[5][x];
      }
      avgRF = avgRF / 20;

      cout << "    Average Time for Linear Hash Table Sequential Adding: " << avgSA << endl;
      cout << "    Average Time for Linear Hash Table Random Adding: " << avgRA << endl;
      cout << "    Average Time for Linear Hash Table Sequential Removing: " << avgSR << endl;
      cout << "    Average Time for Linear Hash Table Random Removing: " << avgRR << endl;
      cout << "    Average Time for Linear Hash Table Sequential Finding: " << avgSF << endl;
      cout << "    Average Time for Linear Hash Table Random Finding: " << avgRF << endl;
      cout << "__________________________________________" << endl;
      cout << endl;
	return 0;
}
