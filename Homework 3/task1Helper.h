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

void insertOne(int packet, int lambda1, int mew1, SinglyLinkedList* list, int time, int qSize);
void processOne(int packet, int mew1, int mew2, int mew3, SinglyLinkedList* list, int time, int qSize);
void processTwo(int packet, int mew2, SinglyLinkedList* list, int timeElapsed, int qSize);
void processThree(int packet, int mew3, SinglyLinkedList* list, int timeElapsed, int qSize);

#endif
