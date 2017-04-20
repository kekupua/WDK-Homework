///////// display.cpp ///////////
/////////   team RTS  //////////
#include "tamagotchi.h"
#include "display.h"
#include "time.h"
#include "status.h"
void clrscr(){
  cout << "\033[2J\033[1;1H";
}

int display(string x, string y, tama tama) {
  //void displayAnimation(string path1, string path2, ...)
  for(int i = 0; i < 5; i++){
    wait(0.4);
    clrscr(); // Clear screen
    char s[255];
    fstream in1;
    in1.open(x.c_str());
    while(in1){
      in1.getline(s, 255);
      if(in1) cout << s << endl;
    }

  	status(tama); // Print screen
    wait(0.4);
    clrscr(); // Clear screen

    fstream in2;
    in2.open(y.c_str());
    while(in2){
      in2.getline(s, 255);
      if(in2) cout << s << endl;
    }
    status(tama); // Print screen
  }

return 0;
}
