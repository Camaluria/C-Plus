/*
	Author: Cameron Alexander 
	Course: COP 2220
	Project#: 5
	Title: Vehicle Owner Management System
	Due Date: 12/11/2016

	Displays vehicle owner data in various views.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adds built-in String functions to the program

#include "owner.h" // Adds user-defined data structures to the program

// Define the bool data type and values
#define bool int
#define false 0
#define true !false

#define SIZE 10 // Size of the owner data array

// Create numbered list of values (starts at 0 by default)
enum SortBy { City = 1, LastName, Mileage, Year };

// function prototypes
void displayRecords(OWNER array[], int size, int sortType);
char* getSortString(int sortType);
bool readFile(char *filename, OWNER array[]);
void sortArray(OWNER array[], int size, int sortType);
void sortByCityState(OWNER array[], int size);
void sortByLastName(OWNER array[], int size);
void sortByMileage(OWNER array[], int size);
void sortByYear(OWNER array[], int size);
void swap(OWNER array[], int pos1, int pos2);

int main(int argc, char* argv[])
{
	OWNER array[SIZE];

	printf("Cameron Alexander\nProject 5\n\n");

	if (argc == 2) // Test if user provided required number of command-line arguments
	{
		if (readFile(argv[1], array)) // Read owner data from the data file
		{
			displayRecords(array, SIZE, NULL); // Display unsorted owner data
			sortArray(array, SIZE, LastName); // Sort owner data by owner's last name
			displayRecords(array, SIZE, LastName); // Display sorted owner data
			sortArray(array, SIZE, Mileage); // Sort owner data by vehicle's mileage
			displayRecords(array, SIZE, Mileage); // Display sorted owner data
			sortArray(array, SIZE, Year); // Sort owner data by vehicle's year
			displayRecords(array, SIZE, Year); // Display sorted owner data
			sortArray(array, SIZE, City); // Sort owner data by owner's city and state
			displayRecords(array, SIZE, City); // Display sorted owner data
		}
		else
		{
			printf("Error:  An error occurred file reading the data file.");
		}
	}
	else 
	{
		printf("Error:  Invalid number of arguments.\n");
	}
	system("pause");
	return 0;
}

/*
	Displays the owner vehicle records.
	array[] - The array containing the owner data.
	size - The size of the owner data array.
	sortOrder - The current order of the owner data.
*/
void displayRecords(OWNER array[], int size, int sortOrder)
{
	int x;
	char name[19], cityState[18], makeModel[21];

	printf("Owner Information (%s):\n\n", getSortString(sortOrder));
	printf("%-20s%-28s%-19s%-7s%-15s%-22s%-6s%-7s\n", "Owner Name", "Owner Address", "City, State", "Zip", "Owner Phone #", "Make & Model", "Year", "Mileage");
	printf("%-20s%-28s%-19s%-7s%-15s%-22s%-6s%-7s\n", "----------", "-------------", "-----------", "---", "-------------", "------------", "----", "-------");

	for (x = 0; x < size; x++)
	{
		// Combine first and last names together as a single value
		strcpy_s(name, 19, array[x].firstName);
		strcat_s(name, 19, " "); strcat_s(name, 19, array[x].lastName);
		
		// Combine city and state together as a single value
		strcpy_s(cityState, 18, array[x].city);
		strcat_s(cityState, 18, ", "); strcat_s(cityState, 18, array[x].state);

		// Combine make and model names together as a single value
		strcpy_s(makeModel, 21, array[x].vehicle.make);
		strcat_s(makeModel, 21, " "); strcat_s(makeModel, 21, array[x].vehicle.model);

		// Display the data for a single vehicle owner
		printf("%-20s%-28s%-19s%-7s%-15s%-22s%-6d%-7d\n", name, array[x].address, cityState, array[x].zip, array[x].phone, makeModel, array[x].vehicle.year, array[x].vehicle.mileage);
	}
	printf("\n\n");
}

/*
	Returns a string describing the current order of the owner data.
	sortOrder - The current order of the owner data.
	returns a string describing the current order of the owner data.
*/
char* getSortString(int sortOrder)
{
	char* sortString = "Unsorted"; // Default to unsorted

	switch (sortOrder)
	{
		case City:
			sortString = "Sorted by City and State";
			break;
		case LastName:
			sortString = "Sorted by Last Name";
			break;
		case Mileage:
			sortString = "Sorted by Mileage";
			break;
		case Year:
			sortString = "Sorted by Year - Descending";
			break;
	}
	return sortString;
}

/*
	Breaks a data record into its individual values and 
	stores the values in the appropriate data structure. 
	recordData - the data to manipulate and store in the array.
	returns the data structure containing the vehicle owner data.
*/
OWNER parseRecord(char* recordData)
{
	OWNER owner; // Owner data structure (located in the owner.h header file)
	char* nextToken;

	// This block of code stores each value of a data record into the appropriate variable in the data structure
	strcpy_s(owner.lastName, LAST_NAME_SIZE, strtok_s(recordData, ",", &nextToken));
	strcpy_s(owner.firstName, FIRST_NAME_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.address, ADDRESS_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.city, CITY_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.state, STATE_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.zip, ZIP_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.phone, PHONE_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.vehicle.make, MAKE_SIZE, strtok_s(NULL, ",", &nextToken));
	strcpy_s(owner.vehicle.model, MODEL_SIZE, strtok_s(NULL, ",", &nextToken));
	owner.vehicle.year = atoi(strtok_s(NULL, ",", &nextToken));
	owner.vehicle.mileage = atoi(strtok_s(NULL, ",", &nextToken));

	return owner;
}

/*
	Reads the owner data records into the program.
	filename - The path and name of the owner data file.
	array[] - The array to store the owner data.
	returns true if the file was read successfully; otherwise, false.
*/
bool readFile(char *filename, OWNER array[])
{
	int recordCount = 0;
	FILE *fp; // File pointer
	bool status = true;
	char line[256]; // Buffer for reading a record from the owner data file

	fopen_s(&fp, filename, "r"); // Opens the owner data file for reading

	if (fp != NULL) // If the file was opened successfully
	{
		while (fgets(line, sizeof(line), fp)) // Keep reading records until the end of the file is reached
		{
			array[recordCount++] = parseRecord(line); // Store the owner data structure in the the owner array
		}
		fclose(fp); // Closes the owner data file
	}
	else {
		printf("Error:  Unable to open the specified file.");
	}
	return status;
}

/*
	Performs the appropriate sort function based on the provided sort type.
	array[] - The array to store the owner data.
	size - The size of the owner data array.
	sortType - The specified sort to perform.
*/
void sortArray(OWNER array[], int size, int sortType)
{
	switch (sortType) 
	{
		case City:
			sortByCityState(array, size);
			break;
		case LastName:
			sortByLastName(array, size);
			break;
		case Mileage:
			sortByMileage(array, size);
			break;
		case Year:
			sortByYear(array, size);
			break;
	}
}

/*
	Sorts the owner data array by the owner's city and state using the Bubble Sort algorithm.
	array[] - The array containing the owner data.
	size - The size of the owner data array.
*/
void sortByCityState(OWNER array[], int size)
{
	int x, y;
	bool swapped = true;

	for (y = 0; y < size && swapped; y++) // Traversal loop
	{
		swapped = false;
		for (x = 0; x < size - (y + 1); x++) // Comparison loop
		{
			// Compare the owner state values of two owner data records
			// If the first owner state value is greater, swap the owner data records
			// If and only if the owner state values are equivalent, compare the owner city values of the two owner data records
			// If the first owner city value is greater, swap the owner data records
			{
				if (strcmp(array[x].state, array[x + 1].state) == 0)
				{
					if (strcmp(array[x].city, array[x + 1].city) > 0)
					{
						swap(array, x, x + 1);
						swapped = true;
					}
				}
				else
				{
					if (strcmp(array[x].state, array[x + 1].state) > 0)
					{
						swap(array, x, x + 1);
						swapped = true;
					}
				}
				
			}
		}
	}
}

/*
	Sorts the owner data array by the owner's last name using the Bubble Sort algorithm.
	array[] - The array containing the owner data.
	size - The size of the owner data array.
*/
void sortByLastName(OWNER array[], int size)
{
	int x, y;
	bool swapped = true;

	for (y = 0; y < size && swapped; y++) // Traversal loop
	{
		swapped = false;
		for (x = 0; x < size - (y + 1); x++) // Comparison loop
		{
			// Compare the owner last name values of two owner data records
			// If the first owner last name value is greater, swap the owner data records
			{
				if (array[x].lastName[0] > array[x + 1].lastName[0])
				{
					swap(array, x, x + 1);
					swapped = true;
				}
			}
		}
	}
}

/*
	Sorts the owner data array by the vehicle's mileage using the Bubble Sort algorithm.
	array[] - The array containing the owner data.
	size - The size of the owner data array.
*/
void sortByMileage(OWNER array[], int size)
{
	int x, y;
	bool swapped = true;

	for (y = 0; y < size && swapped; y++) // Traversal loop
	{
		swapped = false;
		for (x = 0; x < size - (y + 1); x++) // Comparison loop
		{
			// Compare the vehicle mileage values of two owner data records
			// If the first vehicle mileage value is greater, swap the owner data records
			{
				if (array[x].vehicle.mileage > array[x + 1].vehicle.mileage)
				{	
				swap(array, x, x + 1);
				swapped = true;
				}
				
			}
		}
	}
}

/*
	Sorts the owner data array by the vehicle's year using the Bubble Sort algorithm.
	array[] - The array containing the owner data.
	size - The size of the owner data array.
*/
void sortByYear(OWNER array[], int size)
{
	int x, y;
	bool swapped = true;

	for (y = 0; y < size && swapped; y++) // Traversal loop
	{
		swapped = false;
		for (x = 0; x < size - (y + 1); x++) // Comparison loop
		{
			// Compare the vehicle year values of two owner data records
			// If the first vehicle year value is greater, swap the owner data records
			{
				if (array[x].vehicle.year < array[x + 1].vehicle.year)
				{
					swap(array, x, x + 1);
					swapped = true;

				}
			
			}
		}
	}
}

/*
	Swaps the values between two positions within the owner data array.
	array[] - The array containing the owner data.
	pos1 - The first value in the array to swap.
	pos2 - The second value in the array to swap.
*/
void swap(OWNER array[], int pos1, int pos2)
{
	// Copy an owner value to a temporary position
	// Copy another value between the two positions
	// Copy the temporary value to its final position
	OWNER temp;

	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}
