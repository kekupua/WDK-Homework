//status.cpp
#include "tamagotchi.h"
#include "status.h"

void status(class tama tama) {
	//print status
	cout << tama.getName() << endl;
	cout << "age: " << tama.getAge() << endl;
	cout << "$$$: " << tama.getMoney() << endl;

	//print health
	cout << "health: ";
	for(int i = 0; i < tama.getHealth(); i++)
		cout << "o";
	for(int i = 0; i < (10-tama.getHealth()); i++)
		cout << "-";
	

	//print hunger
	cout << endl << "belly: ";
	for(int i = 0; i < tama.getHunger(); i++)
		cout << "o";
	for(int i = 0; i < (10 - tama.getHunger()); i++)
		cout << "-";
	

	//print mood
	cout << endl << "mood: ";
	for(int i = 0; i < tama.getMood(); i++)
		cout << "o";
	for(int i = 0; i < (10 - tama.getMood()); i++)
		cout << "-";
	
}
