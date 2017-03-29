using namespace std;

struct SLink {	//singly linked node
	int value;
	SLink* next;
	SLink(int v, SLink* n = 0)
		:value(v), next(n) {}
};

class SinglyLinkedList {
public:
	SinglyLinkedList() { head = NULL; tail = NULL; }
	void append(SLink *p);		//add a list node at the end
	void print_all(); // print all elements in list

	SLink* getHead() { return head; }
	void setHead(SLink *p) { head = p; }
private:
	SLink* head;
	SLink* tail;
	int size;  //one or the other is sufficient
};
