#include "../time.h"
#include "../display.h"
#include "memory.h"
using namespace std;
int memoryGame(int evolution){
  char choice;
  ifstream rules("./minigame/game2.txt");
  cout << rules.rdbuf();
  cin >> choice;
  cin.clear();
  cin.ignore(255,'\n');
  choice = choice -'0';
  if(choice == 2){
    return 0;
  }
  else if(choice == 1){
    int correct = 1, loopCount = 5, timesCorrect = 0;
    while(correct){
      displayStatic(evolution);
      string answer;

      for(int i = 0; i < loopCount; ++i){
        int asciiChar = 65+(rand()%(int)(90-65+1));  // range of uppercase ascii alphabetical characters
        answer.push_back(char(asciiChar));
      }

      cout << "My secret code is: ";
      for(int i = 0; i < answer.length(); ++i) cout << answer[i];
      cout << endl;
      wait(3);

      displayStatic(evolution);
      string guess;
      cout << "What is my secret code?: ";
      getline(cin, guess);

      locale loc;
      for (int i=0; i < guess.length(); ++i) // For comparison
        guess[i] = toupper(guess[i],loc);

      if(!answer.compare(guess)){ // Correct match
        cout << "Good Job! You got it correct!" << endl;
        timesCorrect++;
        loopCount++;
        wait(3);
      }
      else{ // Wrong match
        cout << "Wrong answer :( The answer was ";
        for(int i = 0; i < answer.length(); ++i) cout << answer[i];
        cout << "\nYou Earned $" << timesCorrect << "!\nLet's play again later!\n";
        return timesCorrect;
      }
    }
  }
  else {
    cout << "Invalid Input!\n";
    return 0;
  }
  cout << "Error! Shouldn't be here.\n";
  return 0;
}
