/*
Comment Author:  Cameron Alexander
Course :		 COP2220
Project #:       2
Title :		     Wind-Chill Calculator
Due Date:		 10/12/2016

Calculates Wind-Chill in Fahrenheit and Celsius from user provided temperature and windspeed
Note: Visual Studio 2015 no longer allows scanf to be used as it is unsafe and deprecated. scanf can be used with a global declaration override,
but I know we are not to have any global declarations and I didn't want that to interfere with the grader program.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//function prototypes
double calculateWindChill(int temperature, int windSpeed);
double convertTemperature(double windChill_F);
void displayResults(int temperature, int windSpeed, double windChill_F, double windChill_C);
bool getInput(int *pTemperature, int *pWindSpeed);
void performCalculations(int temperature, int windSpeed, double *pWindChill_F, double *pWindChill_C);
bool withinRange(int input, int minRange, int maxRange);


int main()
{
	//declare variables
	int temperature = 0;
	int windSpeed = 0;
	double windChill_F = 0;
	double windChill_C = 0;

	printf("Cameron Alexander\nProject 2\n\n"); //display name
	
	//get user input and validate
	if (getInput(&temperature, &windSpeed) == true)
	{
		//calculate wind-chill from user validated inputs
		performCalculations(temperature, windSpeed, &windChill_F, &windChill_C); 
		//display results of calculations to user
		displayResults(temperature, windSpeed, windChill_F, windChill_C);
	}
	system("pause");
	return 0;
}

/*
 * Calculate Wind Chill and return to calling function
 * temperature - user provided temperature
 * windSpeed - user provided windSpeed
 */
double calculateWindChill(int temperature, int windSpeed)
{
	return ((35.74 + (0.6215 * temperature))- (35.75 * pow(windSpeed, 0.16)) + ((0.4275 * temperature * pow(windSpeed, 0.16)))); //Wind-Chill Formula
}
/*
 * Convert Wind-Chill from Fahrenheit to Celsius
 * windChill_F - Wind-Chill in Fahrenheit
 */
double convertTemperature(double windChill_F)
{
	return ((windChill_F - 32)*(5.0 / 9.0)); //formula to convert fahrenheit to celsius
}
/*
 * Display results to user
 * temperature - user provided temperature
 * windSpeed - user provided windSpeed
 * windChill_F - Wind-Chill in Fahrenheit
 * windChill_C - Wind-Chill in Celsius
 */
void displayResults(int temperature, int windSpeed, double windChill_F, double windChill_C)
{
	printf("\n%15s%15s%15s%15s\n", "Outside Temp (F)", "Wind Speed", "Wind-Chill (F)", "Wind-Chill (C)");
	printf("%15s%15s%15s%15s\n","________________", "__________", "_____________","______________");
	printf("%15d%15d%15.3f%15.3f\n", temperature, windSpeed, windChill_F, windChill_C);
}
/*
 * Get temperature and windspeed from user
 * *pTemperature - pointer to provided variable to store input in calling function variable
 * *pWindSpeed - pointer to provided variable to store input in calling function variable
 */
bool getInput(int *pTemperature, int *pWindSpeed)
{
	//prompt for user input
	printf("Enter the ouside temperature (Fahrenheit) [-58 to 41]: ");
	//verify that one valid integer was entered for temperature and is within valid range and return false otherwise
	if(scanf_s("%d", pTemperature) != 1) 
	{
		printf("The entered temperature value is invalid\n");
		return false;
	}
	else if(!withinRange(*pTemperature, -58, 41))
	{
		return false;
	}
	//verify that one valid integer was entered for windspeed and is within valid range and return false otherwise
	printf("Enter the wind speed [2 to 50]: ");
	if (scanf_s("%d", pWindSpeed) != 1)
	{
		printf("The entered wind speed value is invalid\n");
	}

	if (!withinRange(*pWindSpeed, 2, 50))
	{
		return false;
	}


	return true;
}
/*
 * temperature - user provided temperature
 * windSpeed - user provided windSpeed
 * *pTemperature - pointer to provided variable to store input in calling function variable
 * *pWindSpeed - pointer to provided variable to store input in calling function variable
 */
void performCalculations(int temperature, int windSpeed, double *pWindChill_F, double *pWindChill_C)
{
	*pWindChill_F = calculateWindChill(temperature, windSpeed); //calculate windchill and store in variable
	*pWindChill_C = convertTemperature(*pWindChill_F); // take previously calculated windchill and convert to celsius and store in variable
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
	if(input < minRange || input > maxRange)
	{
		printf("The entered value is out of range [%d - %d]\n", minRange, maxRange);
		return false;
	}
	
	return true;
}
