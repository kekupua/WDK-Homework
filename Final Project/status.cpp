//status.cpp
#include <iostream>
using namespace std;

void status(class tama tama) {
    //print status
	cout << tama.getName() << endl;
	cout << "age: " << tama.getAge() << endl;
	cout << "$$$: " << tama.getMoney() << endl;

	//print health
	cout << "health: ";
	for(int i = 0; i <= tama.getHealth(); i++)
		cout << "o";
	if(tama.getHealth() < 10) {
		cout << "-";
		for(i = 0; i <= (10 - tama.getHealth()); i++)
			cout << "o";
	}

	//print hunger
	cout << endl << "belly: ";
	for(i = 0; i <= tama.getHunger(); i++)
		cout << "o";
	if(tama.getHunger() < 10) {
		cout << "-";
		for(i = 0; i <= (10 - tama.getHunger()); i++)
			cout << "o";
	}

	//print mood
	cout << endl << "mood: ";
	for(i = 0; i <= tama.getMood(); i++)
		cout << "o";
	if(tama.getMood() < 10) {
		cout << "-";
		for(i = 0; i <= (10 - tama.getMood()); i++)
			cout << "o";
	}

/////////////////////////////////

}
