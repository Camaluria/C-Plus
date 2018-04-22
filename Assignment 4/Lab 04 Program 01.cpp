// CSC 134.0001 Cameron Alexander
// Lab 04 - Program 1

#include <iostream>
using namespace std;

int main()
{
    int value1 = 2000;
    int value2;

    // DECLARE the variable iPtr to be a pointer to an object of type int
    int *iPtr;
    // ASSIGN the address of variable value1 to pointer variable iPtr
    iPtr = &value1;
    // PRINT the value of the object pointed to by iPtr
    cout << "The value of the objected pointed to by iPtr is: " << *iPtr << endl;

    // ASSIGN the value of the object pointed to by iPtr to value2
    value2 = *iPtr;

    // PRINT the value of value2
    cout << "The value of value2 is: " << value2 << endl;

    // PRINT the address of value1
    cout << "the address of value1 is: " << &value1 << endl;

    // Print the address stored in iPtr
    cout << "the address of iPtr is: " << &*iPtr << endl;




system("pause");
return 0;
   
}
