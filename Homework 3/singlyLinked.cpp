#include "singlyLinked.h"
using namespace std;

// Given SLink, add to the list incrementally.
void SinglyLinkedList::addS(SLink* p){
	SLink* curr = head;
	// If empty list
	if(curr == NULL){append(p); return;}
	else{
		while(curr){
			// IF at the head
			if(curr == head){
				// If the head is bigger than the insert node
				if(curr->a.executeTime > p->a.executeTime){
					p->next = curr;
					head = p;
					return;
				}
			}
			// Reach the end of the list
			if(curr->next == NULL){
				if(curr->a.executeTime > p->a.executeTime){
					p->next = curr->next;
					curr->next = p;
				}
				else append(p);
				return;
			}
			// If the at 1 before the final node
			if(curr->next->next == NULL){
				if(curr->next->a.executeTime >= p->a.executeTime){
					p->next = curr->next;
					curr->next = p;
				}
				else append(p);
				return;
			}
			// Insert between two nodes
			if(curr->next->a.executeTime > p->a.executeTime && curr->a.executeTime < p->a.executeTime){
				p->next = curr->next;
				curr->next = p;
				return;
			}
			curr = curr->next;
		}
	}
	return;
}

// Append p to the end of the list
void SinglyLinkedList::append(SLink *p) {
	//cout << "Append Type: " << p->a.type << endl;
	if (head == NULL) {
		head = p;
	}
	SLink* curr = head;
	while(curr->next)
		curr = curr->next;
	curr->next = p;
	tail = p;
	p->next = NULL;
	return;
}

// Insert n before p
void SinglyLinkedList::insert(SLink* n, SLink *p) {  //insert n before p
	cout << "Insert " << n->value << endl;
	SLink* curr = this->getHead();
	// If empty
  if(curr == NULL){
		append(n);
		return;
	}
	// If first node
	if(curr == p){
		setHead(n);
		n->next = p;
		return;
	}
  // Traverse to one node before p
  while(curr->next != p){
    curr = curr->next;
  }
	curr->next = n;
  n->next = p;
	return;
}

// Insert n after p
void SinglyLinkedList::add(SLink* p, SLink *n){
  cout << "Add " << n->value << endl;
  SLink* curr = this->getHead();
  if(curr == NULL) append(n);

  //Traverse to p
  while(curr != p){
    curr = curr->next;
  }
  n->next = curr->next;
  curr->next = n;
  return;
}

// Erase node at p
void SinglyLinkedList::erase(SLink *p) {
	// cout << "Erase" << endl;
  SLink* curr = head;
	if(curr == NULL) return;
	head = curr->next;
	delete curr;
	return;
}

// Find node
SLink* SinglyLinkedList::find(const int& s){
  cout << "Find " << s << endl;
  SLink* curr = this->getHead();

  // Traverse to S
  while(curr){
		if(curr->value == s) return curr;
    curr = curr->next;
  }
  return NULL;
}

SLink* SinglyLinkedList::advance(int n){
  cout << "Get Element " << n+1 << endl;
  SLink* curr = this->getHead();

  // Traverse n
  for(int i = 0; i < n; ++i){
    curr = curr->next;
  }
  return curr;
}

int SinglyLinkedList::getSize(){
	SLink* curr = getHead();
	int count = 0;
	while(curr){
		++count;
		curr = curr->next;
	}
	return count;
}

void SinglyLinkedList::print_all(SLink* head) {
	while (head) {
		cout << head->a.type << "( " << head->a.executeTime << " )";
		if (head = head->next) cout << ", ";
	}
	cout << "\n";
}
