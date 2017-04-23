#include "guess.h"
using namespace std;
int guessingGame(){
  int correct = 1, answer, timesCorrect = 0;
  char choice;
  ifstream rules("./minigame/instructions2.txt");
  cout << rules.rdbuf();
  cin >> choice;
  cin.clear();
  cin.ignore(255,'\n');
  choice = choice -'0';
  if(choice == 2){
   return 0;
  }
  if(choice == 1){
  	// While correct
  	while(correct){
      //  Pick a random number between START and STOP
  		answer = PICK(START,STOP);

  		// Thinking
  		cout << "My number is between 1 and 100, can you guess it?\n";
  		correct = play(answer);
  		if(correct) timesCorrect++;
  	}

  	// Close
  	cout << "\nYou've earned $"<< timesCorrect << "! Thanks for playing!\n";
    return timesCorrect;
  }
}
