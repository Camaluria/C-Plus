/*
 Comment Author: Cameron Alexander
 Course :		 COP2220
 Homework #:     2
 Title :		 Array Manipulator From File
 Due Date:		 09/04/2016

 Reads and Displays an array from a file. Sorts it ascendingly and descendingly and saves it file.
*/
#include <stdio.h>
#include <stdlib.h>

// global declarations
#define INPUT_FILE "Input.txt"
#define OUPUT_FILE "Output.txt"
#define SIZE_OF_ARRAY 50

// function declarations
void displayArray(int array[], bool sorted, bool ascending);
void readFile(int array[], char* filename);
void sortArray(int array[], bool ascending);
void swap(int array[], int pos1, int pos2);
void writeFile(int array[], char* filename);

int main() {
	// variable declarations
	int array[SIZE_OF_ARRAY];
    
	printf("Ima C Programmer\nHomework 2\n\n"); //display author and file title to user

	// read array from file and perform manipulations
    readFile(array, INPUT_FILE);  // read file and create array
    displayArray(array, false, false) // display array to user
    sortArray(array, true); // sort array ascendingly
    displayArray(array, true, true); // display array to user
    sortArray(array, false); // sort array descendingly
    displayArray(array, true, false); // display array
    writeFile(array, OUPUT_FILE); // write array to file
}

/*
	Display array to users.
	array = array passed from main.
	sorted = boolean for is array sorted.
	ascending = boolean for is array sorted ascendlingly.
*/
void displayArray(int array[], bool sorted, bool ascending) {
	int x;

	if (!sorted) {
		printf("Array Contents (unsorted)");
    } else if (ascending) {
		printf("Array Contents (sorted ascending)");
    } else {
		printf("Array Contents (sorted descending)");
    }
	for (x = 0; x < SIZE_OF_ARRAY; x++) {
		printf("%d\n", array[x]);
    }
}

/*
	Read file and add contents to an array.
	array = array to add contents of file to.
	filename = location of file to gather array contents from.
*/
void readFile(int array[], char* filename) {
    // This function reads data from the file into the array
}

/*
	Sort array ascendingly or descendingly. Code is missing for descending functionality 
	arrray= array to sort
	ascending = boolean to determine wether to sort ascending or descendingly. Not used
*/
void sortArray(int array[], bool ascending) {
	//local variable declaration
	int x, y; //variables used in for loop
	bool swapped = true; // boolean for was something recently swapped in array
	
	//compare array contents to one another and swap them ascendingly. Code is missing for descending.
    for (y = 0; y < SIZE_OF_ARRAY && swapped; y++) {
        swapped = false;
        for (x = 0; x < SIZE_OF_ARRAY - (y + 1); x++) {
            if (array[x] > array[x + 1]) {
                swap(x, x + 1);
                swapped = true;
            }
        }
    }
}

/*
	Swap postion of values in array.
	array = array to swap value postions in
	pos 1 = location of array value 1 that needs to be swapped
	pos 2 = location of array value 2 that needs to be swapped
*/
void swap(int array[], int pos1, int pos2) {
    //local variable declaration
	int temp = array[pos1];

	//swap value postions in array
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

/*
	Write array to file.
	array = array to write to file
	filename = location of file to write array tpp
*/
void writeFile(int array[], char* filename) {
	// This function writes data from the array out to the file
}
