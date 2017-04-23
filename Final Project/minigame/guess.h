#include <cstdlib>
#include <fstream>
#include <iostream>
#define START    1
#define STOP   100
#define PICK(start,stop) (rand() % ((stop) - (start) + 1) + (start))
#define MAX_GUESSES  6
#define WIN  1
#define HI   2
#define LOW  3

int guessingGame();
int test(int picked, int guessed);
int play(int pick);
