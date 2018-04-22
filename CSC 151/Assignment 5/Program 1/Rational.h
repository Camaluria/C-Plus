// Lab 05 Program 1
// Rational Header File
//CSC 134.0001 November 17, 2012
//Cameron Alexander

#ifndef Rational_H // preprocessor wrapper to prevent multiple inclustions of header
#define Rational_H

class Rational 
{
      public:
             Rational( int = 0, int = 0); //constructor
             Rational addition(const Rational &);
             Rational subtraction(const Rational &);
             Rational multiplication (const Rational &);
             Rational division ( Rational &);
             void printRational(void);
             void printRationalAsDouble(void);
      private:
              int numerator;
              int denominator;
              void reduction(void); // reduction function provided in lab
              };       
#endif
