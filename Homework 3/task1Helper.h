#ifndef HELPER_H
#define HELPER_H
#define X 1
#define Y 100
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include "singlyLinked.h"
using namespace std;

/**
 * For the given seconds, sleep the program
 * @param seconds [Time delay in seconds]
 */
void wait(int seconds);













/**
 * Compares the time value of two structs
 * @param  a [1st struct]
 * @param  b [2nd struct]
 * @return   [sort value]
 */
bool compareByTime(struct Action &a, struct Action &b);


void insertOne(int packet, int lambda1, int mew1, SinglyLinkedList* list, int time, int qSize);
void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int time, int qSize);

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
#endif
