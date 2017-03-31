#include "task1Helper.h"
using namespace std;

void wait(int seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

bool isFull(int queue[], int qSize){
	for(int i = 0; i < qSize; ++i){
		if(queue[i] == 0)
			return 0;
	}
	return 1;
}

void enqueue(int queue[], int qSize, int it, int packet){
	int i = 0;
	while(queue[(it+i)%qSize] != 0){
		++i;
	}
	queue[(it+i)%qSize] = packet;
	return;
}

void dequeue(int queue[], int qSize, int* it){
	queue[*it] = 0;
	*it = (*it+1)%qSize;
	return;
}

void printQ(int queue[], int qSize, int it){
	for(int i = 0; i < qSize; ++i){
		if(queue[(it+i)%qSize] != 0) cout << queue[(it+i)%qSize] << " / ";
	}
	cout << endl;
}

void insertOne(int packet, int lambda, int mew1, SinglyLinkedList* list, int timeElapsed, int qSize, int queue1[], int it){
  cout << "\nInsert One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	SLink* iFirst = new SLink(iOne, lambda);
	list->addS(iFirst);
  // Attempt to insert into queue
  if(!isFull(queue1, qSize)){
    // Take the time to load in the packet
    //wait(lambda-timeElapsed);
		enqueue(queue1, qSize, it, packet);
		cout << "Q1: \t";
		printQ(queue1, qSize, it);
		SLink* pFirst = new SLink(pOne, mew1);
		list->addS(pFirst);
		return;
  }
  else{
    cout << "Error, Queue is full! Packet dropped." << endl;
		return;
  }
}

void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int timeElapsed, int queue1[], int queue2[], int queue3[], int qSize1, int qSize2, int qSize3, int *it1, int it2, int it3){
	cout << "\nProcess One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());

	// Process...
	// Decide where to put the packet
	//wait(mew1-timeElapsed);
	bool q = rand()%2;

	// Attempt to send to queue 2
	if(q){
		if(!isFull(queue3, qSize3)){
			dequeue(queue1, qSize1, it1);
			enqueue(queue2, qSize2, it2, packet);
			cout << "Q1: \t";
			printQ(queue1, qSize1, *it1);
			cout << "Q2: \t";
			printQ(queue2, qSize2, it2);
			SLink* pSecond = new SLink(pTwo, mew2);
			list->addS(pSecond);
		}

		else cout << "Second queue full! Packet dropped." << endl;
	}

	// Attempt to send to queue 3
	else {
		if(!isFull(queue3, qSize3)){
			dequeue(queue1, qSize1, it1);
			enqueue(queue3, qSize3, it3, packet);
			cout << "Q1: \t";
			printQ(queue1, qSize1, *it1);
			cout << "Q3: \t";
			printQ(queue3, qSize3, it3);
			SLink* pThird = new SLink(pThree, mew3);
			list->addS(pThird);
		}
		else cout << "Third queue full! Packet dropped." << endl;
	}
	return;
}

void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it){
	cout << "\nProcess Two @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	wait(mew2-timeElapsed);

	dequeue(queue, qSize, it);
	cout << "Q2: \t";
	printQ(queue, qSize, *it);
	return;
}

void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it){
	cout << "\nProcess Three @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	wait(mew3-timeElapsed);
	dequeue(queue, qSize, it);
	cout << "Q3: \t";
	printQ(queue, qSize, *it);
	return;
}
