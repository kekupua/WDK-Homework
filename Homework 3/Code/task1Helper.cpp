#include "task1Helper.h"
using namespace std;

// Sleep the program for some time
void wait(int seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

// Calculate standard deviation
float stdDeviation(vector<int> qTimes, float mewAv){
	float std = 0;
	for(int i = 0; i < qTimes.size(); ++i){
		std += pow(qTimes[i] - mewAv, 2);
	}
	return sqrt(std/qTimes.size());
}

int maxOrMin(int recent, int past, int type){
	int value;
	// Max
	if(type == 0){
		value = recent >= past ? recent : past;
	}
	// Min
	if(type == 1){
		value = recent <= past ? recent : past;
	}
	return value;
}

// Check if queue is full
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

int dequeue(int queue[], int qSize, int* it){
	int temp = queue[*it];
	queue[*it] = 0;
	*it = (*it+1)%qSize;
	return temp;
}

void printQ(int queue[], int qSize, int it){
	for(int i = 0; i < qSize; ++i){
		if(queue[(it+i)%qSize] != 0) cout << queue[(it+i)%qSize] << " / ";
	}
	cout << endl;
}

void insertOne(int packet, int lambda, int mew1, SinglyLinkedList* list, int timeElapsed, int* drop, int qSize, int queue1[], int it){
  cout << "\nInsert One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	SLink* iFirst = new SLink(iOne, lambda);
	list->addS(iFirst);
  // Attempt to insert into queue
  if(!isFull(queue1, qSize)){
		enqueue(queue1, qSize, it, packet);
		SLink* pFirst = new SLink(pOne, mew1);
		list->addS(pFirst);
		return;
  }
  else{
    cout << "Error, Queue is full! Packet dropped." << endl;
		++*drop;
		return;
  }
}

void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int timeElapsed, int* drop, int queue1[], int queue2[], int queue3[], int qSize1, int qSize2, int qSize3, int *it1, int it2, int it3){
	cout << "\nProcess One @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());

	// Process...
	// Decide where to put the packet
	bool q = rand()%2;

	// Attempt to send to queue 2
	if(q){
		if(!isFull(queue3, qSize3)){
			packet = dequeue(queue1, qSize1, it1);
			enqueue(queue2, qSize2, it2, packet);
			SLink* pSecond = new SLink(pTwo, mew2);
			list->addS(pSecond);
		}

		else { cout << "Second queue full! Packet dropped." << endl; ++*drop; }
	}

	// Attempt to send to queue 3
	else {
		if(!isFull(queue3, qSize3)){
			packet = dequeue(queue1, qSize1, it1);
			enqueue(queue3, qSize3, it3, packet);
			SLink* pThird = new SLink(pThree, mew3);
			list->addS(pThird);
		}
		else { cout << "Third queue full! Packet dropped." << endl; ++*drop; }
	}
	return;
}

void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it){
	cout << "\nProcess Two @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());

	packet = dequeue(queue, qSize, it);
	return;
}

void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it){
	cout << "\nProcess Three @ " << "[t = "<< timeElapsed << "]"<<  endl;
	list->erase(list->getHead());
	packet = dequeue(queue, qSize, it);
	return;
}

void printDetails(SinglyLinkedList s, float mew1Av, float mew2Av, float mew3Av, int countL, int mew1Max, int mew2Max, int mew3Max, int lambda1, int q1p, int q2p, int q3p, float mew1Std, float mew2Std, float mew3Std, int drop, int t, int firstQ[], int Q1, int itQ1, int secondQ[], int Q2, int itQ2, int thirdQ[], int Q3, int itQ3){
	s.print_all(s.getHead());
	cout << "Average wait for Q1 | Q2 | Q3:\t" << mew1Av/countL << " | " << mew2Av/countL << " | " << mew3Av/countL << endl;
	cout << "Max wait for Q1 | Q2 | Q3:\t" << mew1Max << " | " << mew2Max << " | " << mew3Max << endl;
	cout << "Min wait for Q1 | Q2 | Q3:\t" << q1p+lambda1 << " | " << q2p << " | " << q3p << endl;
	cout << "Std Deviation for Q1 | Q2 | Q3:\t" << mew1Std << " | " << mew2Std << " | " << mew3Std << endl;
	cout << "Packets Dropped (Total and average): " << drop << " | " << (float) drop/t << endl;
	cout << "\nQ1: \t";
	printQ(firstQ,Q1,itQ1);
	cout << "Q2: \t";
	printQ(secondQ,Q2,itQ2);
	cout << "Q3: \t";
	printQ(thirdQ,Q3,itQ3);
}
