/*
	Author: Ima C Programmer
	Course: COP 2220
	Project#: 5
	Title: owner.h
	Due Date: --/--/----

	Provides data structure for storing owner data.
*/
#pragma once

#include "vehicle.h" // Adds user-defined data structure to the program

#define ADDRESS_SIZE 27
#define CITY_SIZE 14
#define FIRST_NAME_SIZE 8
#define LAST_NAME_SIZE 11
#define PHONE_SIZE 14
#define STATE_SIZE 3
#define ZIP_SIZE 6

// Defines a data structure for organizing owner data
typedef struct
{
	char address[ADDRESS_SIZE];
	char city[CITY_SIZE];
	char firstName[FIRST_NAME_SIZE];
	char lastName[LAST_NAME_SIZE];
	char phone[PHONE_SIZE];
	char state[STATE_SIZE];
	VEHICLE vehicle;
	char zip[ZIP_SIZE];
} OWNER; // This is a user-defined data type