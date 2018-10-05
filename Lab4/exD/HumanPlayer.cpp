// HumanPlayer.cpp
// HumanPlayer class implementation

#include "HumanPlayer.h"
#include "Board.h"

#include <assert.h>
#include <iostream>
using namespace std;
#include "line_eaters.h"
#include "string.h"

HumanPlayer::HumanPlayer(const Mystring& nameA, 
                           char mark, 
                           const Board *boardA)
  : Player(nameA, mark, boardA)
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::make_move(int& row, int& col)
{
  int good_row_read;
  cout << name() << ", what row should your next "
       << mark() << " be placed in?    ";
  eat_line_keep_one_int(row, good_row_read);
  int good_col_read;
  cout << name() << ", what column should your next "
       << mark() << " be placed in? ";
  eat_line_keep_one_int(col, good_col_read);
  if (cin.fail()) kill_the_program();

  int acceptable_input = 1;
  while(1) {
    if (!good_row_read || !good_col_read) {
      cout << "Sorry, " << name() << ", I couldn't understand your input.\n";
      acceptable_input = 0;
    }
    else if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
      cout << "Sorry, " << name() 
           << ", but there is no square with coordinates (row=" 
           << row << ", col=" << col << ").\n";
      acceptable_input = 0;
    }
    else if(boardM->get_mark(row, col) != SPACE_CHAR) {
      cout << "Sorry, " << name() 
           << ", but the square with coordinates (row=" 
           << row << ", col=" << col << ") is marked.\n";
      acceptable_input = 0;
    }
    if (acceptable_input)
      break;

    cout << "Please enter the row again:    ";
    eat_line_keep_one_int(row, good_row_read);
    cout << "Please enter the column again: ";
    eat_line_keep_one_int(col, good_col_read);
    if (cin.fail()) kill_the_program();
    acceptable_input = 1;
  }
}

