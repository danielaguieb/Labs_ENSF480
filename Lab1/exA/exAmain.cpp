// exAmain.cpp
// ENSF 480 Lab 1 -  FALL 2018 - Exercise A
// Author - M. Moussavi

#include <iostream>
using namespace std;
#include "mystring.h"

int main(void)
{
  Mystring *ar[3];
  // at this point, an array of Mystring pointers is created

  Mystring c = 3;
  // at this point, a string of lengthM == 0 is created but it can
  // grow up to 3 (like 2 chars and \0)

  ar[2] = &c;
  // at this point, ar[2] points to the address of c

  ar[1] = ar[0] = NULL;
  // at this point, ar[0] and ar[1] point to null
    
  // A BLOCK OF CODE BEGINS HERE
  {
    Mystring x[2];
    // at this point, an array of mystrings 'x' is initialized
    // with the default constructor which sets the strings to 
    // a size of 1, which is only going to be \0

 
    x[0].set_str("ENEL");
    // at this point, x[0]'s contents are destroyed, and replaced with
    // "ENEL"

    x[1].set_str("0");
    // at this point, similar to last thing, but with 0 in x[1]

    Mystring* z = new Mystring("4");
    // at this point, a Mystring pointer of z is made and it points to a
    // Mystring object that holds the text "4"
    // so, a constructor with a char argument should be called
      
    x[0].append(*z).append(x[1]);
    // here, x[0] should append what z points to which should be 
    // appended by x[1]
    // so it does technically goes left to right, the functions COMPLETE
    // right to left
  
    Mystring mars = x[0];
    // this is the assingment operator, so as long as mars and x[0] isn't the same
    // which they aren't, then this just copies it to here

    x[1] = x[0];
    // same thing as above, and should work
    
    Mystring jupiter("White");
    // this should be a constructor with a char* argument

    ar[0] = new Mystring ("Yellow");
    // now ar[0] should be pointing to a new string that's filled with "Yellow"

  } // BLOCK ENDS HERE

  c.set_str("A");
  // c's contents are destroyed, the char array is changed, and the length count
  // changes to 1

  delete  ar [0];
  // the pointer is destroyed, however I'm not sure what happened to "Yellow"
 
  Mystring d = "Green";
  // new dude shows up but the party is already over
  
  cout << "\nProgram terminated successfully." <<endl;
  return 0;
}

