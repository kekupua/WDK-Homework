#include "tamagotchi.h"
bool tama::playGame(){

}

void tama::feed(){
  int input;
  cout << "What do you want to feed?" << endl;
  cout << "(1) Medicine [+1 health]\n(2) Bread[+1 health]\n(3) Candy[+1 mood, -1 health]\n";
  cin >> input;
  if(input == 1){ // Medicine
    if(getMedC() >= 1){
      setMedC(getMedC()-1);
      setHealth(getHealth()+1);
    }
    else{
      cout << "You have no Medicine!" << endl;
    }
  }
  else if(input == 2){ // Bread
    if(getBreadC() >= 1){
      setBreadC(getBreadC()-1);
      setHunger(getHunger()+1);
    }
    else{
      cout << "You have no Bread!" << endl;
    }
  }
  else if(input == 3){ // Candy
    if(getCandyC() >= 1){
      setCandyC(getCandyC()-1);
      setMood(getMood()+1);
      setHealth(getHealth()-1);
    }
    else{
      cout << "You have no Candy!" << endl;
    }
  }
  else{
    cout << "Invalid input!" << endl;
  }
}
