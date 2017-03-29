#include "task1Helper.h"
using namespace std;

void wait(float seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

bool compareByTime(struct Action &a, struct Action &b){
    return a.timeDelay < b.timeDelay;
}

void insertOne(int* packet, int* lambda, queue<int>& one, SinglyLinkedList list){
  float timeChange = *lambda;
  cout << *lambda << endl;

  // Attempt to insert into queue
  if(one.size() < 8){
    // Take the time to load in the packet
    wait(timeChange);
    cout << *packet << " inserted" << endl;
    one.push(*packet);
  }
  else{
    cout << "Error, Queue is full! Packet dropped." << endl;
  }

}

// void processOne(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& one);
//
// void insertTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);
//
// void processTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);
//
// void insertThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);
//
// void processThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);
