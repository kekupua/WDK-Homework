//tamagotchi.h
#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H
#include <string>
#include <iostream>
using namespace std;

class tama {
private:
  string name;
  int age;
  int hunger;
  int health;
  int mood;
  int money;
  int medC, breadC, candyC; // Count of items

public:
  tama() { name = "Bob"; age = 0; hunger = 10; health = 10; mood = 10; money = 5; }

  string getName() {return name;}
  int getAge() {return age;}
  int getHunger() {return hunger;}
  int getHealth() {return health;}
  int getMood() {return mood;}
  int getMoney() {return money;}
  int getMedC() {return medC;}
  int getBreadC() {return breadC;}
  int getCandyC() {return candyC;}

  void setName(string x) {name = x;}
  void setAge(int x) {age = x;}
  void setHunger(int x) {hunger = x;}
  void setHealth(int x) {health = x;}
  void setMood(int x) {mood = x;}
  void setMoney(int x) {money =x;}
  void setMedC(int m) {medC = m;}
  void setBreadC(int b) {breadC = b;}
  void setCandyC(int c) {candyC = c;}

  bool playGame();
  void feed();
  void shop();

};

#endif
