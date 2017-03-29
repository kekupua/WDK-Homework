#ifndef SINGLY_H
#define SINGLY_H
#include <iostream>
using namespace std;

enum Actions {iOne, pOne, pTwo, pThree};

struct Action{
  Actions type;
  int timeDelay;
};

struct SLink { //singly linked node
	int value;
	struct Action a;
	SLink* next;
	SLink(int v, SLink* n = 0)
		:value(v), next(n) {}
};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail = NULL;}
	void addS(SLink* p); // Insert the node sorted
	void insert(SLink* n, SLink* p);  //insert n before p, return pointer to n
	void add(SLink* p, SLink* n);	//insert n after p, return pointer to n
	void erase(SLink* p);		//erase node p
	SLink* find(const int& s);	//find node with specified content
	SLink* advance(int n);	// advance to nth element, return node pointer
	void append(SLink *p);		//add a list node at the end
	void print_all(SLink* head); // print all elements in list, given head

	SLink* getHead() { return head; }
	void setHead(SLink *p) { head = p; }
	int getSize();

private:
	SLink* head;
	SLink* tail;
	int size;
};

#endif
