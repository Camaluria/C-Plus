// CSC 134 Lab 02 Program 1.cpp 
// Description: Program to Determine Account Balance and If Account is Overdrawn
// Prgorammer: Cameron Alexander
// Date: September 14, 2012

#include "iostream"
using namespace std;

int main()
{
    
    //Variables used to store account balance
    int accnumber; 
    double begbalance = 0.00;
    double accbalance = 0.00;
    double charges = 0.00;
    double credits = 0.00;
    double limit = 0.00;
    
    //Intialization Phase
    cout << "Enter Account Number (Enter -1 to Quit): "; 
    cin >> accnumber;
    
// While loop to find account balances until -1 is entered
while(accnumber != -1)
{
   
   cout << "Enter Beginnning Balance: ";
   cin >> begbalance;
   cout << "Enter Total Charges: ";
   cin  >> charges;
   cout << "Enter Total Credits: ";
   cin >> credits;
   cout << "Enter Credit Limit: ";
   cin >> limit;
   cout << "\n"; // create new line for spacing
   
   accbalance = (begbalance - charges + credits); // find total account balance
    
   //If statement to find if account balance is lower than credit limit
   if( accbalance > limit)
{
   cout << "Account Number: " << accnumber << endl;
   cout << "New Balance is: " << accbalance << endl;
}
 //else statement to let user know they have exceeded their credit limit
 else
{ 
   cout << "Account Number: " << accnumber << endl;
   cout << "New Balance is: " << accbalance << endl;
   cout << "Credit Limit: " << limit << endl;

   cout << "Credit Limit Exceeded." << endl << "\n" ;
}
   
}//end while


	system("pause");
	return 0;
}   
   
   
   
   
   
