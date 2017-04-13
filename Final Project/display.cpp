///////// display.cpp ///////////
/////////   team RTS  //////////

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

void clrscr(){
  cout << "\033[2J\033[1;1H";
}

int display(string x, string y){
  //void displayAnimation(string path1, string path2, ...)
  for(int i = 0; i < 5; i++){
    usleep(400000);
    clrscr(); //clear screen
    
    ifstream in5(x);
    char s[255];

    while(in5){
      in5.getline(s, 255);
      if(in5) cout << s << endl;
    }
    
    usleep(400000);
    clrscr(); //clear screen
    
    ifstream in6(y);
    while(in6){
      in6.getline(s, 255);
      if(in6) cout << s << endl;
    }

  }

return 0;
}
