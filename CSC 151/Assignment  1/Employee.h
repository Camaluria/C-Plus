// Employee.h 
// Description: Header file to use with Lab 01 Program 02.cpp to create Employee objects
// Prgorammer: Cameron Alexander
// Date: September 01, 2012

#include <iostream>
#include <string>
#include "Employee.cpp"
using namespace std;
//Employee class definition
class Employee
{
      public:
        //Constructor intializes Employee with strings supplied
        Employee(string, string, int);
        //Funtion to set first name          
        void setfname(string)
        //Funtion to retrieve first name     
        string getfname()
        //Funtion to set last name
        void setlname(string)
        //Function to retrieve last name
        string getlname()
        //Funtion to set salary
        void setsalary(int newsalary)
        //Function to retrieve salary
        int getsalary()
      //Variables used in Gradebook Constructor  
      private: 
        string fname;
        string lname;
        int salary;
};
