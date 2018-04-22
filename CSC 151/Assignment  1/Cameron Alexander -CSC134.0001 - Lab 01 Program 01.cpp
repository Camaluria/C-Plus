// CSC 134 Lab 01 Program 1.cpp 
// Description: Program to Determine Final Class Grade
// Prgorammer: Cameron Alexander
// Date: September 01, 2012

#include "iostream"
using namespace std;

 int main()
{
	//Variables used to store grades
	int midterm;
	int q1, q2, q3; 
	int lab1, lab2, lab3, lab4;
	int final;
	int small; 
	double average;

	//Numerical Inputs From User
	cout << "Enter Midterm Grade: ";
	cin >> midterm;
	cout << "Enter Your Final Grade: ";
	cin >> final;
	cout << "Enter Your 3 Quiz Grades: ";
	cin >> q1 >> q2 >>	q3;
	cout << "Enter Your 4 Lab Grades: ";
	cin >> lab1 >> lab2 >> lab3 >> lab4;
	

	small = q1; //Set small to q1 to be used for comparisons 

	//if statement to find the lowest quiz grade
	if(small > q2)
	{
		small = q2;
	}
	else if(small > q3)
	{
		small = q3;
	}
	

	// Calculate average based on percentages given
	// Also subtracts the lowest grade from quizes
	average = (midterm * .2) + (final * .2) + (((lab1 + lab2 + lab3 + lab4)/4) * .5) + (((q1 + q2 + q3 - small)/2) * .1);

	// Display Class Average
	cout << "Final Class Grade: " << average << endl; 


	system("pause");
	return 0;
}

