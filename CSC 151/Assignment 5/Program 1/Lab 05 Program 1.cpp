// Lab 05 Program 1
// Main File Provided in Lab Assignment 5
//CSC 134.0001 November 17, 2012
//Cameron Alexander

#include "Rational.h"
#include "Rational.cpp" //Dev-C++ will not compile without me including this file as well
#include <iostream>
using namespace std;

int main()
{
   Rational c( 2, 6 ), d( 7, 8 ), x; // creates three rational objects 

   c.printRational(); // prints rational object c
   cout << " + ";
   d.printRational(); // prints rational object d				
   x = c.addition( d ); // adds object c and d; sets the value to x

   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x    
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " - ";
   d.printRational(); // prints rational object d
   x = c.subtraction( d ); // subtracts object c and d 
           
   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " x ";
   d.printRational(); // prints rational object d
   x = c.multiplication( d ); // multiplies object c and d
                            
   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " / ";
   d.printRational(); // prints rational object d	
   x = c.division( d ); // divides object c and d
                            
   cout << " = ";
   x.printRational(); // prints rational object x		
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << endl;
          system("pause");
   return 0;
} // end main
