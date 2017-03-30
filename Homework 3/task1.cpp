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

  SLink* iLink1 = new SLink(iOne, lambda1);
  s.addS(iLink1);
  insertOne(packet, lambda1, mew1, &s, t, Q1);
  // Loop
  while(1){
    bool ran = 0;
    // Check the queue
    Action mainAction = s.getHead()->a;
    cout << "Type: " << mainAction.type << " Time: " << mainAction.executeTime << endl;

    // Recalulate
    packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
    lambda1 = rand()%q1b + q1a + t; // Calculate new lambda time between q1a and q1b seconds, adjusted for t
    mew1 = rand()%q1e + q1p + t; // Calculate new mew time between q1p and q1e, adjusted for t
    int mew2 = rand()%q2e + q2p + t; // Calculate new mew time between q2p and q2e, adjusted for t
    int mew3 = rand()%q3e + q3p + t; // Calculate new mew time between q3p and q3e, adjusted for t

    // IF insert at queue one
    if(mainAction.type == iOne && mainAction.executeTime == t){
      insertOne(packet, lambda1, mew1, &s, t, Q1);
      ran = 1;
    }

    if(mainAction.type == pOne && mainAction.executeTime == t){
      processOne(packet, mew1, mew2, mew3, &s, t, Q1);
      ran = 1;
    }
    if(mainAction.type == pTwo && mainAction.executeTime == t){
      processTwo(packet, mew2, &s, t, Q2);
      ran = 1;
    }
    if(mainAction.type == pThree && mainAction.executeTime == t){
      processThree(packet, mew3, &s, t, Q3);
      ran = 1;
    }
    if(!ran){
      cout << "\nWaiting..." << " (t = "<< t << ")" <<  endl;
    }
    else --t;

    // Print call list
    s.print_all(s.getHead());
    ++t;
    wait(1);
  }

  return 0;
}
