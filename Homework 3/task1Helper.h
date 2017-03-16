#define QONE 8
#define QTWO 10
#define QTHREE 13
#include <ctime>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

enum Actions { iOne, pOne, iTwo, pTwo, iThree, pThree };

struct Action{
  Actions type;
  int timeDelay;
};

void wait(int seconds);

/**
 * Compares the time value of two structs
 * @param  a [1st struct]
 * @param  b [2nd struct]
 * @return   [sort value]
 */
bool compareByTime(struct Action &a, struct Action &b);

/**
 * Insert into the first queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
void insertOne(int* packet, int* lambda, int* mew1, int* mew2, int* mew3, vector<Action>& callQ, queue<int>& one);

/**
 * Process and exit from first queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
//void processOne(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& one);

/**
 * Insert into the second queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
//void insertTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);

/**
 * Process and exit from second queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
//void processTwo(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& two);

/**
 * Insert into third queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
//void insertThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);

/**
 * Process and exit from third queue
 * @param packet [Value to be insert]
 * @param lambda [Time delay for first queue entrance]
 * @param mew1   [Time delay for first queue processing]
 * @param mew2   [Time delay for second queue processing]
 * @param mew3   [Time delay for third queue processing]
 * @param callQ  [Function call queue]
 */
//void processThree(int packet, int lambda, int mew1, int mew2, int mew3, vector<Actions>& callQ, queue<int>& three);
