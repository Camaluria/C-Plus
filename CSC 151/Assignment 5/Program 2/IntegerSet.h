// Lab 05 Program 2
// Header file for IntegerSet
//Cameron Alexander 
//November 17, 2012

#ifndef IntegerSet_H
#define IntegerSet_H

class IntegerSet 
{
       public:
       IntegerSet( );
       IntegerSet unionOfSets( const IntegerSet& );
       IntegerSet intersectionOfSets( const IntegerSet& );
       void emptySet( void );
       void insertElement( int );
       void deleteElement( int );
       void printSet( void ) ;
       bool isEqualTo( const IntegerSet& ) ;

       private:
       int set[ 101 ]; 
}
#endif
