/*
Comment Author: Cameron Alexander
Course :		COP2220
Homework #:     4 
Title :		   Validate Leap Year
Due Date:		10/02/2016

Accepts a year and tells you if it is a valid leap year
Note: Bool lib is included in VS 2013 Ultimate so I did not have to define bool
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool withinRange(int, int, int); //function prototype
void validateLeapYear(int); //function prototype

int main()
{
	int year = 0; // store year entered by user

	printf("Author: Cameron Alexander\n");
	printf("Homework 4 - Leap Year Validator\n\n");
	printf("Enter a year between 1900 and 2030 (integer): "); // request year from user
	scanf_s("%d", &year); //store user
	
	//check if year provided is within range
	if (withinRange(year,1900,2030) == true) 
	{
		validateLeapYear(year); //call function to check year

	}
	else
	{
		printf("%d %s\n", year, "is outside the range of 1900 and 2030"); //if year is outside range then let user know
	}
	
	system("pause");
	return 0;

}

/*
 * Check that year is within range
 * year - user provided year
 * min - minimum year within range
 * max - maximum year within range
 */
bool withinRange(int year, int min, int max)
{
	return year >= min && year <= max;
}

/*
 * Check whether year is a leap year
 * year - user provided year
 */
void validateLeapYear(int year)
{
	if (year % 4 == 0 || year % 400 == 0) //check if year is divisble by 4 or 400
	{
		printf("%d %s\n", year, "is a leap year");
	}
	else if (year % 100 == 0) //check if year is divisible by 100
	{
		printf("%d %s\n", year, "is not a leap year");
		return;
	}
	else //all other situations are not a leap year
	{
		printf("%d %s\n", year, "is not a leap year");
	}
}