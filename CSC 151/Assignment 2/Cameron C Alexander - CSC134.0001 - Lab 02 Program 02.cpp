// CSC 134 Lab 02 Program 2.cpp 
// Description: Program to Calculate Total Sales
// Prgorammer: Cameron Alexander
// Date: September 14, 2012

#include "iostream"
using namespace std;

int main()
{
    //Variables to store user info
    int pnumber;
    double cost;
    int quantity;
    double total;
    
    //Variables to use as counters for products 1-5 as A - E in switch statement
    //Intialized to 0  in case a product is not used
    int acounter = 0;
    int bcounter = 0;
    int ccounter = 0;
    int dcounter = 0;
    int ecounter = 0;
    
    //Variable to tally total per product.
    //Intialized to 0 in case a product is not used
    double atotal = 0.00;
    double btotal = 0.00;
    double ctotal = 0.00;
    double dtotal = 0.00;
    double etotal = 0.00;
    

//While statement to get product numbers and assess charges
while(pnumber != -1)
{
       //Switch Statement to charge each product number and increase the counter
      //Intialization Phase
cout << "Enter Product Number (Enter -1 to stop): ";
cin >> pnumber; 


       switch(pnumber)
       {
           case 1:
           cout << "Enter Quantity Sold: ";  
           cin >> quantity;

           acounter = acounter + quantity;
          
           break;
           
           case 2:
           cout << "Enter Quantity Sold: ";  
           cin >> quantity;
           
           bcounter = bcounter + quantity;
           
           break;
           
           case 3:
           cout << "Enter Quantity Sold: ";
           cin >> quantity;
           
           ccounter = ccounter + quantity;
           break;
           
           case 4:
           cout << "Enter Quantity Sold: ";  
           cin >> quantity;
           
           dcounter = dcounter + quantity;
           break;
           
           case 5:
           cout << "Enter Quantity Sold: ";
           cin >> quantity;
           
           
           ecounter = ecounter + quantity;
           break;
           
          
           
           } // End Switch
} // End While

//Calculate Each Product Total and Final Total
atotal = acounter * 2.98;
btotal = bcounter * 4.50;
ctotal = ccounter * 9.98;
dtotal = dcounter * 4.49;
etotal = ecounter * 6.87;

total = (atotal + btotal + ctotal + dtotal + etotal);

//Display Total per Product and Total Amount

cout << "Product 1: " << atotal << endl;
cout << "Product 2: " << btotal << endl;
cout << "Product 3: " << ctotal << endl;
cout << "Product 4: " << dtotal << endl;
cout << "Product 5: " << etotal << endl;
cout << "Total: " << total << endl;



	system("pause");
	return 0;
}




           
