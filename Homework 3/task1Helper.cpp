#include "task1Helper.h"
using namespace std;

void wait(int seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

bool compareByTime(struct Action &a, struct Action &b){
    return a.executeTime < b.executeTime;
}

void insertOne(int packet, int lambda, int mew1, SinglyLinkedList* list, int timeElapsed, int qSize){
  cout << "\nInsert One: " << lambda-timeElapsed << " seconds..." << endl;
  // Attempt to insert into queue
  if(timeElapsed < qSize){
    // Take the time to load in the packet
    wait(lambda-timeElapsed);
    // cout << packet << " inserted" << endl;
		list->erase(list->getHead());
  }
  else{
    cout << "Error, Queue is full! Packet dropped." << endl;
  }
	SLink* iFirst = new SLink(iOne, lambda);
	list->addS(iFirst);
	cout << "Line 30: ";
	list->print_all(list->getHead());
	SLink* pFirst = new SLink(pOne, mew1);
	list->addS(pFirst);
	cout << "Line 34: ";
	list->print_all(list->getHead());
	cout << list->getHead()->a.executeTime << endl;
	return;
}

void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList list, int timeElapsed, int qSize){
	cout << "\nProcess One: " << mew1-timeElapsed << " seconds..." << endl;
	list.erase(list.getHead());
	wait(mew1-timeElapsed);
	// Process...
	// Decide where to put the packet
	bool q = rand()%2;
	// Send to queue 2
	if(q){
		SLink* pSecond = new SLink(pTwo, mew2);
		list.addS(pSecond);
	}
	// Send to queue 3
	else {
		SLink* pThird = new SLink(pThree, mew2);
		list.addS(pThird);
	}
}

// void insertTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);
//
// void processTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);
//
// void insertThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);
//
// void processThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);
