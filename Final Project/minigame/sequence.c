#include <stdio.h>
#include "play.h"

int play(int pick)
{  int guess;		/*  the player's guess               */
   int num_guesses;	/*  the number of guesses remaining  */
   int result;          /*  the result of testing the guess  */

	/* Initialize the number of guesses      */
	num_guesses = MAX_GUESSES;

	/* While there are guesses remaining     */
	while( num_guesses > 0 )
	{
		/*  ask the player to guess      */
		printf("\tWhat is your guess? ");
		scanf("%d",&guess);

		/*  if the guess is correct      */
		result = test(pick,guess);
		if( result == WIN)
			/* return a winner!      */
		{	printf("YES!!\a  you guessed it!\n");
			return WIN;
		}

		/*  otherwise give the hint      */
		if( result == HI )
			printf("Too High!!!\n");
		else
			printf("Too Low!!!\n");

		/*  update the number of guesses */
		num_guesses = num_guesses -1;
	}

	/*  Return a loser :-(                  */
	printf("Sorry :-(, you're out of guesses\n");
	printf("The number was %d\n", pick);
	return LOSE;
}
