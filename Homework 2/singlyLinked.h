#include "basicAccount.h"
using namespace std;

struct SLink {	//singly linked node
	basicAccount b;
	int value;
	SLink* next;
	SLink(basicAccount bank)
		:b(bank){}
	SLink(int v, SLink* n = 0)
		:value(v), next(n) {}
};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail = NULL; }
 	void addB();

	void insert(SLink* n, SLink* p);  //insert n before p, return pointer to n
	void add(SLink* p, SLink* n);	//insert n after p, return pointer to n
	void erase(SLink* p);		//erase node p
	SLink* find(const int& s);	//find node with specified content
	SLink* advance(int n);	// advance to nth element, return node pointer
	void append(SLink *p);		//add a list node at the end
	void print_all(); // print all elements in list

	SLink* getHead() { return head; }
	void setHead(SLink *p) { head = p; }
	int getSize();
private:
	SLink* head;
	SLink* tail;
	int size;  //one or the other is sufficient
};
