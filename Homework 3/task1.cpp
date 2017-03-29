#include "singlyLinked.h"
#include "task1Helper.h"
using namespace std;
// 1 input, 2 outgoing queues
// 1: insert into first queue at random intervals of time
// 1.5: if queue is full, drop request and send error
// 2: head of queue enters processing
// 3: after processing, goes into 2nd or 3rd queue randomly
// 3.5: if queue entering is full, drop request and send error
// 4: head of queue 2,3 enters processing
// Any action requires a New node be made and added to the list

int t = 0;
int main(){
  // Setup
  SinglyLinkedList s;
  fstream config;
  config.open("config.txt");

  int q1a, q1b, q1p, q1e, Q1, q2p, q2e, Q2, q3p, q3e, Q3;
  config >> q1a >> q1b >> q1p >> q1e >> Q1;
  config >> q2p >> q2e >> Q2;
  config >> q3p >> q3e >> Q3;

  queue<int> first; // Entrance queue
  queue<int> second, third; // Exit queues
  int packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
  int lambda = rand()%q1b + q1a; // Entrance between q1a and q1b seconds

  first.push(packet);
  Action aFirst;
  aFirst.type = iOne;
  aFirst.timeDelay = lambda;

  // Loop
  while(1){
    // Check the queue
    Actions mainAction = iOne;

    // IF insert at queue one
    if(mainAction == iOne){
      insertOne(&packet, &lambda, first, s);
      lambda = rand()%q1b + q1a; // Calculate new lambda time between q1a and q1b seconds
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
  }

  return 0;
}
