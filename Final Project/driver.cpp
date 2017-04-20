#include "time.h"
#include "item.h"
#include "status.h"
#include "display.h"
#include "tamagotchi.h"
<<<<<<< HEAD
#include <conio.h>
=======
#include "item.h"
#include "time.h"
>>>>>>> e0f04c6f1c7fc463658c3439201366e2971ae711
using namespace std;

int main() {
	class tama Origin;
	//	Name the tamagotchi
	string name;
	cout << "Enter a name for your tamagotchi: ";
	cin >> name;
	Origin.setName(name);
	cout << "Welcome, " << Origin.getName() << "! Please take good care of your Tamagotchi! (CTRL+C to Quit)" << endl;

	int ran = 0;
	// Loop
	while(1){
		// Check if alive
		bool life = Origin.checkLife();
		if(!life){ // If dead
			cout << "Oh No! Your Tamagotchi has died :( [Program will now exit]" << endl;
			return 0;
		}
		// Check if evolving
		bool evolve = Origin.checkEvolve();
		if(evolve){
			// Show animation
			// Print prompts
		}
		if(ran) system("clear");
		ifstream test("Resources/Sprites/egg.txt");
		cout << test.rdbuf();
		// Present options
		int input;
		while(input != 5){
			cout << "\nMenu\n========\n";
			cout << "(1) Feed\n(2) Play a Game\n(3) Go to the Shop\n(4) Check Inventory\n(5) Next Day\n";
			cin >> input;
			ran = 1;
			if(input == 1){
				Origin.feed();
			}
			else if(input == 2){ // @TODO
				Origin.playGame();
			}
			else if(input == 3){
				Origin.shop();
			}
			else if(input == 4){
				Origin.printInventory();
			}
			else if(input == 5){// @TODO
				// Next Day
			}
			else{
				cout << "Invalid Input!, try again." << endl;
				cin.clear();
			}
		}
		input = 0;
	}

	// Not Currently Used
	if(Origin.getAge() < 5)
		animate("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt", Origin);

	else if(Origin.getAge() < 15)
		animate("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", Origin);

	else if(Origin.getAge() < 30)
		animate("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt", Origin);

	// Evolve
	if(Origin.getAge() == 5) {
		animate("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt", Origin);
		animate("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", Origin);
	}
	if(Origin.getAge() == 15) {
		animate("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", Origin);
		animate("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt", Origin);
	}

}
