///////// display.cpp ///////////
/////////   team RTS  //////////
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
//#include "tamagotchi.h"
#include "status.cpp"
using namespace std;

void clrscr(){
  cout << "\033[2J\033[1;1H";
}

int display(string x, string y, class tama tama) {
  //void displayAnimation(string path1, string path2, ...)
  for(int i = 0; i < 5; i++){
    usleep(400000);
    clrscr(); //clear screen

    char s[255];
    ifstream in1(x);
    while(in1){
      in1.getline(s, 255);
      if(in1) cout << s << endl;
    }

   //print status
	status(tama);

/////////////////////////////////

    usleep(400000);
    clrscr(); //clear screen

    ifstream in2(y);
    while(in2){
      in2.getline(s, 255);
      if(in2) cout << s << endl;
    }

   //print status
	status(tama);

  }
return 0;
}
