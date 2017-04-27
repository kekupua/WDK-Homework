#include "time.h"
#include "item.h"
#include "status.h"
#include "display.h"
#include "tamagotchi.h"
using namespace std;

int main() {
	srand(time(NULL)); // Seed random
	class tama Origin; // Make tamagotchi
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
			displayStatic(4);
			cout << "Oh No! Your Tamagotchi died :(\nYou made it " << Origin.getAge() << " days! [Program will now exit]" << endl;
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

		// Present menu
		char input;
		while(input != 7){
			if(Origin.isSick()) cout << "\nOh no! " << Origin.getName() << " is sick!\nPlease give " << Origin.getName() << " some medicine! [-1 Health per Day]\n";
			if(Origin.pooped()) cout << "\nOh no! " << Origin.getName() << " pooped!\n Please clean up after " << Origin.getName() << ". [-1 Health per Day]\n";
			cout << "\n\nMenu\n========\n";
			cout << "(1) Feed Tamagotchi\n(2) Play a Game\n(3) Go to the Shop\n(4) Clean up Mess\n(5) Check Inventory\n(6) Check Status\n(7) Next Day\n";
			cin >> input;
			cin.clear();
			cin.ignore(255,'\n');
			input = input - '0';
			ran = 1;
			if(input == 1){ // Feed
				Origin.feed();
			}
			else if(input == 2){ // Play game
				int dollars = Origin.playGame();
				Origin.setMoney(Origin.getMoney()+dollars);
				Origin.setMood(Origin.getMood()+1);
			}
			else if(input == 3){ // Shop for food
				Origin.shop();
			}
			else if(input == 4){ // Clean up mess
				Origin.clean();
			}
			else if(input == 5){ // Check Inventory
				Origin.printInventory();
			}
			else if(input == 6){ // Check status
				displayStatic(Origin.getEvolution());
				status(Origin);
			}
			else if(input == 7){ // Move forward to next day
				Origin.nextDay();
			}
			else{
				cout << "Invalid Input!, try again." << endl;
			}
		}
		input = 0;
	}

}
