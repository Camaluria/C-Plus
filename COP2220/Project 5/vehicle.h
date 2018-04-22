/*
	Author: Ima C Programmer
	Course: COP 2220
	Project#: 5
	Title: vehicle.h
	Due Date: --/--/----

	Provides data structure for storing vehicle data.
*/
#pragma once

#define MAKE_SIZE 10
#define MODEL_SIZE 11

// Defines a data structure for organizing vehicle data
typedef struct
{
	char make[MAKE_SIZE];
	int mileage;
	char model[MODEL_SIZE];
	int year;
} VEHICLE; // This is a user-defined data type