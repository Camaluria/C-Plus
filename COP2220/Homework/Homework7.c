/*
	Author:		Cameron Alexander
	Course:		COP2220
	Homework:	7
	Title:		Array Statistics
	Due Date:	11/12/2016

	Sorts random numbers to determine the median using an array.
*/
#include <stdio.h>
#include <stdlib.h>

double calculateMedian(int array[], int size);
void displayResults(int array[], int size, double median);
void fillArray(int array[], int size);
void sortArray(int array[], int size);
void swap(int array[], int pos1, int poi2);

int main()
{
	//initialize variables
	int array1[25];
	int array2[24]; 
	double median1 = 0;
	double median2 = 0;

	//print program header
	printf("Cameron Alexander\nHomework7\n\n");

	//fill arrays
	fillArray(array1, 25);
	fillArray(array2, 24);

	//sort arrays
	sortArray(array1, 25);
	sortArray(array2, 24);

	//determine median
	median1 = calculateMedian(array1, 25);
	median2 = calculateMedian(array2, 24);

	//display results
	displayResults(array1, 25, median1);
	displayResults(array2, 24, median2);

	system("pause");
	return 0;
}

/*
	Calculates the median value of the numbers in the array.
	Note:  The array must be sorted to ensure the correct median value is found.
	array[] - The array containing the random numbers.
	size - The size of the array.
	returns the median value of the numbers in the array.
*/
double calculateMedian(int array[], int size)
{
	double median;

	if (size % 2 == 0)
	{
		median = ((array[size / 2] + array[(size / 2) - 1]) / 2.0);
	}
	else
		median = (array[size / 2]);

	return median;
}

/*
	Displays the results of the array statistics.
	array[] - The array containing the random numbers.
	size - The size of the array.
	median - The median value of the random values.
*/
void displayResults(int array[], int size, double median)
{
	int i;
	
	printf("Array Size: %d\n", size);
	printf("_____________\n");
	printf("Median Value: %.2f\n", median);

	for (i = 0; i < size; i++)
	{
		printf("%5d", array[i]);
	}
	printf("\n\n");
}
/*
	Fills the array with random numbers.
	array[] - The array containing the random numbers.
	size - The size of the array.
*/
void fillArray(int array[], int size)
{
	int i;
	srand(10);

	for (i = 0; i < size; i++)
	{
		array[i] = rand() % 1000;
	}
}

/*
	Sorts the array using the Bubble Sort algorithm.
	array[] - The array containing the random numbers.
	size - The size of the array.
*/
void sortArray(int array[], int size)
{
	int x, y;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size - 1; x++)
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