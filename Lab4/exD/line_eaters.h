// line_eaters.h

// The line_eaters module contains functions that read an
// entire line from cin and then try to extract some data from
// the beginning of the input line.

#ifndef LINE_EATERS_H
#define LINE_EATERS_H

// The next declaration says "There is a class called Mystring".
// This allows the compiler to process the prototype for
// eat_line_keep_one_word without having seen the Mystring class
// definition. 
class Mystring;

char eat_line_keep_one_char();
// REQUIRES: User has been prompted for input.
// PROMISES:
//   An attempt is made to read a line from cin.
//   It is the caller's responsibilty to check the status of cin
//   after calling this function. 
//
//   If the attempt fails, the return value is junk and should
//   not be used.
//
//   If the attempt succeeds, the return value is either
//   the first non-whitespace char in the input line,
//   ' ' (the space character) if the input was all whitespace.

void eat_line_keep_one_int(int& the_int, int& success);
// REQUIRES: User has been prompted for input.
// PROMISES:
//   An attempt is made to read a line from cin.
//   It is the caller's responsibilty to check the status of cin
//   after calling this function. 
//
//   If the attempt fails, success == 0 and the_int is unchanged.
//
//   If the attempt succeeds, and there are chars at the beginning
//   of the input line that can be converted to an int, success == 1,
//   and that int is stored in the_int.  (Leading whitespace characters
//   are tolerated.)
//   
//   If the attempt succeeds, but conversion from the input line to
//   an integer value is impossible, success == 0 and the_int is
//   unchanged.  

void eat_line_keep_one_word(Mystring& word);
// REQUIRES: User has been prompted for input.
// PROMISES:
//   An attempt is made to read a line from cin.
//   It is the caller's responsibilty to check the status of cin
//   after calling this function. 
//
//   If the attempt fails, the_word is unchanged.
//
//   If the attempt succeeds, and the input line is nothing but
//   whitespace, word.length() == 0.
//
//   Otherwise, the "first word" in the input line is copied into
//   word.  The "first word" is obtained by skipping leading
//   whitespace, then copying non-whitespace chars until either
//   more whitespace or end-of-string is found.

void kill_the_program();
// PROMISES: 
//   Prints a message on cerr (the error output stream) explaining that
//   the program will be terminated because of an unexpected input
//   failure, then calls exit(1).

#endif
