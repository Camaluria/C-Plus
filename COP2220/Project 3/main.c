/*
Comment Author:  Cameron Alexander
Course :		 COP2220
Project #:       3
Title :		     Rock Paper Scissors Lizard Spock
Due Date:		 10/30/2016

Plays Rock Paper Scissors Lizard Spock based on user input from command line
Note: Visual Studio 2015 no longer allows scanf to be used as it is unsafe and deprecated. scanf can be used with a global declaration override,
but I know we are not to have any global declarations and I didn't want that to interfere with the grader program.
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//define hand signs played
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

//define win/tie conditions
#define SHELDON_WINS 0
#define LEONARD_WINS 1
#define TIE 2

int convertShape(char* shape);
void displayResults(char* sheldonsInitialShape, int sheldonWins, char* leonardsInitialShape, int leonardWins, int ties);
int determineLeonardsNextShape(int sheldonsCurrentShape, int leonardsCurrentShape, int gameOutcome);
int determineSheldonsNextShape(int sheldonsCurrentShape, int leonardsCurrentShape, int gameOutcome);
int determineWinner(int sheldonsShape, int leonardsShape);
int getBetterShape(int shape);
void playGame(int sheldonsInitialShape, int leonardsInitialShape, int numberGames, int *pSheldonsWinCount, int *pLeonardsWinCount, int *pTieCount);
void updateScores(int gameOutcome, int *pSheldonsWinCount, int *pLeonardsWinCount, int *pTieCount);

int main(int argc, char *argv[])
{
	printf("Cameron Alexander\nProject 3 - Rock-Paper-Scissors-Lizard-Spock\n\n");

	//check valid number of commands entered
	if (argc != 4)
	{
		printf("Invalid number of commands entered! Exiting Program.");
		system("exit");
	}
	//initialize variables
	int sheldonsInitialShape = 0;
	int leonardsInitialShape = 0;
	int sheldonsWins = 0;
	int leonardsWins = 0;
	int ties = 0;
	int rounds = 0;

	sheldonsInitialShape = convertShape(argv[1]); //convert command line argument to playable sign
	leonardsInitialShape = convertShape(argv[2]); //convert command line argument to playable sign
	rounds = atoi(argv[3]); //conver command line argument to number of rounds to play

	playGame(sheldonsInitialShape, leonardsInitialShape, rounds, &sheldonsWins, &leonardsWins, &ties); //commence game
	displayResults(argv[1], sheldonsWins, argv[2], leonardsWins, ties); //display results of game

	system("pause");
	return 0;

}

/*
 * Convert command line argument to playable sign
 * shape - command line string enetered
 */
int convertShape(char* shape)
{
	char* shapeToLower = strlwr(shape);

	if (strcmp(shapeToLower, "rock") == 0)
	{
		return ROCK;
	}
	else if (strcmp(shapeToLower, "scissors") == 0)
	{
		return SCISSORS;
	}
	else if (strcmp(shapeToLower, "paper") == 0)
	{
		return PAPER;
	}
	else if (strcmp(shapeToLower, "lizard") == 0)
	{
		return LIZARD;
	}
	else if (strcmp(shapeToLower, "spock") == 0)
	{
		return SPOCK;
	}
}

/*
* Display end result of game
* sheldonsInitialShape - first shape sheldon played
* sheldonWins - number of games sheldon won
* leonardsInitialShape - first shape leonard played
* leonardWins - number of games leonard won
* ties - number of games leonard and sheldon tied
*/
void displayResults(char* sheldonsInitialShape, int sheldonWins, char* leonardsInitialShape, int leonardWins, int ties)
{
	//print opening moves
	printf("Sheldon's Initial Move: %s\n", sheldonsInitialShape);
	printf("Leonard's Initial Move: %s\n", leonardsInitialShape);

	//determine overall winner based on wins
	if (sheldonWins > leonardWins)
	{
		printf("Sheldon Wins!\n");
	}
	else if (sheldonWins == leonardWins)
	{
		printf("Sheldon and Leonard Tie!\n");
	}
	else
	{
		printf("Leonard Wins!\n");
	}

	printf("Sheldon won %d game(s), Leonard won %d game(s), and they tied %d game(s)\n\n", sheldonWins, leonardWins, ties); //print totals
}

/*
* Determine the best shape for leonard to play next.
* sheldonsCurrentShape - Shape sheldon played in last round
* leonardsCurrentShape - Shape leonard played in last round
* gameOutcome - winner of last round
*/
int determineLeonardsNextShape(int sheldonsCurrentShape, int leonardsCurrentShape, int gameOutcome)
{
	//leonard will not change shape if he won
	if (gameOutcome == LEONARD_WINS)
	{
		return leonardsCurrentShape;
	}
	//leonard will play the best shape to counter his current shape if he ties
	else if (gameOutcome == TIE)
	{
		return getBetterShape(leonardsCurrentShape);
	}
	//leonard will play the best shape to counter sheldons shape if he loses
	else if (gameOutcome == SHELDON_WINS)
	{
		return getBetterShape(sheldonsCurrentShape);
	}
}

/*
* Determine the best shape for sheldon to play next.
* sheldonsCurrentShape - Shape sheldon played in last round
* leonardsCurrentShape - Shape leonard played in last round
* gameOutcome - winner of last round
*/
int determineSheldonsNextShape(int sheldonsCurrentShape, int leonardsCurrentShape, int gameOutcome)
{
	//sheldon will play Spock Shape on every other turn.
	if (sheldonsCurrentShape != SPOCK)
	{
		return SPOCK;
	}
	else
	{
		switch (gameOutcome)
		{
		case SHELDON_WINS: return ROCK; break;
		case LEONARD_WINS: return PAPER; break;
		case TIE: return LIZARD; break;
		}
	}
}
/*
* Determine whose shape won for this round of play.
* sheldonsShape - Shape sheldon played in last round
* leonardsShape - Shape leonard played in last round
*/
int determineWinner(int sheldonsShape, int leonardsShape)
{

	if (sheldonsShape == leonardsShape)
	{
		return TIE;
	}

	if (sheldonsShape == ROCK)
	{
		if (leonardsShape == PAPER || leonardsShape == SPOCK)
		{
			return LEONARD_WINS;
		}
		else
		{
			return SHELDON_WINS;
		}
	}

	if (sheldonsShape == SCISSORS)
	{
		if (leonardsShape == ROCK || leonardsShape == SPOCK)
		{
			return LEONARD_WINS;
		}
		else
		{
			return SHELDON_WINS;
		}
	}

	if (sheldonsShape == PAPER)
	{
		if (leonardsShape == SCISSORS || leonardsShape == LIZARD)
		{
			return LEONARD_WINS;
		}
		else
		{
			return SHELDON_WINS;
		}
	}

	if (sheldonsShape == LIZARD)
	{
		if (leonardsShape == ROCK || leonardsShape == SCISSORS)
		{
			return LEONARD_WINS;
		}
		else
		{
			return SHELDON_WINS;
		}
	}

	if (sheldonsShape == SPOCK)
	{
		if (leonardsShape == PAPER || leonardsShape == LIZARD)
		{
			return LEONARD_WINS;
		}
		else
		{
			return SHELDON_WINS;
		}
	}
}
/*
* Determine the best shape to play for the next round
* shape - last shape played
*/
int getBetterShape(int shape)
{
	switch (shape)
	{
	case ROCK: return SPOCK; 
		break;
	case PAPER: return LIZARD; 
		break;
	case SCISSORS: return SPOCK; 
		break;
	case SPOCK: return PAPER; 
		break;
	case LIZARD: return SCISSORS; 
		break;
	}

}

/*
* Play Rock Paper Scissors Lizard Spock
* sheldonsInitialShape - Shape sheldon played in last round
* leonardsInitialShape - Shape leonard played in last round
* numberGames - number of rounds
* pSheldonsWinCount - number of games sheldon has won
* pLeonardWinCount - number of games leonard has won
* pTieCount - number of games leonard and sheldon has tied
*/
void playGame(int sheldonsInitialShape, int leonardsInitialShape, int numberGames, int *pSheldonsWinCount, int *pLeonardsWinCount, int *pTieCount)
{
	int i;
	int winner; //variable to store current round winner
	int sheldonsCurrentShape = sheldonsInitialShape;
	int leonardsCurrentShape = leonardsInitialShape;

	//play each round of game
	for (i = 0; i < numberGames; i++)
	{
		//determine winner of current round
		winner = determineWinner(sheldonsCurrentShape, leonardsCurrentShape);
		//update scores
		updateScores(winner, pSheldonsWinCount, pLeonardsWinCount, pTieCount);
		//change shapes in preparation of next round
		sheldonsCurrentShape = determineSheldonsNextShape(sheldonsCurrentShape, leonardsCurrentShape, winner);
		//change shape in prepartion of next round
		leonardsCurrentShape = determineLeonardsNextShape(sheldonsCurrentShape, leonardsCurrentShape, winner);
	}
}

/*
* Update win counts after each round
* gameOutcome - results of who won last round
* pSheldonsWinCount - number of games sheldon has won
* pLeonardWinCount - number of games leonard has won
* pTieCount - number of games leonard and sheldon has tied
*/
void updateScores(int gameOutcome, int *pSheldonsWinCount, int *pLeonardsWinCount, int *pTieCount)
{
	switch (gameOutcome)
	{
	case SHELDON_WINS: *pSheldonsWinCount = *pSheldonsWinCount +1;
		break;
	case LEONARD_WINS: *pLeonardsWinCount = *pLeonardsWinCount + 1;
		break;
	case TIE: *pTieCount = *pTieCount +1;
		break;
	}
}