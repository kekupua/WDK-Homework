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

  int* firstQ = new int[Q1];
  int* secondQ = new int[Q2];
  int* thirdQ = new int[Q3];
  int packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
  int lambda1 = rand()%q1b + q1a; // Entrance between q1a and q1b seconds
  int mew1 = rand()%q1e + q1p;
  int mew2 = 0;
  int mew3 = 0;

  SLink* iLink1 = new SLink(iOne, lambda1);
  s.addS(iLink1);
  insertOne(packet, lambda1, mew1, &s, t, Q1);
  // Loop
  while(1){
    // Check the queue
    Action mainAction = s.getHead()->a;
    cout << "Type: " << mainAction.type << " Time: " << mainAction.executeTime << endl;

    // Recalulate load times
    lambda1 = rand()%q1b + q1a + t; // Calculate new lambda time between q1a and q1b seconds, adjusted for t
    mew1 = rand()%q1e + q1p + t; // Calculate new mew time between q1p and q1e, adjusted for t
    mew2 = rand()%q2e + q2p + t; // Calculate new mew time between q2p and q2e, adjusted for t
    mew3 = rand()%q3e + q3p + t; // Calculate new mew time between q3p and q3e, adjusted for t

    // IF insert at queue one
    if(mainAction.type == iOne && mainAction.executeTime == t){
      insertOne(packet, lambda1, mew1, &s, t, Q1);
    }

    else if(mainAction.type == pOne && mainAction.executeTime == t){
      processOne(packet, mew1, mew2, mew3, s, t, Q1);
    }
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
    else {
      cout << "\nWaiting..." << " (t = "<< t << " )"<<  endl;
    }

    packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
    s.print_all(s.getHead());
    ++t;
    wait(1);
  }

  return 0;
}
