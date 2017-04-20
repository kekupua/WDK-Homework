#include "display.h"
#include "status.h"
#include "tamagotchi.h"
#include "item.h"
#include "time.h"
using namespace std;

int main() {
	class tama tama;
	cout << tama.getName() << endl;

	//name the tamagotchi
	cout << "Enter a name for your tamagotchi: ";
	string x;
	cin >> x;
	tama.setName(x);

	/*
	char c;
	cin >> c;
	if(c == 'n')
		time(tama);
	*/

	if(tama.getAge() < 5)
		display("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt", tama);

	else if(tama.getAge() < 15)
		display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", tama);

	else if(tama.getAge() < 30)
		display("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt", tama);

	//evolve
	if(tama.getAge() == 5) {
		display("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt", tama);
		display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", tama);
	}
	if(tama.getAge() == 15) {
		display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt", tama);
		display("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt", tama);
	}

}
