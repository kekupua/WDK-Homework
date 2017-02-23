#include <iostream>
#include <string>
#include "doublyLinked.h"
using namespace std;

// Given DLink, add to the list incrementally.
bool DoublyLinkedList::addB(DLink *p){
	DLink* curr = getHead();
	if(curr == NULL){append(p); return 1;}
	else{
		while(curr){
			// If acctNum found in list
			if(curr->b.getAcctNum() == p->b.getAcctNum()){
				cout << "Error: Account Number Already in Use." << endl;
				return 0;
			}

			// IF at the head
			if(curr == getHead()){
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
					curr->prev = p;
					p->next = curr;
					setHead(p);
					return 1;
				}
			}

			// Reach the end of the list
			if(curr->next == NULL){
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
					curr->prev->next = p;
					p->prev = curr->prev;
					curr->prev = p;
					p->next = curr;
				}
				else append(p);
				return 1;
			}

			// In the list
			if(curr->next->b.getAcctNum() > p->b.getAcctNum() && curr->b.getAcctNum() < p->b.getAcctNum()){
				curr->next->prev = p;
				p->next = curr->next;
				p->prev = curr;
				curr->next = p;
				return 1;
			}

			else
				curr = curr->next;
		}
	}
}

void DoublyLinkedList::findB(string name){
	cout << "Find " << name << "..." << endl;
  DLink* curr = getHead();
  // Traverse to S
  while(curr){
		if(curr->b.getName() == name){
			cout << endl << name << endl;
			cout << "=========" << endl;
			cout << "Account Number: " << curr->b.getAcctNum() << endl;
			cout << "Balance: " << curr->b.getBalance() << endl;
			return;
		}

		//If no other nodes
		else curr = curr->next;
  }
	cout << "Error: Not Found" << endl;
	return;
}

void DoublyLinkedList::findB(long int id){
	cout << "Find " << id << "..." << endl;
	DLink* curr = getHead();
	// Traverse to S
	while(curr){
		if(curr->b.getAcctNum() == id){
			cout << curr->b.getName() << endl;
			cout << "=========" << endl;
			cout << "Account Number: " << curr->b.getAcctNum() << endl;
			cout << "Balance: " << curr->b.getBalance() << endl;
			return;
		}

		//Waterfall
		else curr = curr->next;
	}
	cout << "Error: Not Found" << endl;
	return;
}

void DoublyLinkedList::deleteB(string name){
	cout << "Delete " << name << "..." << endl;
  DLink* curr = getHead();
  // Traverse to S
  while(curr){
		if(curr->b.getName() == name){
			// IF has prev and next
			if(curr->next && curr->prev){
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
			}
			else if(curr->prev){
				curr->prev->next = NULL;
				tail = curr->prev;
			}
			else if(curr->next){
				if(curr == getHead()) setHead(curr->next);
				curr->next->prev = NULL;
			}
			else{
				head = NULL;
			}
			delete curr;
			cout << "Deleted " << name << endl;
			return;
		}

		// Waterfall
		else curr = curr->next;
  }
	cout << "Error: Not Found" << endl;
	return;
}

void DoublyLinkedList::deleteB(long int id){
	cout << "Delete " << id << "..." << endl;
	DLink* curr = getHead();
	// Traverse to S
	while(curr){
		if(curr->b.getAcctNum() == id){
			// IF has prev and next
			if(curr->next && curr->prev){
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
			}
			else if(curr->prev){
				curr->prev->next = NULL;
			}
			else if(curr->next){
				if(curr == getHead()) setHead(curr->next);
				curr->next->prev = NULL;
			}
			else{
				head = NULL;
			}
			delete curr;
			cout << "Deleted " << id << endl;
			return;
		}

		// Waterfall
		else curr = curr->next;
	}
	cout << "Error: Not Found" << endl;
	return;
}

void DoublyLinkedList::append(DLink *p) {
	cout << "Append " << p->b.getName() << endl;
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
	cout << "Insert " << n->b.getName() << "..." << endl;
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
	cout << "Add " << n->b.getName() << "..." << endl;
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
	cout << "Deleting " << p->b.getName() << "..." << endl;
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
DLink* DoublyLinkedList::find(string s){
  cout << "Find " << s << "..." << endl;
  DLink* curr = this->getHead();

  // Traverse to S
  while(curr->b.getName() != s){
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
		cout << head->b.getName() << " (" << head->b.getAcctNum() << ")";
		if (head = head->next) cout << ", ";
	}
	cout << "\n";
}
