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
bool isFull(int queue[], int qSize);
void enqueue(int queue[], int qSize, int it, int packet);
int dequeue(int queue[], int qSize, int* it);
void printQ(int queue[], int qSize, int it);
void insertOne(int packet, int lambda1, int mew1, SinglyLinkedList* list, int time, int qSize, int queue1[], int iterator);
void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int timeElapsed, int queue1[], int queue2[], int queue3[], int qSize1, int qSize2, int qSize3, int *it1, int it2, int it3);
void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it);
void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int queue[], int qSize, int* it);

#endif
