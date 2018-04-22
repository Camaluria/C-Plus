/*
Author:    Cameron Alexander
Course:    COP2220
Homework#: 5
Title  :   Random Number Generator
Due Date:  11/6/2016
Generate Random Numbers and Calculate Results
*/


#include <stdlib.h>
#include <stdio.h>

int main()
{
	//initialize variables
	int random_array[25];
	int sum = 0;
	float average = 0;
	int minimum = 1000;
	int maximum = 0;
	int temp;
	int duplicate;
	int i;
	int j;
	int k;

	//fill array
	

	//determine array size for looping constraints
	int arraysize = sizeof(random_array) / sizeof(random_array[0]);

	//sum all random numbers generated
	for (i = 0; i < arraysize; i++)
	{
		sum = sum + random_array[i];
	}
	
	//determine average from sum
	average = (float)sum / arraysize;

	//find smallest and largest numbers in numbers generated
	for (i = 0; i < arraysize; i++)
	{
		if (random_array[i] < minimum)
		{
			minimum = random_array[i];
		}

		if (random_array[i] > maximum)
		{
			maximum = random_array[i];
		}
	}

	//sort array in ascending order
	for (i = 0; i < arraysize; i++)
	{
		for (j = i + 1; j < arraysize; j++)
		{
			if (random_array[i] > random_array[j])
			{
				temp = random_array[i];
				random_array[i] = random_array[j];
				random_array[j] = temp; 
			}
		}
		
	}

	//print array
	for (i = 5; i <= arraysize; i += 5)
	{
		for (j = i - 5; j < i; j++)
		{
			printf("%5d", random_array[j]);
		}
		printf("\n");
	}

	//display results
	printf("\n\nStatistics\n_________\n");
	printf("%3s: %d\n", "Sum", sum);
	printf("%5s: %.2f\n", "Average", average);
	printf("%5s: %d\n", "Minimum", minimum);
	printf("%5s: %d\n", "Maximum", maximum);


	system("pause");
	return 0;
}

