/*
Comment Author:  Cameron Alexander
Course :		 COP2220
Homework #:      5
Title :		     Prime Number Counter
Due Date:		 10/23/2016

Calculates total number of prime numbers from 0 to user provided number.
Note: Visual Studio 2015 no longer allows scanf to be used as it is unsafe and deprecated. scanf can be used with a global declaration override,
but I know we are not to have any global declarations and I didn't want that to interfere with the grader program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//function prototypes
int countPrimes(int input);
bool isPrime(int input);
bool withinRange(int input, int minRange, int maxRange);


int main(int argc, char *argv[])
{
	int prime = 0; //store user input
	int total = 0; //store total number of primes between 0 and user provided number

	printf("Homework 5\nCameron Alexander\n\n");
	//prompt for user input
	printf("Enter a number between [0 to 1000]: ");
	//verify that one valid integer was entered for temperature and is within valid range
	if (scanf_s("%d",&prime) != 1)
	{
		printf("The entered value is invalid\n");
		exit(0);
	}
	else if (withinRange(prime, 0, 1000) != true)
	{
		exit(0);
	}
	else
	{
		total = countPrimes(prime);
		printf("Exactly %d prime numbers exist between 0 and %d\n", total, prime);
	}
	system("pause");
	return 0;


}

/*
 * Tally all prime numbers between 0 and number provided
 * input - user provided number
 */
int countPrimes(int input)
{
	int counter = 0; //variable to store total number of primes

	for (int i = 0; i <= input; i++)
	{
		if (isPrime(i) == true)
		{
			counter++;
		}
	}
	return counter; 
}

/*
* Verify that user provided number is valid
* input - user provided number
*/
bool isPrime(int input)
{
	if (input < 2)
	{
		return false;
	}

	if (input % 2 == 0 && input != 2)
	{
		return false;
	}

	for (int i = 2; i <= sqrt(input); i++)
	{
		if (input%i == 0)
		{
			return false;
		}
	}
	return true;
}


/*
* Verify that user provided numbers are valid
* input - user provided number
* minRange - Lowest number allowed
* maxRange - Highest number allowed
*/
bool withinRange(int input, int minRange, int maxRange)
{
	//check if number is within range and return false if not
	if (input < minRange || input > maxRange)
	{
		printf("The entered value is out of range [%d - %d]\n", minRange, maxRange);
		return false;
	}

	return true;
}