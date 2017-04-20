#include "tamagotchi.h"
bool tama::playGame(){
return 1;
}

void tama::shop(){
  int input;
  cout << "What do you want to buy?" << endl;
  cout << "(1) Medicine [+1 health]\n(2) Bread[+1 health]\n(3) Candy[+1 mood, -1 health]\n";
  cin >> input;
  if(getMoney() == 0){
    cout << "You have no Money!" << endl;
  }
  else{
    if(input == 1){ // Medicine
      setMedC(getMedC()+1);
      setMoney(getMoney()-1);
      cout << "Bought Medicine!\n";
    }
    else if(input == 2){ // Bread
      setBreadC(getBreadC()+1);
      setMoney(getMoney()-1);
      cout << "Bought Bread!\n";
    }
    else if(input == 3){ // Candy
      setCandyC(getCandyC()+1);
      setMoney(getMoney()-1);
      cout << "Bought Candy!\n";
    }
    else{
      cout << "Invalid input!" << endl;
    }
  }

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
