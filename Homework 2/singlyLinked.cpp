#include <iostream>
#include <string>
#include "singlyLinked.h"
#include "basicAccount.h"
using namespace std;

// Given DLink, add to the list incrementally.
bool SinglyLinkedList::addB(SLink* p){
	SLink* curr = head;
	// If empty list
	if(curr == NULL){append(p); return 1;}
	else{
		while(curr){
			// If acctNum found in list
			if(curr->b.getAcctNum() == p->b.getAcctNum()){
				cout << "Error: Account Number Already in Use." << endl;
				return 0;
			}

			// IF at the head
			if(curr == head){
				// If the head is bigger than the insert node
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
					p->next = curr;
					head = p;
					return 1;
				}
			}
			// Reach the end of the list
			if(curr->next == NULL){
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
					p->next = curr->next;
					curr->next = p;
				}
				else append(p);
				return 1;
			}

			// If the final at 1 before the final node
			if(curr->next->next == NULL){
				if(curr->next->b.getAcctNum() > p->b.getAcctNum()){
					p->next = curr->next;
					curr->next = p;
				}
				else append(p);
				return 1;
			}

			// In the list
			if(curr->next->b.getAcctNum() > p->b.getAcctNum() && curr->b.getAcctNum() < p->b.getAcctNum()){
				p->next = curr->next;
				curr->next = p;
				return 1;
			}

			else
				curr = curr->next;
		}
	}
	return 0;
}

void SinglyLinkedList::findB(string name){
	cout << "Find " << name << "..." << endl;
  SLink* curr = head;
  // Traverse to S
  while(curr){
		if(curr->b.getName() == name){
			cout << endl << name << endl;
			cout << "=========" << endl;
			cout << "Account Number: " << curr->b.getAcctNum() << endl;
			cout << "Balance: " << curr->b.getBalance() << endl;
			return;
		}

		//If no match
		else curr = curr->next;
  }
	cout << "Error: Not Found" << endl;
	return;
}

void SinglyLinkedList::findB(long int id){
	cout << "Find " << id << "..." << endl;
	SLink* curr = head;
	// Traverse to S
	while(curr){
		if(curr->b.getAcctNum() == id){
			cout << endl << curr->b.getName() << endl;
			cout << "=========" << endl;
			cout << "Account Number: " << curr->b.getAcctNum() << endl;
			cout << "Balance: " << curr->b.getBalance() << endl;
			return;
		}

		// If no match
		else curr = curr->next;
	}
	cout << "Error: Not Found" << endl;
	return;
}

void SinglyLinkedList::deleteB(string name){
	cout << "Delete " << name << "..." << endl;
  SLink* curr = head;
	// If empty
	if(curr == NULL){
		cout << "Empty List!" << endl;
		return;
	}

	// IF first node is match
	if(curr->b.getName() == name){
		setHead(curr->next);
		delete curr;
		cout << "Deleted " << name << endl;
		return;
	}

  // Traverse to name
  while(curr){
		// If the next node is a match
		if(curr->next->b.getName() == name){
			// Within list
			if(curr->next->next){
				curr->next = curr->next->next;
			}
			// At one before end
			else {
				curr->next = NULL;
			}
			delete curr->next;
			cout << "Deleted " << name << endl;
			return;
		}

		// Waterfall
		else curr = curr->next;
  }
	cout << "Error: Not Found" << endl;
	return;
}

void SinglyLinkedList::deleteB(long int id){
	cout << "Delete " << id << "..." << endl;
  SLink* curr = head;
	// If empty
	if(curr == NULL){
		cout << "Empty List!" << endl;
		return;
	}

	// IF first node is match
	if(curr->b.getAcctNum() == id){
		setHead(curr->next);
		delete curr;
		cout << "Deleted " << id << endl;
		return;
	}

  // Traverse to name
  while(curr){
		// If the next node is a match
		if(curr->next->b.getAcctNum() == id){
			// Within list
			if(curr->next->next){
				curr->next = curr->next->next;
			}
			// At one before end
			else {
				curr->next = NULL;
			}
			delete curr->next;
			cout << "Deleted " << id << endl;
			return;
		}

		// Waterfall
		else curr = curr->next;
  }
	cout << "Error: Not Found" << endl;
	return;
}

// Append the node p
void SinglyLinkedList::append(SLink *p) {
	cout << "Append " << p->b.getName() << endl;
	if (head == NULL) {
		head = p;
	}
	if (tail != NULL) {
		tail->next = p;
	}
	p->next = NULL;
	tail = p;
	return;
}

// Prints all nodes with acctNum
void SinglyLinkedList::print_all() {
	SLink* curr = head;
	if(head == NULL){ cout << "Empty List!" << endl; return; }
	while (curr) {
		cout << curr->b.getName() << " (" << curr->b.getAcctNum() << ")";
		if (curr = curr->next) cout << ", ";
	}
	cout << "\n";
}
