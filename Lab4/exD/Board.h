// Board.h
// Board class interface

#ifndef BOARD_H
#define BOARD_H

#include "xo_constants.h"

class Board {
public:
  Board();

  char get_mark(int row, int col) const;
  // REQUIRES:
  //    0 <= row && row < BOARD_SIZE
  //    0 <= col && col < BOARD_SIZE
  // PROMISES:
  //    Return value is one of LETTER_X, LETTER_O, SPACE_CHAR

  int is_full() const;
  // PROMISES: 
  //   Return value is 1 if no blank squares are left, 0 otherwise.

  int x_wins() const;
  // PROMISES: 
  //   Return value is 1 if the X player has won, 0 otherwise.

  int o_wins() const;
  // PROMISES: 
  //   Return value is 1 if the O player has won, 0 otherwise.

  void display() const;

  void put_mark(int row, int col, char mark);
  // Put an X or an O in a square.
  // REQUIRES: 
  //    0 <= row && row < BOARD_SIZE
  //    0 <= col && col < BOARD_SIZE
  //    get_mark(row, col) == SPACE_CHAR
  //    !x_wins() && !o_wins()
  //    mark == LETTER_X || mark == LETTER_O
  // PROMISES:
  //    get_mark(row, col) == mark
  //    move_count() is increased by one.

  void clear();
  // PROMISES: All squares get the value of SPACE_CHAR.

private:
  char squareM[BOARD_SIZE][BOARD_SIZE];
  int mark_countM;

  // Helper for x_wins and o_wins ...
  int check_winner(char mark) const;

  // Helpers for display ...
  void write_column_headers() const;
  void write_mostly_hyphens() const;
  void write_mostly_spaces() const;
};

#endif
