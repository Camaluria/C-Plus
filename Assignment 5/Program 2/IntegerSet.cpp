// Lab 05 Program 2
// Class Functions for IntegerSet
//Cameron Alexander 
//November 17, 2012

#include "IntegerSet.h"

class IntegerSet
{
      
IntegerSet::IntegerSet()
{
emptyset();                        
}

void IntegerSet::emptySet(void)
{
      for (int a = 0; a < 101; a++)
      set[a]= 0;
}  
      
void IntegerSet::insertElement(int a)
{
  set[a] = 1;    
      
}
      
void IntegerSet::deleteElement(int a)
{
   set[a] = 0;
     
}
        
bool IntegerSet::isEqualTo(const IntegerSet &r)
{
      for int a = 0; a < 101; a++)
      if (set[a] != r.set[a])
      return false;

return true;
      
}
          
IntegerSet IntegerSet::intersectionofSets(const IntegerSet &r)
{
      IntegerSet temp; 
      for int a = 0; a < 101; a++)
      if (set[a] == 1 && r.set[a] == 1)
      temp.set[a] = 1;

return temp;
      
}   

IntegerSet IntegerSet::unionnofSets(const IntegerSet &r)
{
      IntegerSet temp; 
      for int a = 0; a < 101; a++)
      if (set[a] == 1 || r.set[a] == 1)
      temp.set[a] = 1;

return temp;
      
}     

void IntegerSet::printSet(void)
{
  cout << "ok";
     
}
      
}

