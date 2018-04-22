// CSC134.0001 Cameron Alexander Lab 03 Program 01
// Program to Calculate surface area or volume of a given shape
// September 29th, 2012

#include <iostream>
#include <cmath>
using namespace std;

//function prototypes for each shape and volume
double sphere_volume(double);
double sphere_surface_area(double);
double cylinder_volume(double, double);
double cylinder_surface_area(double, double);
double cone_volume(double, double);
double cone_surface_area(double, double);

int main()
{
    //Variables used to store information
    char shape =' ';
    int type = 0;
    double radius = 0;
    double height = 0;
    double volume = 0;
    double volume1 = 0;
    double area = 0;
    
    while (shape != 'q')
{
    cout << "Select a Shape (1) sphere (2) cylinder (3) cone (q) quit: ";
    cin >> shape;
    
    //if statement to end program
    if(shape = 'q')
    {
     cout << "Good bye!" << endl;
     break;
     } 
     
    cout << "Select a Computation (1) volume (2) surface area: "; 
    cin >> type; 
    
    //if statements to determine which function to run based on input
    
    if(shape == '1' && type == 1)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    volume1 = sphere_volume(radius);
    cout << "Volume area of sphere is: " << volume1 << endl;
    }
    
    if (shape == '1' && type == 2)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    area = sphere_surface_area(radius);
    cout << "Surface area of sphere is: " << area << endl;
    }
    
    if (shape == '2' && type == 1)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    cout << "Please enter height: " ;
    cin >> height; 
    volume = cylinder_volume(radius,height);
    cout << "Volume area of cyclinder is: " << volume << endl;
    }
    
    if (shape == '2' && type == 2)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    cout << "Please enter height: " ;
    cin >> height;
    area = cylinder_surface_area(radius,height);
    cout << "Volume area of cyclinder is: " << area << endl;
    }
    
    if (shape == '3' && type == 1)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    cout << "Please enter height: " ;
    cin >> height; 
    volume = cone_volume(radius,height);
    cout << "Volume area of cone is: " << volume << endl;
    }
    
    if (shape == '3' && type == 2)
    {
    cout << "Please enter radius: " ;
    cin >> radius;
    cout << "Please enter height: " ;
    cin >> height;
    area = cone_surface_area(radius,height);
    cout << "Volume area of cone is: " << area << endl;
    }
}    
    
    
    system("pause");
    return 0;
   
}

//function to determine a volume of a sphere
double sphere_volume(double radius)
{
       double volume =(1.33333)*(3.14159)*pow(radius,3);
       
       return volume;
}

//function to determine a surface area of a sphere       
double sphere_surface_area(double radius)
{
       double area = ((4)*(3.14159)*pow(radius,2));
       
       return area;
}

//function to determine a volume of a cylinder       
double cylinder_volume(double radius, double height)
{
       double volume = ((3.14159)*pow(radius,2)*(height));
       
       return volume;
}

//function to determine a surface area of a cylinder
double cylinder_surface_area(double radius, double height)
{
       double area = ((2)*(3.14159)*pow(radius,2)) + ((2)*(3.14159)*(radius)*(height));
       
       return area;
}

//function to determine a volume of a cone
double cone_volume(double radius, double height)
{
       double volume = ((.33333)*(3.14159)*pow(radius,2)*(height));
       
       return volume;
}

//function to determine a surface area of a cone
double cone_surface_area(double radius, double height)
{
       double area = ((3.14159)*pow(radius,2)) + (3.14159 * radius)*sqrt((pow(radius,2) + pow(height,2)));
       
       return area;
}
