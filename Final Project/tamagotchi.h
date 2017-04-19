
//tamagotchi.h

#include <string.h>
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
public:
tama() {name = "Bob"; age = 0; hunger = 10; health = 10; mood = 10; money = 5;};
string getname() {return name;}
int getage() {return age;}
int gethunger() {return hunger;}
int gethealth() {return health;}
int getmood() {return mood;}
int getmoney() {return money;}
void setname(string x) {name = x;}
void setage(int x) {age = x;}
void sethunger(int x) {hunger = x;}
void sethealth(int x) {health = x;}
void setmood(int x) {mood = x;}
void setmoney(int x) {money =x;}
};
