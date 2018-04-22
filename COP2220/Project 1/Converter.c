/*
Comment Author: Cameron Alexander
Course :		 COP2220
Project #:     1
Title :		 Unit Converter
Due Date:		 09/26/2016

Accepts Measurement from User Input and Converts to Different Unit Of Measurement 
Note: Visual Studio 2015 no longer allows scanf to be used as it is unsafe and deprecated. scanf can be used with a global declaration override,
	  but I know we are not to have any global declarations and I didn't want that to interfere with the grader program. 
*/
#include <stdio.h>
#include <stdlib.h>

//define converter constants
#define METERS_CONVERTER 0.3048
#define KILOGRAMS_CONVERTER 0.4536

int main()
{
	//variable declarations for user input
	int fahrenheit = 0; //store fahrenheit temperature user provides
	int feet = 0; //store feet measurement user provides 
	int pounds = 0; //store weight in pounds user provides

	//variable declarations for the converted user input
	double celsius = 0; //store celsius conversion of fahrenheit
	double meters = 0; //store meters conversion of feet
	double kilograms = 0;  //sotre kilograms conversion of kiliograms

	
	printf("Author: Cameron Alexander\n");
	printf("Project 1 - Unit Conversion Tool\n\n");
	printf("Enter a Fahrenheit temperature (integer): "); //request user input
	scanf_s("%d", &fahrenheit); //store user input
	printf("Enter a distance in feet (integer): "); //request user input
	scanf_s("%d", &feet); //store user input
	printf("Enter a weight in pounds (integer): "); //request user input
	scanf_s("%d", &pounds); //store user input

	celsius = ((fahrenheit - 32)*(5.0/9.0)); //formula to convert fahrenheit to celsius
	meters = (feet*METERS_CONVERTER); //formula to convert feet to meters
	kilograms = (pounds*KILOGRAMS_CONVERTER); //formula to convert pounds to kilograms

	//formatted table to display user input with proper conversions in an easy to read format
	printf("\n%15s%15s%15s%15s\n", "Original", "Value", "Converted to", "Value");
	printf("%15s%15s%15s%15s\n", "________", "_____", "____________", "_____");
	printf("%15s%15d%15s%15.3f\n", "Fahrenheit", fahrenheit, "Celsius", celsius);
	printf("%15s%15d%15s%15.3f\n", "Feet", feet, "Meters", meters);
	printf("%15s%15d%15s%15.3f\n", "Pounds", pounds, "Kilograms", kilograms);

	system("pause");
	return 0;

}