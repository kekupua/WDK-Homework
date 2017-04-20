#include <iostream>
#include "tamagotchi.h"
using namespace std;
#define DEAD 1

int time(class tama tama) {
	//if too old
	if(tama.getAge() == 30)
		return DEAD

	//increment age
	tama.setAge(tama.getAge()++)

	//decrement mood
	tama.setMood(tama.getMood()--)

	//decrement belly (randomly between 1 and 3)
	tama.setHunger(tama.getMood() - (rand() % 3) + 1)

	//randomly increment/decrement health
	tama.setHealth(tama.getHealth() + (rand() % 2) - 1)

}
