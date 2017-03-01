#include <iostream>
#include <string>
#include "singlyLinked.h"
#include "basicAccount.h"
using namespace std;

// Given DLink, add to the list incrementally.
void SinglyLinkedList::addB(){
	string name;
	float balance;
	long int ID;
	// User input
	cout << "Enter a name, balance and ID(in order)" << endl;
	cin >> name >> balance >> ID;

	// Create necessary objects
	basicAccount* info = new basicAccount(ID, name, balance);
	SLink* p = new SLink(info);

	SLink* curr = head;
	// If empty list
	if(curr == NULL){append(p); return 1;}
	else{
		while(curr){
			// If acctNum found in list
			if(curr->b.getAcctNum() == p->b.getAcctNum()){
				cout << "Error: Account Number Already in Use." << endl;
				delete link;
				delete info;
				return 0;
			}

			// IF at the head
			if(curr == head){
				// If the head is bigger than the insert node
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
					p->next = curr;
					setHead(p);
					return 1;
				}
			}

			// Reach the end of the list
			if(curr->next->next == NULL){
				if(curr->b.getAcctNum() > p->b.getAcctNum()){
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
	delete link;
	delete info;
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

void DoublyLinkedList::findB(long int id){
	cout << "Find " << id << "..." << endl;
	typedef std::shared_ptr<my_type_t> my_type_ptr;Link* curr = head;
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
				if(curr == head) setHead(curr->next);
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

void SinglyLinkedList::deleteB(long int id){
	cout << "Delete " << id << "..." << endl;
	DLink* curr = head;
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
				if(curr == head) setHead(curr->next);
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

void SinglyLinkedList::append(DLink *p) {
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

int SinglyLinkedList::getSize(){
	SLink* curr = head;
	int count = 0;
	while(curr){
		++count;
		curr = curr->next;
	}
	return count;
}

void SinglyLinkedList::print_all() {
	SLink* curr = head;
	if(head == NULL){ cout << "Empty List!" << endl; return; }
	while (curr) {
		cout << curr->value;
		if (curr = curr->next) cout << ", ";
	}
	cout << "\n";
}
