#include "play.h"

int test(int picked, int guessed)
{

	/*  If the guess matches the pick      */
	if( guessed == picked )
		/*  return win!                */
		return WIN;

	/*  Otherwise if the guess is too low  */
	if( guessed < picked )
		/*  return low                 */
		return LOW;

	/*  Otherwise if the guess is too high */
	/*  return high                        */
	return HI;
}
