
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

void clrscr(){
  cout << "\033[2J\033[1;1H";
}

int main(){
  //void displayAnimation(string path1, string path2, ...)
  //egg
  for(int i = 0; i < 5; i++){
    usleep(400000);
    clrscr(); //clear screen
    
    ifstream in5("egg.txt");
    char s[255];

    while(in5){
      in5.getline(s, 255);
      if(in5) cout << s << endl;
    }
    
    usleep(400000);
    clrscr();
    
    ifstream in6("egg2.txt");
    while(in6){
      in6.getline(s, 255);
      if(in6) cout << s << endl;
    }

  }
  //rabbit
  for(int i = 0; i < 5; i++){
    usleep(400000);
    clrscr(); //clear screen
    
    ifstream in3("rabbit.txt");
    char s[255];

    while(in3){
      in3.getline(s, 255);
      if(in3) cout << s << endl;
    }
    
    usleep(400000);
    clrscr();

    ifstream in4("rabbit2.txt");
    while(in4){
      in4.getline(s, 255);
      if(in4) cout << s << endl;
    }
  }
  //potato
for(int i = 0; i < 5; i++){
  usleep(400000);
  clrscr(); //clear screen
  
  ifstream in1("potato.txt");
  char s[255];

  while(in1){
    in1.getline(s, 255);
    if(in1) cout << s << endl;
  }
  
  usleep(400000);
  clrscr();

  ifstream in2("potato2.txt");
  while(in2){
    in2.getline(s, 255);
    if(in2) cout << s << endl;
  }
}


}
