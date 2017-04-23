///////// display.cpp ///////////
/////////   team RTS  //////////
#include "tamagotchi.h"
#include "display.h"
#include "time.h"
#include "status.h"

void clrscr(){
  cout << "\033[2J\033[1;1H";
}

// Displays a static sprite based on given evolution number
void displayStatic(int evolution){
  system("clear");
  ifstream tama;
  if(evolution == 1){ // Egg
    tama.open("Resources/Sprites/egg.txt");
  }
  else if(evolution == 2){ // Rabbit
    tama.open("Resources/Sprites/rabbit.txt");
  }
  else if(evolution == 3){ // Potato
    tama.open("Resources/Sprites/potato.txt");
  }
  cout << tama.rdbuf();
  return;
}

void animate(class tama tama) {
  string x, y;
  int evolution = tama.getEvolution();
  if(evolution == 1){ // Egg
    x = "Resources/Sprites/egg.txt";
    y = "Resources/Sprites/egg2.txt";
  }
  else if(evolution == 2){ // Rabbit
    x = "Resources/Sprites/rabbit.txt";
    y = "Resources/Sprites/rabbit2.txt";
  }
  else{ // Potato
    x = "Resources/Sprites/potato.txt";
    y = "Resources/Sprites/potato2.txt";
  }

  for(int i = 0; i < 5; i++){
    wait(0.3);
    clrscr(); // Clear screen
    char s[255];
    ifstream in1;
    in1.open(x.c_str());
    cout << in1.rdbuf();
    status(tama); // Print screen

    wait(0.3);
    clrscr(); // Clear screen
    ifstream in2;
    in2.open(y.c_str());
    cout << in2.rdbuf();
    status(tama); // Print screen
  }

}
