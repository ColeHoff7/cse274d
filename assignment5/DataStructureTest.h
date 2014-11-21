/*
 * DataStructureTest.h
 *
 *  Created on: Nov 19, 2014
 *      Author: Cole
 */

#ifndef DATASTRUCTURETEST_H_
#define DATASTRUCTURETEST_H_

#include "ArrayStack.h"
#include <time.h>


namespace ods{
template<class T>
class DataStructureTester{
protected:
	ArrayStack<int> randList;
	T list;

public:
	long doSequentialAdd(int start, int end, int step);
	int doRandomAdd(int n);
	int doSequentialRemove(int start, int end, int step);
	int doRandomRemove(int n);
	long doSequentialFind(int start, int end, int step);
	int doRandomFind(int n);
	void AddRandom(int i) {
	  randList.add(i);
	  //std::cout << "find " << list.find(i) << std::endl;
	}
};

template<class T>
long DataStructureTester<T>::doSequentialAdd(int start, int end, int step) {
	clock_t t;
	t = clock();
	for(int n = start; n <= end; n += step){
		list.add(n);
	}
	return (long)(clock() - t) * 1000;
}

template<class T>
int DataStructureTester<T>::doRandomAdd(int n) {
	clock_t t;
	t = clock();
	for(int i = 0; i < n; i++){
		list.add(randList.get(i));
	}
	return (int)(clock() - t) * 1000;
}

template<class T>
int DataStructureTester<T>::doSequentialRemove(int start, int end, int step) {
	clock_t t;
	t = clock();
	for(int n = start; n <= end; n += step){
			list.remove(n);
	}
	return (int)(clock() - t) * 1000;
}

template<class T>
int DataStructureTester<T>::doRandomRemove(int n) {
	clock_t t;
	t = clock();
	for(int i = 0; i < n; i++){
		list.remove(randList.get(i));
	}
	return (int)(clock() - t) * 1000;
}

template<class T>
long DataStructureTester<T>::doSequentialFind(int start, int end, int step) {
	clock_t t;
	t = clock();
	for(int n = start; n <= end; n += step){
		list.find(n);
	}
	return (long)(clock() - t) * 1000;
}

template<class T>
int DataStructureTester<T>::doRandomFind(int n) {
	clock_t t;
	t = clock();
	for(int i = 0; i < n; i++){
		list.find(randList.get(i));
	}
	return (int)(clock() - t) * 1000;
}

}


#endif /* DATASTRUCTURETEST_H_ */
