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

void insertOne(int packet, int lambda, SinglyLinkedList list, int timeElapsed){
  cout << "Time: " << lambda-timeElapsed << " seconds..." << endl;

  // Attempt to insert into queue
  if(timeElapsed < 8){
    // Take the time to load in the packet
    wait(lambda-timeElapsed);
    cout << packet << " inserted" << endl;
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
