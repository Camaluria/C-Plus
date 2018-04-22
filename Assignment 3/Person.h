//Person.h
//Definition of class Person that uses an array to store ages

#include <string>
using namespace std;

//Person class definition
class Person
{
      public:
      static const int ages = 1;
      //Constructor initializes name and age array
      Person(string, const int []);
      void setName(string)); //function to set course name
      string getName(); //function to retrieve course name
      
      private:
      string name;
      int age[ages];
}
