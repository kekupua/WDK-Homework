#include "guess.h"
using namespace std;
int play(int pick){
  int guess;
  int num_guesses;
  int result;

	// Initialize Guesses
	num_guesses = MAX_GUESSES;

	// While there are guesses remaining
	while(num_guesses > 0){
		// Ask the player to guess
		cout << "What is your guess?: ";
		cin >> guess;
    cin.clear();
    cin.ignore(255,'\n');

		// If correct
		result = test(pick,guess);
		if(result == WIN){
      cout << "Correct!\a You guessed it!\n";
			return WIN;
		}

		// Otherwise give hint
		if(result == HI)
			cout << "Too High!\n";
		else
			cout << "Too Low!\n";

		// Update guesses
		num_guesses = num_guesses-1;
	}

	// If out of guesses
	cout << "Sorry :( you're out of guesses\n";
	cout << "The number was " << pick << endl;
	return 0;
}
