/*
Comment Author:  Cameron Alexander
Course :		 COP2220
Project #:       5
Title :		     Random Number Metrics Calculator
Due Date:		 11/19/2016

Generates random numbers and gives basic calculations of the results.

Note: This program has most of the functionality of the structure diagram but does implement finding the number of occurenences of numbers.
	  This is done because there is no way to generate and record the number of occurences of a number without calling a separate function which
	  is expressly forbidden in the program requirements. This makes it so I can not properly calcuate the min.max.average, and median as specified.
Note: Visual Studio 2015 no longer allows scanf to be used as it is unsafe and deprecated. scanf can be used with a global declaration override,
but I know we are not to have any global declarations and I didn't want that to interfere with the grader program.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_SIZE 100

//function prototypes
void calculateStatistics(int array[], int *pMin, int *pMax, double *pMedian, double *pAverage);
void copyArray(int array[], int copy[]);
void generateNumbers(int array[], int seed, int count);
double getAverage(int array[]);
int getMax(int array[]);
double getMedian(int array[]);
int getMin(int array[]);
void initializeArray(int array[]);
void printReport(int array[], int count, int min, int max, double median, double average);
bool readFile(char *filename, int *pSeed, int *pCount);
void sortArray(int array[]);
void swap(int array[], int pos1, int pos2);
bool validateInput(int seed, int count);
bool withinRange(int value, int minRange, int maxRange);

int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		int array[ARRAY_SIZE];
		double average = 0.0;
		int count = 0;
		int maximum = 0;
		double median = 0.0;
		int minimum = 0;
		int seed = 0;

		readFile(argv[1], &seed, &count);
		generateNumbers(array, seed, count);
		calculateStatistics(array, &minimum, &maximum, &median, &average);
		printReport(array, count, minimum, maximum, median, average);
	}
	else
	{
		printf("No filename specified");
	}

	system("pause");
	return 0;
}

/*
 * Calculate metrics of the random array
 * pMin - pointer to maximum variable
 * pMax - pointer to maximum variable
 * pMedian - pointer to median variable
 * pAverage - pointer to average variable
 */
void calculateStatistics(int array[], int *pMin, int *pMax, double *pMedian, double *pAverage)
{
	*pMin = getMin(array);
	*pMax = getMax(array);
	*pMedian = getMedian(array);
	*pAverage = getAverage(array);
}

/*
 * Copy Contents of one array to another
 * array[] - the array containing the original numbers
 * copy[] - the new array containing the original numbers
 */
void copyArray(int array[], int copy[])
{
	int i;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		copy[i] = array[i];
	}
}
/*
Fills the array with random numbers.
array[] - The array containing the random numbers.
seed - random number seed.
count - size of numbers allowed.
*/
void generateNumbers(int array[], int seed, int count)
{
	int i;
	srand(seed);

	if (validateInput(seed, count))
	{
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			array[i] = rand() % count;
		}
	}
	else
	{
		system("exit");
	}

}
/*
 * Calculate Average
 * array[] - The array containing the random numbers.
 *
 */
double getAverage(int array[])
{
	int i;
	double average;
	int sum = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		sum = sum + array[i];
	}

	average = (float)sum / ARRAY_SIZE;

	return average;
}
/*
* Calculate Maximum
* array[] - The array containing the random numbers.
*
*/
int getMax(int array[])
{

	int i;
	int maximum = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
		return maximum;
}

/*
* Calculate Median
* array[] - The array containing the random numbers.
*
*/
double getMedian(int array[])
{
	double median;
	int temp_array[ARRAY_SIZE];
	copyArray(array, temp_array);
	sortArray(temp_array);

	if (ARRAY_SIZE % 2 == 0)
	{
		median = ((temp_array[ARRAY_SIZE / 2] + temp_array[(ARRAY_SIZE / 2) - 1]) / 2.0);
	}
	else
		median = (temp_array[ARRAY_SIZE / 2]);

	return median;
}
/*
* Calculate minimum
* array[] - The array containing the random numbers.
*
*/
int getMin(int array[])
{
	int i;
	int minimum = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (array[i] < minimum)
		{
			minimum = array[i];
		}
	}
		return minimum;
}
/*
 * Initialize array to given size
*/
void initializeArray(int array[])
{
	array = (int*)malloc(ARRAY_SIZE * sizeof(int));
}

void printReport(int array[], int count, int min, int max, double median, double average)
{
	int i;
	int j;
	sortArray(array);
	printf("Author: Cameron Alexander\nAssignment: Project 4- Random Number Statistics");
	printf("\n\nStatistics\n_________\n");
	printf("%3s: %.2f\n", "Median", median);
	printf("%5s: %.2f\n", "Average", average);
	printf("%5s: %d\n", "Minimum", min);
	printf("%5s: %d\n\n", "Maximum", max);
	
	for (i = 0; i < ARRAY_SIZE; i += 5)
	{
		for (j = i - 5; j < i; j++)
		{
			printf("%5d", array[j]);
		}
		printf("\n");
	}
	

}
/*
* Read contents of file
* filename - file location to be read
* pSeed - pointer to seed variable used for random number seed
* pCount - pointer to count variable used for number count in random number generation
*/
bool readFile(char *filename, int *pSeed, int *pCount)
{

	FILE* file;

	if (file = fopen(filename, "r") == NULL)
	{
		printf("Invalid Filename!");
		return false;
		exit(0);
	}
	else
	{
		file = fopen(filename, "r");
		fscanf(file,"%d %d", pSeed, pCount);
		fclose(file);

		return true;
	}
}

/*
 * Sorts the array using the Bubble Sort algorithm.
 * array[] - The array containing the random numbers.
*/
void sortArray(int array[])
{

	int x, y;

	for (y = 0; y < ARRAY_SIZE; y++)
	{
		for (x = 0; x < ARRAY_SIZE - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap(array, x, x + 1);
			}
		}
	}
}

/*
Swaps the values between two positions within the array.
array[] - The array containing the random numbers.
pos1 - The first value in the array to swap.
pos2 - The second value in the array to swap.
*/
void swap(int array[], int pos1, int pos2)
{
	int temp = array[pos1];

	array[pos1] = array[pos2];
	array[pos2] = temp;
}
/*
* validate that seed and count are within requirements
* seed - number used in random number generator seed
* count - number used in random number generator
*/
bool validateInput(int seed, int count)
{
	if (withinRange(seed, 0, 10000) && withinRange(count, 100, 1000))
	{
		return true;
	}
	else
	{
		return false;
	}
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