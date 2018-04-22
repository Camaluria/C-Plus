// Lab 05 Program 1
//Rational Class Functions
//CSC 134.0001 November 17, 2012
//Cameron Alexander

#include "Rational.h"
#include <iostream>
using namespace std;

//default constructor
Rational::Rational(int a, int b)
{
     numerator = a;
     denominator = b;
}

//Function adds two fractions together and uses reduction function
Rational Rational::addition(const Rational &a)
{
         Rational e; //Rational class to store results
         
         e.numerator = a.numerator * denominator;
         e.numerator += a.denominator * numerator;
         e.denominator = a.denominator * denominator;
         e.reduction();
         
         return e;
}
//Function subtracts two fractions together and uses reduction function         
Rational Rational::subtraction(const Rational &s)
{
         Rational e;  //Rational class to store results
         
         e.numerator = s.denominator * numerator;
         e.numerator -= denominator * s.numerator;
         e.denominator = s.denominator * denominator;
         e.reduction();
         
         return e;
}
//Function multiplies two fractions together and uses reduction function
Rational Rational::multiplication(const Rational &m)
{
         Rational e;  //Rational class to store results
         
         e.numerator = m.numerator * numerator;
         e.denominator = m.denominator * denominator;
         e.reduction();
         
         return e;
}

//Function divides two fractions together and uses reduction function
Rational Rational::division( Rational &i)
{
         Rational e;  //Rational class to store results
         
         e.numerator = i.numerator * numerator;
         e.denominator = denominator * i.denominator;
         e.reduction();
         
         return e;
}

//Function prints out fraction
void Rational::printRational(void)
{
     cout << numerator << "/" << denominator;
}

//Function prints out fraction as double
void Rational::printRationalAsDouble(void)
{
     cout << static_cast<double>(numerator)/denominator; //changes type of numerator to Double
}

//function provided by lab assignment to reduce fractions
void Rational::reduction()
{
   int largest; 
   largest = numerator > denominator ? numerator : denominator;

   int gcd = 0; // greatest common divisor

   for ( int loop = 2; loop <= largest; loop++ )

       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   if (gcd != 0) 
   {
      numerator /= gcd;
      denominator /= gcd;
   } // end if 
} // end function reduction
