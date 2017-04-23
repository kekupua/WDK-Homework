#include "time.h"
#include "item.h"
#include "status.h"
#include "display.h"
#include "tamagotchi.h"
using namespace std;

int main() {
	srand(time(NULL)); // Seed random
	class tama Origin;
	int ran = 0;
	//Name the tamagotchi
	string name;
	cout << "[Please enlarge your terminal window]\n";
	cout << "Welcome! Please take good care of your Tamagotchi! (CTRL+C to Quit)\n";
	cout << "Enter a name for your tamagotchi: ";
	cin >> name;
	cin.clear();
	cin.ignore(255,'\n');
	Origin.setName(name);

	// Loop
	while(1){
		// Check if alive
		bool life = Origin.checkLife();
		if(!life){ // If dead
			cout << "Oh No! Your Tamagotchi died :( [Program will now exit]" << endl;
			return 0;
		}
		// Check if evolving
		bool evolve = Origin.checkEvolve();
		if(evolve){
			// Show animation
			Origin.evolve();
			animate(Origin);
			cout << endl << name << " has evolved! [+3 Max Health]\n";
		}
		else{ // Show animation
			if(ran) system("clear");
			animate(Origin);
		}

		// Present options
		char input;
		while(input != 6){
			// Clear buffer
			if(Origin.isSick()) cout << "\nOh no! " << Origin.getName() << " is sick!\nPlease give " << Origin.getName() << " some medicine! [-1 Health per Day]\n";
			cout << "\n\nMenu\n========\n";
			cout << "(1) Feed\n(2) Play a Game\n(3) Go to the Shop\n(4) Check Inventory\n(5) Check Status\n(6) Next Day\n";
			cin >> input;
			cin.clear();
			cin.ignore(255,'\n');
			input = input - '0';
			ran = 1;
			if(input == 1){
				Origin.feed();
			}
			else if(input == 2){ // @TODO
				int dollars = Origin.playGame();
				Origin.setMoney(Origin.getMoney()+dollars);
				Origin.setMood(Origin.getMood()+1);
			}
			else if(input == 3){
				Origin.shop();
			}
			else if(input == 4){
				Origin.printInventory();
			}
			else if(input == 5){
				displayStatic(Origin.getEvolution());
				status(Origin);
			}
			else if(input == 6){
				Origin.nextDay();
			}
			else{
				cout << "Invalid Input!, try again." << endl;
			}
		}
		input = 0;
	}

}
