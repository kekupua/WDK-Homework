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

int t = 0, count = 0;
int main(){
  // Setup
  fstream config;
  config.open("config.txt");
  int q1a, q1b, q1p, q1e, Q1, q2p, q2e, Q2, q3p, q3e, Q3;
  config >> q1a >> q1b >> q1p >> q1e >> Q1;
  config >> q2p >> q2e >> Q2;
  config >> q3p >> q3e >> Q3;
  // Declare Variables
  SinglyLinkedList s;
  int itQ1 = 0, itQ2 = 0, itQ3 = 0, drop = 0;
  int* firstQ = new int[Q1];
  int* secondQ = new int[Q2];
  int* thirdQ = new int[Q3];
  for(int i = 0; i < Q1; ++i) firstQ[i] = 0;
  for(int i = 0; i < Q2; ++i) secondQ[i] = 0;
  for(int i = 0; i < Q3; ++i) thirdQ[i] = 0;
  int packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
  int lambda1 = rand()%(q1b + 1 - q1a) + q1a; // Entrance between q1a and q1b seconds
  int mew1 = rand()%(q1e + 1 - q1p) + q1p; // Processing time between q1p and q1e seconds
  float mew1Av = 0, mew2Av = 0, mew3Av = 0, mew1Std = 0, mew2Std = 0, mew3Std = 0;
  int mew1Max = 0, mew2Max = 0, mew3Max = 0;
  vector<int> mew1V;
  vector<int> mew2V;
  vector<int> mew3V;

  SLink* iLink1 = new SLink(iOne, lambda1);
  s.addS(iLink1);
  insertOne(packet, lambda1, mew1, &s, t, &drop, Q1, firstQ, itQ1);
  // Loop
  while(1){
    // Check the queue
    Action mainAction = s.getHead()->a;

    // Recalulate
    ++count;
    bool ran = 0;
    packet = rand()%Y + X; // Random packet value between X and Y. X = 1, Y = 100
    lambda1 = rand()%(q1b + 1 - q1a) + q1a + t; // Calculate new lambda time between q1a and q1b seconds, adjusted for t
    mew1 = rand()%(q1e + 1 - q1p) + q1p + t; // Calculate new mew time between q1p and q1e, adjusted for t
    int mew2 = rand()%(q2e + 1 - q2p) + q2p + t; // Calculate new mew time between q2p and q2e, adjusted for t
    int mew3 = rand()%(q3e + 1 - q3p) + q3p + t; // Calculate new mew time between q3p and q3e, adjusted for t
    mew1V.push_back(lambda1+mew1-t-t);
    mew2V.push_back(mew2-t);
    mew3V.push_back(mew3-t);
    // Holds total value, will divide by count later
    mew1Av += (lambda1+mew1-t-t);
    mew2Av += (mew2-t);
    mew3Av += (mew3-t);
    mew1Std = stdDeviation(mew1V, mew1Av/count);
    mew2Std = stdDeviation(mew2V, mew2Av/count);
    mew3Std = stdDeviation(mew3V, mew3Av/count);
    mew1Max = maxOrMin(lambda1+mew1-t-t, mew1Max, 0);
    mew2Max = maxOrMin(mew2-t, mew2Max, 0);
    mew3Max = maxOrMin(mew3-t, mew3Max, 0);

    // Check the Action type
    // IF insert at queue one
    if(mainAction.type == iOne && mainAction.executeTime == t){
      insertOne(packet, lambda1, mew1, &s, t, &drop, Q1, firstQ, itQ1);
      ran = 1;
    }

    if(mainAction.type == pOne && mainAction.executeTime == t){
      processOne(packet, mew1, mew2, mew3, &s, t, &drop, firstQ, secondQ, thirdQ, Q1, Q2, Q3, &itQ1, itQ2, itQ3);
      ran = 1;
    }
    if(mainAction.type == pTwo && mainAction.executeTime == t){
      processTwo(packet, mew2, &s, t, secondQ, Q2, &itQ2);
      ran = 1;
    }
    if(mainAction.type == pThree && mainAction.executeTime == t){
      processThree(packet, mew3, &s, t, thirdQ, Q3, &itQ3);
      ran = 1;
    }
    if(!ran){
      cout << "\nWaiting..." << " (t = "<< t << ")" <<  endl;
    }
    if(s.getHead()->a.executeTime == t) --t;
    ++t;

    // Print Stats
    printDetails(s, mew1Av, mew2Av, mew3Av, count, mew1Max, mew2Max, mew3Max, q1a, q1p, q2p, q3p, mew1Std, mew2Std, mew3Std, drop, t, firstQ, Q1, itQ1, secondQ, Q2, itQ2, thirdQ, Q3, itQ3);
    wait(2);
    system("cls");
    system("clear");
  }
  return 0;
}
