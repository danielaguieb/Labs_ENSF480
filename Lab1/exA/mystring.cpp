//  mystring.cpp
// ENSF 480 Lab 1 - FALL 2018 - Exercise A
// Author - M. Moussavi

#include "mystring.h"
#include <string.h>
#include <iostream>
using namespace std;

Mystring::Mystring()
{ 
  charsM = new char[1];
  charsM[0] = '\0';
  lengthM = 0;
  cout << "\ndefault constructor is called. ";
}


// a constructor that creates a char array that has the same length 
// as the argument and same contents
Mystring::Mystring(const char *s)
  : lengthM((int)strlen(s))
{
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
  cout << "\nconstructor with char* argument is called. ";
}


// a  constructor that creates an empty char array that has length of n
Mystring::Mystring(int n): lengthM(0), charsM(new char[n])          
{
    charsM[0] = '\0';
	cout << "\nconstructor with int argument is called. ";
    
    // cout <<"\nif this is the first time you're seeing this, POINT ONE"; 
    // POINT ONE
}


// a copy constructor
Mystring::Mystring(const Mystring& source):
  lengthM(source.lengthM), charsM(new char[source.lengthM+1])
{
    strcpy (charsM, source.charsM);
	cout << "\ncopy constructor is called. ";
}


// destructor
Mystring::~Mystring()
{
    delete [] charsM;
	cout << "\ndestructor is called. ";
}

// getter for length
int Mystring::length() const
{
  return lengthM;
}

// return char at pos
char Mystring::get_char(int pos) const
{
  if(pos < 0 && pos >= length()){
    cerr << "\nERROR: get_char: the position is out of boundary."; 
  }

  return charsM[pos];
}

// returns the string contents as a pointer to a char array
const char * Mystring::c_str() const
{
  return charsM;
}

// set char at pos to c
void Mystring::set_char(int pos, char c)
{
  if(pos < 0 && pos >= length()){
    cerr << "\nset_char: the position is out of boundary."
	 << " Nothing was changed.";
    return;
  } 

  // don't let users replace something with a '\0'
  if (c != '\0'){
    cerr << "\nset_char: char c is empty."
	 << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

// make sure that this isn't copying itself,
// then deletes its chars, then copies what's inside
Mystring& Mystring::operator =(const Mystring& S)
{
  if(this == &S)
    return *this;
  delete [] charsM;
  lengthM = (int)strlen(S.charsM);
  charsM = new char [lengthM+1];
  strcpy(charsM,S.charsM);

  cout << "\nassignment operator called. ";
  return *this;
}

// adds onto the string 
Mystring& Mystring::append(const Mystring other)
{
  
  char *tmp = new char [lengthM + other.lengthM + 1];
  lengthM += other.lengthM;
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);
  delete []charsM;
  // deletes the original replaces it with the concatenated one
  charsM = tmp;
   
  // POINT TWO
    
  return *this;
}

 void Mystring::set_str(const char* s)
{
    delete []charsM;
    lengthM = (int)strlen(s);
    charsM=new char[lengthM+1];
    strcpy(charsM, s);
}

int Mystring::isNotEqual (const Mystring& s)const
{

  return (strcmp(charsM, s.charsM)!= 0);
}

int Mystring::isEqual (const Mystring& s)const
{

  return (strcmp(charsM, s.charsM)== 0);
}

int Mystring::isGreater (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)> 0);
}

int Mystring::isLessThan (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)< 0);
}













