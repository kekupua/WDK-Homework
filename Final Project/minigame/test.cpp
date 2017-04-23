#include "guess.h"

int test(int picked, int guessed){
	// If match
	if( guessed == picked )
		return WIN;

	//  If too low of a guess
	if(guessed < picked)
		//return low
		return LOW;

	// If too high of a guess
	// return high
	return HI;
}
