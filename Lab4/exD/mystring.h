/* mystring.h */


#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class Mystring {
	friend ostream& operator << (ostream& os, const Mystring& rhs);
	
public:
  Mystring();
  // PROMISES: Empty string object is created.
	
  Mystring(const char *s);
  // PROMISES: s points to first char of a built-in string.
  // REQUIRES: Mystring object is created by copying chars from s.
	
  Mystring(const Mystring& source);
	
  ~Mystring();
	
  int length() const;
  // PROMISES: Return value is number of chars in charsM.
	
  char get_char(int pos) const;
  // REQUIRES: pos >= 0 && pos < length()
  // PROMISES:
  // Return value is char at position pos.
  // (The first char in the charsM is at position 0.)
	
  const char * c_str() const;
  // PROMISES:
  //   Return value points to first char in built-in string
  //   containing the chars of the string object.
	
  void set_char(int pos, char c);
  // REQUIRES: pos >= 0 && pos < length(), c != '\0'
  // PROMISES: Character at position pos is set equal to c.
	
  Mystring& operator =(const Mystring& s);
	
  bool operator > (const Mystring& s)const;
  // REQUIRES: s refers to an object of class Mystring
  // PROMISES: retruns true if charsM is greater than s.charsM.
	
  bool operator < (const Mystring& s)const;
  // REQUIRES: s refers to an object of class Mystring
  // PROMISES: retruns true if charsM is less than s.charsM.
	
  bool operator == (const Mystring& s)const;
  // REQUIRES: s refers to an object of class Mystring
  // PROMISES: retruns true if charsM is equal s.charsM.
	
  bool operator != (const Mystring& s)const;
  // REQUIRES: s refers to an object of class Mystring
  // PROMISES: retruns true if charsM is not equal s.charsM.
	
	void append(const Mystring& s);
	void append(char c);
	void truncate(int new_length);
	
private:
  int lengthM;
  char *charsM;

};
#endif









