
#include <stdio.h>
#include "play.h"
#define TRUE  1
#define FALSE 0
//#define DEBUG
#include <stdlib.h>

#define START    1   /*  macro for the beginning of range of numbers */
#define STOP   100   /*  macro for the end or range of numbers       */

#define PICK(start,stop) (rand() % ((stop) - (start) + 1) + (start))

int guess()
{  int keep_playing = TRUE;  /* do we keep playing?  initially true.  */
   int hidden_number;        /* the picked random number              */

	/*  Introduce the game                                  */
	printf("\t\tLet's play the guessing game!\n");

	/*  While the player wants to keep playing              */
	while( keep_playing )
	{	/*  pick a random number between START and STOP */
		hidden_number = PICK(START,STOP);

		/*  introduce the play                          */
		printf("I'm thinking of a number between %d "
			"and %d.  Can you guess it?\n",START,STOP);
#ifdef DEBUG
printf("debug:main:the pick is %d\n",hidden_number);
#endif

		/*  play the game                               */
		play(hidden_number);

		/*  ask the player if they want to continue     */
		printf("\nDo you want to play again?\n");
		printf("(1 for yes, 0 for no): ");
		scanf("%d", &keep_playing);
	}

	/*  say goodbye                                         */
	printf("\nThanks for the game.... bye...\n");
	
}
