///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: exer10_8.cpp
//
// Description:
//    Driver program for testing the IntegerSet class.  Instantiates
//    several IntegerSet objects and executes all the member functions
//    of the IntegerSet class.
//                                                                  
///////////////////////////////////////////////////////////////////////
// Lab 05 Program 2
// Driver Provided in Lab Assignment 5 
//Cameron Alexander 
//November 17, 2012
#include <iostream>
using namespace std;

#include "IntegerSet.h"
#include "Integerset.cpp" //Dev-C++ will not compile without me including this file as well
int main()
{
    // IntegerSet holds integers in the range 0..100
    const int maxInteger = 100;

    // Test default constructor --
    // Create an empty set s
    IntegerSet s;
    cout << "Initial empty set: " << endl;
    s.printSet();
    cout << endl;
     
    // Test insertElement function --
    // Insert powers of 5 into Integer set s
    for (int i = 0; i <= maxInteger; i += 5)
    {
        s.insertElement(i);
    }
    cout << "Inserted powers of 5: " << endl;
    s.printSet();
    cout << endl;

    // Test deleteElement Function -- 
    // Delete powers of 10 from IntegerSet s	
    for (int i = 0; i <= maxInteger; i+= 10)
    {
        s.deleteElement(i);
    }
    cout << "Deleted powers of 10: " << endl;
    s.printSet();
    cout << endl;

    // Create a set of even integers
    IntegerSet evenSet;
    for (int i = 0; i <= maxInteger; i+=2)
    {
        evenSet.insertElement(i);
    }
    cout << "Even Integers: " << endl;
    evenSet.printSet();
    cout << endl;

    // Create a set of odd integers
    IntegerSet oddSet;
    for (int i = 1; i <= maxInteger; i+=2)
    {
        oddSet.insertElement(i);
    }
    cout << "Odd Integers: " << endl;
    oddSet.printSet();
    cout << endl;

    // Test unionOfSets Function --
    // Print union of even and odd integers which
    // results in a set of all integers between 0..100
    s = evenSet.unionOfSets(oddSet);
    cout << "Union of Even and Odd Integers: " << endl;
    s.printSet();
    cout << endl;

    // Test intersectionOfSets Function --
    // Print intersection of even and odd integers which
    // results in an empty set
    s = evenSet.intersectionOfSets(oddSet);
    cout << "Intersection of Even and Odd Integers: " << endl;
    s.printSet();
    cout << endl;

    // Test isEqualTo Function --
    // Even integers should not be equal to odd integers.
    if (evenSet.isEqualTo(oddSet))
    {
        cout << "Even Integer Set is equal "
             << "to Odd Integer Set." << endl;
    }
    else
    {
        cout << "Even Integer Set is NOT equal "
             << "to Odd Integer Set." << endl;
    }

    // Test isEqualTo Function --
    // Set s, the intersection of even and odd integers,
    // should equal the empty set.
    IntegerSet emptySet;
    if (s.isEqualTo(emptySet))
    {
        cout << "Intersection of even and odd integers "
             << "is equal to the Empty Set." << endl;
    }
    else
    {
        cout << "Intersection of even and odd integers "
             << "is NOT equal to the Empty Set." << endl;
    }
    cout << endl;

    // Test constructor from array of integers --
    // Create a set of prime numbers between 0 to 100
    const int numPrimes = 25;
    int primes[numPrimes] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
                             31, 37, 41, 43, 47, 53, 59, 61, 67, 
                             71, 73, 79, 83, 89, 97};
    IntegerSet primeSet(primes, numPrimes);
    cout << "Prime Integers: " << endl;
    primeSet.printSet();
    cout << endl;

    return 0;
}
