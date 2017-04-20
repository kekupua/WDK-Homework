#include "display.cpp"
#include "tamagotchi.h"
#include "item.h"
#include "time.cpp"
#include <string.h>
#include <iostream>
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
	display("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt");

else if(tama.getAge() < 15) 
	display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt");

else if(tama.getAge() < 30) 
	display("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt");

//evolve
if(tama.getAge() == 5) {
	display("Resources/Sprites/egg.txt", "Resources/Sprites/egg2.txt");
	display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt");
}
if(tama.getAge() == 15) {
	display("Resources/Sprites/rabbit.txt", "Resources/Sprites/rabbit2.txt");
	display("Resources/Sprites/potato.txt", "Resources/Sprites/potato2.txt");
}

}
