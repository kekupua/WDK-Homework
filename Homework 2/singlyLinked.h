#include "basicAccount.h"
using namespace std;

struct SLink {	//singly linked node
	basicAccount b;
	int value;
	SLink* next;
	SLink(basicAccount* bank)
		:b(*bank), next(NULL){}
	SLink(int v, SLink* n = 0)
		:value(v), next(n) {}
};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail = NULL; }
 	bool addB(SLink* p);
	// Overload functions
	void findB(string name); // Find based on name
	void findB(long int id); // Find based on ID
	void deleteB(string name); // Delete based on name
	void deleteB(long int id); // Delete based on id
	void append(SLink *p);		//add a list node at the end
	void print_all(); // print all elements in list

	SLink* getHead() { return head; }
	void setHead(SLink *p) { head = p; }
private:
	SLink* head;
	SLink* tail;
	int size;  //one or the other is sufficient
};
