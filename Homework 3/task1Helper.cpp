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

void insertOne(int* packet, int* lambda, int* mew1, int* mew2, int* mew3, vector<Action>& callQ, queue<int>& one){
  float timeChange = *lambda;
  cout << *lambda << endl;

  // Attempt to insert into queue
  if(one.size() < QONE){
    // Take the time to load in the packet
    wait(timeChange/1000);
    cout << *packet << " inserted" << endl;
    one.push(*packet);
  }
  else{
    cout << "Error! Queue is full" << endl;
  }

  // Calculate new lambda time
  *lambda = rand()%1000 + 2000; // Entrance between 2000 and 2999 miliseconds

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
