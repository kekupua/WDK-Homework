#include "tamagotchi.h"
#include "time.h"
using namespace std;

void time(class tama tama) {
	//increment age
	tama.setAge(tama.getAge()+1);

	//decrement mood
	tama.setMood(tama.getMood()-1);

	//decrement belly (randomly between 1 and 3)
	tama.setHunger(tama.getMood() - (rand() % 3) + 1);

	//randomly increment/decrement health
	tama.setHealth(tama.getHealth() + (rand() % 2) - 1);
}

// Sleep the program for some time
void wait(float seconds){
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
