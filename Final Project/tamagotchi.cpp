#include "time.h"
#include "display.h"
#include "./minigame/memory.h"
#include "./minigame/guess.h"
#include "tamagotchi.h"

int tama::playGame(){
  int winStatus = 0;
  displayStatic(evolution);
  char game;
  cout << "(1) Memory Game\n(2) Guessing Game\n(3) Go Back\n";
  cin >> game;
	game = game - '0';
  if(game == 1) winStatus = memoryGame(evolution);
  else if(game == 2) winStatus = guessingGame();
  else if(game == 3) return 0;
  else{
    cout << "Invalid Input!\n";
    return 0;
  }
  return winStatus;
}

void tama::shop(){
  displayStatic(evolution);
  int input;
  cout << "What do you want to buy?" << endl;
  cout << "(1) Medicine [+1 Health, Cures Sickness]\n(2) Bread [+2 Belly]\n(3) Candy [+1 Mood, -1 Health]\n(4) Cancel Order\n";
  cin >> input;
  if(getMoney() == 0){
    cout << "You have no Money!" << endl;
  }
  else{
    if(input == 1){ // Medicine
      medC++;
      money -= 1;
      cout << "Bought Medicine! [+1 Medicine, -$1]\n";
    }
    else if(input == 2){ // Bread
      breadC++;
      money -= 1;
      cout << "Bought Bread! [+2 Belly, -$1]\n";
    }
    else if(input == 3){ // Candy
      candyC++;
      money -= 1;
      cout << "Bought Candy! [+1 Candy, -$1]\n";
    }
    else if(input == 4){
      cout << "Leaving Store...\n";
    }
    else{
      cout << "Invalid input!" << endl;
    }
  }

}

void tama::feed(){
  displayStatic(evolution);
  int input;
  cout << "What do you want to feed?" << endl;
  cout << "(1) Medicine [+1 Health]\n(2) Bread [+2 Belly]\n(3) Candy [+1 Mood, -1 Health]\n(4) Cancel Feeding\n";
  cin >> input;
  if(input == 1){ // Medicine
    if(medC >= 1){
      cout << "Gave Medicine! [+1 Health, -1 Medicine, Sickness Cured]\n";
      medC -= 1;
      health += 1;
      sick = 0;
      if(health > maxHealth) health = maxHealth;
    }
    else{
      cout << "You have no Medicine!" << endl;
    }
  }
  else if(input == 2){ // Bread
    if(breadC >= 1){
      cout << "Fed Bread! [+2 Belly, -1 Bread]\n";
      breadC -= 1;
      hunger += 2;
      if(hunger > 10) hunger = 10;
    }
    else{
      cout << "You have no Bread!" << endl;
    }
  }
  else if(input == 3){ // Candy
    if(candyC >= 1){
      cout << "Gave Candy! [+1 Mood, -1 Health]\n";
      candyC -= 1;
      mood += 1;
      health -= 1;
      if(mood > 10) mood = 10;
    }
    else{
      cout << "You have no Candy!" << endl;
    }
  }
  else if(input == 4){
    cout << "Cancelling feeding...\n";
  }
  else{
    cout << "Invalid input!" << endl;
  }
}

void tama::printInventory(){
  displayStatic(evolution);
  cout << "Currently in your inventory, you have:" << endl;
  if(money) cout << "$" << money << endl;
  if(medC) cout << medC << " Medicine\n";
  if(breadC) cout << breadC << " Bread\n";
  if(candyC) cout << candyC << " Candy\n";
  if(!money && !medC && !breadC && !candyC) cout << "Nothing!\n";
  return;
}

void tama::evolve(){
  if(evolution <= 3){
    maxHealth += 3;
    evolution += 1;
  }
  return;
}

void tama::nextDay(){
  //output = min + (rand() % (int)(max - min + 1))
  age++;

  // Sickness Checks
  if(!mood) health -= 1;
  if(sick) health -= 1;
  else{
    int sickChance = rand()%(int)(100+1);
    if(sickChance > 75) sick = 1; // 25% chance to get sick
  }

  if(hunger == 0) health -= 1; // If hungry, tamagotchi is dying
  hunger -= 1 + (rand()%(int)(3-1+1)); // Subtract a range from 1-3 from current hunger
  if(mood-1 >= 0) mood -= 1; // Tamagotchi gets lonely at night
  health -= rand()%1; // Subtract a range from 0-1 from current health
  if(hunger < 0) hunger = 0;
  return;
}

bool tama::checkLife(){
  if(health == 0) return 0;
  else return 1;
}

bool tama::checkEvolve(){
  if(age == 5 || age == 15) return 1;
  else return 0;
}
