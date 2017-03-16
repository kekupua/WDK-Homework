#include "task1Helper.h"
using namespace std;
// 1 input, 2 outgoing queues
// 1: insert into first queue at random intervals of time
// 1.5: if queue is full, drop request and send error
// 2: head of queue enters processing
// 3: after processing, goes into 2nd or 3rd queue randomly
// 3.5: if queue entering is full, drop request and send error
// 4: head of queue 2,3 enters processing

int main(){
  // Setup
  vector<Action> callQ; // Call queue
  queue<int> first; // Entrance queue
  queue<int> second, third; // Exit queues
  int packet = rand()%10 + 1; // Random packet value between 1 and 10
  int lambda = rand()%1000 + 2000; // Entrance between 2000 and 2999 miliseconds
  int mew1 = rand()%1000 + 3000; // Processing Q1 time between 3000 and 3999 miliseconds
  int mew2 = 0;
  int mew3 = 0;
  //int mew2 = rand()%1000 + 1000; // Processing Q2 time between 1000 and 1999 miliseconds
  //int mew3 = rand()%1000 + 500;  // Processing Q3 time between 500 and 1499 miliseconds
  //lambda = rand()%1000 + 2000; // Entrance between 2000 and 2999 miliseconds
  //action = checkQueue();
  //delay(lambda);

  first.push(packet);
  Action aFirst;
  aFirst.type = iOne;
  aFirst.timeDelay = lambda;
  callQ.push_back(aFirst);
  while(1){
    // Check the queue
    Actions mainAction = callQ[0].type;

    // IF insert at queue one
    if(mainAction == iOne){
      insertOne(&packet, &lambda, &mew1, &mew2, &mew3, callQ, first);
    }
    // else if(mainAction == pOne){
    //   processOne(packet,lambda,mew1,mew2,mew3,callQ,first);
    // }
    // else if(mainAction == iTwo){
    //   insertTwo(packet,lambda,mew1,mew2,mew3,callQ,second);
    // }
    // else if(mainAction == pTwo){
    //   processTwo(packet,lambda,mew1,mew2,mew3,callQ,second);
    // }
    // else if(mainAction == iThree){
    //   insertThree(packet,lambda,mew1,mew2,mew3,callQ,third);
    // }
    // else{ // pThree
    //   processThree(packet,lambda,mew1,mew2,mew3,callQ,third);
    // }

    // Resort the Queue based on shortest time
    sort(callQ.begin(), callQ.end(), compareByTime);
  }

  return 0;
}
