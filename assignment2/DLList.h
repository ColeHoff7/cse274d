/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_

namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() { return n; }
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) { add(size(), x); }
	virtual T remove(int i);
	virtual void clear();
	bool IsPalindrome();
	void Rotate(int r);
	void Absorb(DLList* l2);
	DLList<T>* deal();
};

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}


template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
	n = 0;
}



template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}


template<class T>
T DLList<T>::get(int i) {
    return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}

template<class T>
bool DLList<T>::IsPalindrome(){
  Node* temp1 = dummy.next;//head
  Node* temp2 = dummy.prev;//tail
  for(int z = 0; z<n/2; z++){
	if(temp1->x != temp2->x){
	  return false;
	}
	temp1 = temp1->next;
	temp2 = temp2->prev;
  }
  return true;
}

template<class T>
void DLList<T>::Rotate(int r){
  r = r % n;
  if(r != 0){
    Node* p = getNode(r-1);//allowed to use getNode()? more efficient way?
    dummy.next->prev = dummy.prev;//make the head's previous point to the tail
    dummy.prev->next = dummy.next;//make the tail's next point to the head
    dummy.next = p->next;//inserts dummy into new spot
    dummy.prev = p;
    p->next = &dummy;//changes p's next to point to dummy
    dummy.next->prev = &dummy;//changes the dummy's next to point back to dummy
  }
}

template<class T>
void DLList<T>::Absorb(DLList<T>* l2){
  dummy.prev->next = l2->dummy.next; //tail1's next points to the second list's head
  l2->dummy.next->prev = dummy.prev; //the second list's head's previous points to tail1
  l2->dummy.prev->next = &dummy; //the second list's tail's next points to dummy
  dummy.prev = l2->dummy.prev; //dummy's previous now points to the second list's tail
  l2->dummy.prev = &l2->dummy; //makes second list's dummy point to itself
  l2->dummy.next = &l2->dummy;
  n += l2->n;
}

template<class T>
DLList<T>* DLList<T>::deal(){
  DLList<T>* x = new DLList();
  Node* current;
  Node* previous;
  previous = &x->dummy;
  current = dummy.next->next;//makes current index 1;
  for(int i = 1; i < n/2; i++){
	  previous->next = current;
	  current->prev->next = current->next;
	  current->next->prev = current->prev;
	  current->prev = previous;
	  previous = current;
	  current->next = &x->dummy;
	  x->dummy.prev = current;
	  current = previous->next->next;
  }


  /*Node* current;
  for(int i = 0; i < n/2; i++){
	if(i % 2 != 0){
	  current = getNode(i);
	  x->dummy.prev->next = current;//makes x's tail point to new node
	  current->prev->next = current->next;//patches the hole
	  current->next->prev = current->prev;//patches the hole
	  current->prev = x->dummy.prev;//new node's previous is now the old tail for x
	  x->dummy.prev = current;//dummy points to new tail
	  current->next = &dummy;
	}
  }
  */

  n = n - x->size();
  return x;

  //tried 2 different ways of doing it, neither worked for me. I have no idea why
}


} /* namespace ods */
#endif /* DLLIST_H_ */
