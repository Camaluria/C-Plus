// CSC 134 Lab 01 Program 2.cpp 
// Description: Program to create employee objects,  display object values and manipulate them
// Prgorammer: Cameron Alexander
// Date: September 01, 2012

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


int main(){
    
    // Declare two Employee objects
   Employee employee1( "Lisa", "Roberts", 54000 );
   Employee employee2( "Mark", "Stein", 48000 );

   // Display current Employee's names and salaries
   cout << "Current Employee Salaries: " << endl;
   cout << employee1.getfname() << "  " << employee1.getlname() << ": " << employee1.getsalary() << endl;
   cout << employee2.getfname() << "  " << employee2.getlname() << ": " << employee2.getsalary() << endl;
   
   // Increase each employee's salary by 10%
   employee1.setsalary(59400);
   employee2.setsalary(52800);

  // Display Employee's names and new salaries
   cout << "New Salaries after raise: " << endl;
   cout << employee1.getfname() << "  " << employee1.getlname() << ": " << employee1.getsalary() << endl;
   cout << employee2.getfname() << "  " << employee2.getlname() << ": " << employee2.getsalary() << endl;
   

   

system("Pause");
return 0;
}
