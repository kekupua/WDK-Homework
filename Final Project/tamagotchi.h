//tamagotchi.h
#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class tama {
private:
  string name;
  int age, evolution;
  int sick;
  int hunger;
  int health, maxHealth;
  int mood;
  int money;
  int medC, breadC, candyC; // Count of items

public:
  tama() {name = "Bob"; age = 0; evolution = 1; sick = 0; hunger = 10; health = 10; maxHealth = 10; mood = 10; money = 5; medC = 0; breadC = 0; candyC = 0;}

  string getName() {return name;}
  int getAge() {return age;}
  int getEvolution() {return evolution;}
  int getHunger() {return hunger;}
  int getHealth() {return health;}
  int getMaxHealth() {return maxHealth;}
  int getMood() {return mood;}
  int getMoney() {return money;}
  int getMedC() {return medC;}
  int getBreadC() {return breadC;}
  int getCandyC() {return candyC;}
  int isSick() {return sick;}

  void setName(string x) {name = x;}
  void setAge(int x) {age = x;}
  void setHunger(int x) {if(x <= 10) hunger = x; return;}
  void setHealth(int x) {if(x <= maxHealth) health = x; return;}
  void setMaxHealth(int x) {maxHealth = x; return;}
  void setMood(int x) {if(x <= 10) mood = x; return;}
  void setMoney(int x) {money =x;}
  void setMedC(int m) {medC = m;}
  void setBreadC(int b) {breadC = b;}
  void setCandyC(int c) {candyC = c;}

  int playGame();
  void feed();
  void shop();
  void printInventory();
  void evolve();
  void nextDay();
  bool checkLife();
  bool checkEvolve();
};

#endif
