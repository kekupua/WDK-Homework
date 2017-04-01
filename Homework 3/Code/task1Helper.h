#ifndef HELPER_H
#define HELPER_H
#define X 1
#define Y 100
#include <cmath>
#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "singlyLinked.h"
using namespace std;

/**
 * For the given seconds, sleep the program
 * @param seconds [Time delay in seconds]
 */
void wait(int seconds);
int maxOrMin(int recent, int past, int type);
float stdDeviation(vector<int> qTimes, float mewAv);
bool isFull(int queue[], int qSize);
void enqueue(int queue[], int qSize, int it, int packet);
int dequeue(int queue[], int qSize, int* it);
void printQ(int queue[], int qSize, int it);
void insertOne(int packet, int lambda1, int mew1, SinglyLinkedList* list, int time, int* drop, int qSize, int queue1[], int iterator);
void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int timeElapsed, int* drop, int queue1[], int queue2[], int queue3[], int qSize1, int qSize2, int qSize3, int *it1, int it2, int it3);
void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it);
void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it);
void printDetails(SinglyLinkedList s, float mew1Av, float mew2Av, float mew3Av, int count, int mew1Max, int mew2Max, int mew3Max, int lambda1, int q1p, int q2p, int q3p, float mew1Std, float mew2Std, float mew3Std, int drop, int t, int firstQ[], int Q1, int itQ1, int secondQ[], int Q2, int itQ2, int thirdQ[], int Q3, int itQ3);

#endif
