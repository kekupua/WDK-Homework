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

	void insert(SLink* n, SLink* p);  //insert n before p, return pointer to n
	void add(SLink* p, SLink* n);	//insert n after p, return pointer to n
	void erase(SLink* p);		//erase node p
	SLink* find(const int& s);	//find node with specified content
	SLink* advance(int n);	// advance to nth element, return node pointer
	void print_all(); // print all elements in list

	SLink* getHead() { return head; }
	void setHead(SLink *p) { head = p; }
	int getSize();
private:
	SLink* head;
	SLink* tail;
	int size;  //one or the other is sufficient
};
