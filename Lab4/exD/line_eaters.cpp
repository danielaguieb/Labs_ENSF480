// line_eaters.cpp

#include <iostream>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include "mystring.h"

#include "line_eaters.h"

char eat_line_keep_one_char()
{
  char c, result;
  do {
    cin.get(c);
  } while(cin && isspace(c) && c != '\n');
  
  if (cin && c != '\n') {
    result = c;
    while(cin && c != '\n')
      cin.get(c);
  }
  else
    result = ' ';

  return result;
}

void eat_line_keep_one_int(int& the_int, int& success)
{
  string line;
  getline(cin, line);
  if (!cin)
    success = 0;
  else {
    char *endptr;
    errno = 0;     // errno is a global variable used for error checks.
    long int li = strtol(line.c_str(), &endptr, 10);
    success =
      (endptr != line.c_str())
      && (errno != ERANGE)
      && (li >= INT_MIN && li <= INT_MAX);
    if (success)
      the_int = (int) li;
  }
}

void eat_line_keep_one_word(Mystring& word)
{
  string line;
  getline(cin, line);
  if (!cin)
    return;

  word.truncate(0);
  signed int i = 0;
  while (i < (signed) line.length() && (signed)isspace(line[i]))
    i++;
  while (i < (signed) line.length() && !(signed)isspace(line[i])) {
    word.append(line[i]);
    i++;
  }
}

void kill_the_program()
{
  cerr << "\n\nError: Unexpected failure reading terminal input.\n";
  cerr << "Program terminated.\n\n";
  exit(1);
}
