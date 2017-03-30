#include "task1Helper.h"
using namespace std;

void wait(int seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

void insertOne(int packet, int lambda, int mew1, SinglyLinkedList* list, int timeElapsed, int qSize){
  cout << "\nInsert One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
  // Attempt to insert into queue
  if(timeElapsed < qSize){ // Placeholder
    // Take the time to load in the packet
    wait(lambda-timeElapsed);
		SLink* iFirst = new SLink(iOne, lambda);
		list->addS(iFirst);
		SLink* pFirst = new SLink(pOne, mew1);
		list->addS(pFirst);
		return;
  }
  else{
    cout << "Error, Queue is full! Packet dropped." << endl;
		SLink* iFirst = new SLink(iOne, lambda);
		list->addS(iFirst);
		return;
  }
}

void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int timeElapsed, int qSize){
	cout << "\nProcess One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());

	// Process...
	// Decide where to put the packet
	wait(mew1-timeElapsed);
	bool q = rand()%2;
	// Send to queue 2
	if(q){
		// If queue 2 isn't full
		SLink* pSecond = new SLink(pTwo, mew2);
		list->addS(pSecond);
		// If full
		// cout << "Second queue full! Packet dropped." << endl;
	}
	// Send to queue 3
	else {
		// If queue 3 isn't full
		SLink* pThird = new SLink(pThree, mew2);
		list->addS(pThird);
		// If full
		// cout << "Third queue full! Packet dropped." << endl;
	}
}

void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int qSize){
	cout << "\nProcess Two @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	wait(mew2-timeElapsed);

	// @TODO
	// Remove packet from queue
	// Print queue contents
	return;
}

void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int qSize){
	cout << "\nProcess Three @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	wait(mew3-timeElapsed);

	// @TODO
	// Remove packet from queue
	// print queue contents
	return;
}
