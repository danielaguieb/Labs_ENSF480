/*  mystring.cpp */

#include <assert.h>
#include "mystring.h"
#include <string.h>
#include <iostream>
using namespace std;



Mystring::Mystring()
: lengthM(0), charsM(new char[1])
{
  charsM[0] = 0;
}

Mystring::Mystring(const char *s)
: lengthM(strlen(s))
{
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
}

Mystring::Mystring(const Mystring& source):
lengthM(source.lengthM), charsM(new char[source.lengthM+1])
{
  strcpy (charsM, source.charsM);
}

Mystring::~Mystring()
{
  delete [] charsM;
}

int Mystring::length() const
{
  return lengthM;
}

char Mystring::get_char(int pos) const
{
  assert(pos >= 0 && pos < length());
  return charsM[pos];
}

const char * Mystring::c_str() const
{
  return charsM;
}

void Mystring::set_char(int pos, char c)
{
  assert(pos >= 0 && pos < length());
  assert(c != '\0');
  charsM[pos] = c;
}

Mystring& Mystring::operator =(const Mystring& S)
{
	
  if(this == &S)
    return *this;
  delete [] charsM;
  lengthM=strlen(S.charsM);
  charsM=new char [lengthM+1];
  strcpy(charsM,S.charsM);
  return *this;
}


bool Mystring::operator != (const Mystring& s)const
{
	
  return (strcmp(charsM, s.charsM)!= 0);
}


bool Mystring::operator == (const Mystring& s)const
{
	
  return (strcmp(charsM, s.charsM)== 0);
}


bool Mystring::operator > (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)> 0);
}


bool Mystring::operator < (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)< 0);
}


void Mystring::append(const Mystring& s)
{
  lengthM += s.lengthM;
  char* temp = new char[lengthM+1];
	if(temp == NULL)
	{
		cerr << "\n cannot allocat memory for Mystring obj.";
		exit(1);
	}
	
	strcpy(temp, charsM);
	strcat (temp, s.charsM);
	delete []charsM;
	temp = charsM;
}

void Mystring::append(char c)
{
  if (c != '\0') {
    int old_length = lengthM;
    ++lengthM;
		char* temp = new char[lengthM+1];
		if(temp == NULL)
		{
			cerr << "\n cannot allocat memory for Mystring obj.";
			exit(1);
		}
		
		strcpy(temp, charsM);
		delete [] charsM;
		charsM = temp;
    charsM[old_length] = c;
    charsM[lengthM] = '\0';
  }
}


void Mystring::truncate(int new_length)
{
  
	// defend against nonsense argument
	if (new_length < 0)
    new_length = 0;
	
	
  if (new_length < lengthM) {
    lengthM = new_length;
		char* temp = new char[lengthM+1];
		if(temp == NULL)
		{
			cerr << "\n cannot allocat memory for Mystring obj.";
			exit(1);
		}
		
		int i;
		for(i=0; i< lengthM; i++)
			temp [i] = charsM[i];
		temp[i] = '\0';
	}
	else
		return;
}




ostream& operator << (ostream& os, const Mystring& rhs)
{
	os << rhs.charsM;
	return os;
}


