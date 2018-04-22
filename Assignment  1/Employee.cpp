// Employee.cpp
// Description: Class file to use with Employee.h to create Employee objects
// Prgorammer: Cameron Alexander
// Date: September 01, 2012

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//Employee class definition

      //Constructor intializes Employee with strings supplied
        Employee::Employee(string fname, string lname, int salary)
        {
        // call set functions to initalize Employee
              setfname (fname);
              setlname (lname);
              setsalary (salary);
        }
    // end Employee Constructor
    
    //Funtion to set first name          
        void Employee::setfname(string newfname)
        {
             fname = newfname;
        }
        //Funtion to retrieve first name     
        string Employee::getfname()
        {
               return fname;
        }
        //Funtion to set last name
        void Employee::setlname(string newlname)
        {
             lname = newlname;
        }
        //Function to retrieve last name
        string Employee::getlname()
        {
               return lname;
        }
        //Funtion to set salary
        void Employee::setsalary(int newsalary)
        {
             salary = newsalary;
        }
        //Function to retrieve salary
        int Employee::getsalary()
        {
            return salary;
        } 
