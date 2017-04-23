//status.cpp
#include "tamagotchi.h"
#include "status.h"

void status(class tama tama) {
	//print status
	cout << tama.getName();
	switch(tama.getEvolution()){
		case 1: cout << " [Egg]\n"; break;
		case 2: cout << " [Rabbit]\n"; break;
		case 3: cout << " [Potato Man]\n"; break;
	}
	cout << "Age: " << tama.getAge() << " Days old\n";
	cout << "$$$: " << tama.getMoney() << endl;

	//print health
	cout << "Health: ";
	for(int i = 0; i < tama.getHealth(); i++)
		cout << "+ ";
	for(int i = 0; i < (tama.getMaxHealth()-tama.getHealth()); i++)
		cout << "_ ";
	cout << "(" << tama.getHealth() << "/" << tama.getMaxHealth() << ")";

	//print hunger
	cout << "\nBelly: ";
	for(int i = 0; i < tama.getHunger(); i++)
		cout << "+ ";
	for(int i = 0; i < (10 - tama.getHunger()); i++)
		cout << "_ ";
	cout << "(" << tama.getHunger() << "/10)";

	//print mood
	cout << "\nMood: ";
	for(int i = 0; i < tama.getMood(); i++)
		cout << "+ ";
	for(int i = 0; i < (10 - tama.getMood()); i++)
		cout << "_ ";
  cout << "(" << tama.getMood() << "/10)";

	return;
}
