//============================================================================
// Name        : cse274-assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DLList.h"

using namespace std;
using namespace ods;
int main() {

  //testing palindrome
  DLList<int> x;
  x.add(1);
  x.add(2);
  x.add(2);
  x.add(1);
  cout << "Is Palindrome? " << x.IsPalindrome() << endl;
  x.add(5);
  cout << "Is Palindrome? " << x.IsPalindrome() << endl;
  cout << endl;


  //testing rotate
  DLList<int> y;
  y.add(1);
  y.add(2);
  y.add(3);
  y.add(4);
  cout << "Before Rotate: ";
  for(int n = 0; n < y.size(); n++){
    cout << y.get(n) << ", ";
  }
  cout << endl;
  y.Rotate(2);
  cout << "After Rotate: ";
  for(int n = 0; n < y.size(); n++){
    cout << y.get(n) << ", ";
  }
  cout << endl;
  cout << endl;


  //testing absorb
  DLList<int>* a = new DLList<int>();
  a->add(1);
  a->add(2);
  a->add(3);
  DLList<int>* b = new DLList<int>();
  b->add(4);
  b->add(5);
  b->add(6);
  a->Absorb(b);
  cout << "After Absorb: ";
  for(int n = 0; n < a->size(); n++){
    cout << a->get(n) << ", ";
  }
  cout << endl;
  cout << endl;
  delete a;
  delete b;


  //testing deal
  DLList<int>* s = new DLList<int>();
  s->add(1);
  s->add(2);
  s->add(3);
  s->add(4);
  s->add(5);
  s->add(6);
  s->add(7);
  DLList<int>* t = new DLList<int>();
  t = s->deal();
  cout << "S: ";
  for(int n = 0; n < s->size(); n++){
      cout << s->get(n) << ", ";
  }
  cout << endl;
  cout << "T: ";
  for(int n = 0; n < t->size(); n++){
        cout << t->get(n) << ", ";
  }
  cout << endl;
  delete s;
  delete t;

  //I commented this out because I couldn't get deal to work
}
