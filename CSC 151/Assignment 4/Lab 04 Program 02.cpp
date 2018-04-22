// CSC 134.0001 Cameron Alexander
// Lab 04 Program 02

#include <iostream>
using namespace std;

//function prototypes for string manipulation
int stringLength1( char *s ); //Find a string length using array notation
int stringLength2(char *s ); //Find a string length using pointer notation
char *stringCopy1( char *s1, const char *s2 );//Copy a string using array notation
char *stringCopy2( char *s1, const char *s3 ); //Copy string using pointer notation
char *stringCat1( char *s1, const char *s2 ); //Concatenate a string using array notation
char *stringCat2( char *s1, const char *s3 ); //Concatenate string using pointer notation
int stringComp1(char *s1, const char *s3 ); //Compare strings using array notation
int stringComp2(char *s1, const char *s3 ); //Compare srings using pointer notation 
int main()
{
  
   char s1[ 100 ];
   char* s2 = "education";
   char* s3 = "school";

        cout << "stringLength(" << s2 << "): "
        << stringLength1( s2 ) << endl;
        
        cout << "stringLength(" << s3 << "): "
        << stringLength2( s3 ) << endl;

        cout << "stringCopy1(s1, " << s2 << "): "
        << stringCopy1( s1, s2 ) << endl;

        cout << "stringCopy2(s1, " << s3 << "): "
        << stringCopy2( s1, s3 ) << endl;

        cout << "stringCat1(s1, " << s2 << "): "
        << stringCat1( s1, s2 ) << endl;
        
        cout << "stringCat2(s1, " << s3 << "): "
        << stringCat2( s1, s3 ) << endl;

    system("pause");
    return 0;
}

//Array Subscript Notation to find string length
int stringLength1( char *s ) 
{
  int count = 0; //incrementer variable
  char *ptr = s;
  
  //while loop to count each element up to escape
  while(ptr[count] != '\0')
  {
       ptr[count++];
  }
  
    return count;
    
}

// Pointer Subscript notation to find string length
int stringLength2(char *s ) 
{
  int count = 0; 
  char *ptr = s;
  
  //while loop to count each element up to escape
  while(*(ptr + count) != '\0')
  {
       *(ptr + count++);
  }
    
    return count;     
}

//Array Subscript Notation to copy a constant array to another
char *stringCopy1( char *s1, const char *s2 ) 
{
    
    //for loop to copy each element from s2 into s1
    for(int i=0; s2[i]!='\0'; i++)
    {
          s1[i]=s2[i];
    }     
    return s1; 
    
}

//Pointer Subscript Notation to copy a constant array to another
char *stringCopy2( char *s1, const char *s2 ) 
{
   
    int count = 0;
    char *aptr = s1;
    
    //Clear string array s1 before reuse so future results macth expected output
      while ( *(aptr + count) != '\0')
    {
     *(aptr + count) = NULL;
     count++;
     }
     
     //For loop to replace each empty char element one by one with given element from s2
    for(int i=0; *(s2 + i)!='\0'; i++)
        *(s1 + i)= *(s2 + i);
    
    return s1; 
}

//Array Subscript Notation to append a constant array to another
char *stringCat1( char *s1, const char *s2 ) 
{

     int temp = 0; // variable to hold current length of string 1

      //for loop to find current length of string 1 up to escape 
      for(int i=0; s1[i]!='\0'; i++)
      {
      temp = i;
      }
      temp++;
      
      //for loop to start at end of string 1 and copy the elements of string 2 into it until string 2's escape
      for(int i=0; s2[i]!='\0'; i++)
      {
         s1[temp] = s2[i];
         temp++;
      }
      
      s1[temp] = '\0'; //terminate string 1 after string 2 is appended 
 
      return s1;
    
}

//Pointer Subscript Notation to append a constant array to another
char *stringCat2( char *s1, const char *s2 ) 
{

     int temp = 0; // variable to hold current length of string 1

    //for loop to find current length of string 1 up to escape 
    for(int i=0; *(s1 + i) !='\0'; i++)
    {  
      temp = i;
    }
     temp++;
  
  //for loop to start at end of string 1 and copy the elements of string 2 into it until string 2's escape
  for(int i=0; *(s2 + i)!='\0'; i++)
      {
         *(s1 + temp) = *(s2 + i);
         temp++;
      }
      
      *(s1 + temp) = '\0'; //terminate string 1 after string 2 is appended 
    
   return s1;
    
}

int *stringComp1( char *s1, const char *s2 ) 
{
   for(int i = 0; s1[i] != '\0'; i++)
   {
      if(s1[i] == s2[i])
      {
        cout << "Strings Match" << endl;
        return 1;
      }
      else
      {
        cout << "Not Matching Strings" << endl;
        return 0;
      }
      
           
}

int *stringComp2( char *s1, const char *s2 ) 
{
  
   for(int i = 0; *(s1 + i) != '\0'; i++)
   {
      if(*(s1 + i) == *(s2 + i))
      {
        cout << "Strings Match" << endl;
        return 1;
      }
      else
      {
        cout << "Not Matching Strings" << endl;
        return 0;
      }
     
}


