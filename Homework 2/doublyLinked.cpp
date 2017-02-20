#include <iostream>
#include "doublyLinked.h"
using namespace std;

void DoublyLinkedList::append(DLink *p) {
	cout << "Append " << p->value << endl; 
	if (head == NULL) {
		head = p;
		p->prev = NULL;
	}
	if (tail != NULL) {
		tail->next = p;
		p->prev = tail;
	}
	p->next = NULL;
	tail = p;
	return;
}

void DoublyLinkedList::insert(DLink* n, DLink *p) {  //insert n before p
	cout << "Insert " << n->value << "..." << endl;
 	// IF p doesn't exist
	if(p == NULL){
		append(n);
		return;
	}
	// IF there is a node before p
	if(p->prev){
		p->prev->next = n;
		n->prev = p->prev;
		n->next = p;
		p->prev = n;
	}
	// IF there is no node before p
	else{
		n->prev = NULL;
		n->next = p;
		p->prev = n;
	}
	return;
}

void DoublyLinkedList::add(DLink* p, DLink *n) {  //insert n after p
	cout << "Add " << n->value << "..." << endl;
	// IF p doesn't exist
	if(p == NULL){
		append(n);
		return;
	}

	// IF there is an element after p
	if(p->next){
		p->next->prev = n;
		n->next = p->next;
		n->prev = p;
		p->next = n;
	}

	// IF there is no node after p
	else{
		p->next = n;
		n->prev = p;
		n->next = NULL;
	}
}


void DoublyLinkedList::erase(DLink *p) {   //delete element p
	cout << "Deleting " << p->value << "..." << endl;
	DLink* curr = getHead();
	// IF empty list
	if(curr == NULL) return;

	// Search for the element
	while(curr){
		if(curr == p) {
			if(curr->prev) curr->prev->next = curr->next;
			if(curr->next) curr->next->prev = curr->prev;
			delete[] curr;
			cout << "Succesfully Deleted" << endl;
			return;
		}
		else curr = curr->next;
	}
	cout << "Error: Not Found" << endl;
	return;
}

// Find node
DLink* DoublyLinkedList::find(const int& s){
  cout << "Find " << s << "..." << endl;
  DLink* curr = this->getHead();

  // Traverse to S
  while(curr->value != s){
    //If no other nodes
    if(curr == NULL) return NULL;
    curr = curr->next;
  }
  return curr;
}

DLink* DoublyLinkedList::advance(int n){
  cout << "Advance " << n << "..." << endl;
  DLink* curr = this->getHead();

  // Traverse n
  for(int i = 0; i < n; ++i){
    curr = curr->next;
  }
  return curr;
}

void DoublyLinkedList::print_all(DLink* head) {
	while (head) {
		cout << head->value;
		if (head = head->next) cout << ", ";
	}
	cout << "\n";
}
