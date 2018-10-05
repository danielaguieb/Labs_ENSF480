// Board.cpp
//Board.cpp
#include "Board.h"

#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;

Board::Board()
  : mark_countM(0)
{
  for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++)
      squareM[i][j] = SPACE_CHAR;
}

char Board::get_mark(int row, int col) const
{
  assert(0 <= row && row < BOARD_SIZE);
  assert(0 <= col && col < BOARD_SIZE);
  return squareM[row][col];
}

int Board::is_full() const
{
  return mark_countM == BOARD_SIZE * BOARD_SIZE;
}

int Board::x_wins() const
{
  return check_winner(LETTER_X);
}

int Board::o_wins() const
{
  return check_winner(LETTER_O);
}

void Board::display() const
{
  write_column_headers();
  write_mostly_hyphens();
  for (int row = 0; row < BOARD_SIZE; row++) {
    write_mostly_spaces();
    cout << "    row" << setw(2) << row << ' ';
    for (int col = 0; col < BOARD_SIZE; col++)
      cout << "|  " << get_mark(row, col) << "  ";
    cout << "|\n";
    write_mostly_spaces();
    write_mostly_hyphens();
  }
}

void Board::put_mark(int row, int col, char mark)
{
  assert(0 <= row && row < BOARD_SIZE);
  assert(0 <= col && col < BOARD_SIZE);
  assert(get_mark(row, col) == SPACE_CHAR);
  assert(mark == LETTER_X || mark == LETTER_O);
  assert(!x_wins() && !o_wins());
  squareM[row][col] = mark;
  mark_countM++;
}

void Board::clear()
{
  for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++)
      squareM[i][j] = SPACE_CHAR;
  mark_countM = 0;
}

int Board::check_winner(char mark) const
{
  int row, col;
  int result = 0;
  
  // Look for a row filled with mark.
  for (row = 0; !result && row < BOARD_SIZE; row++) {
    int row_result = 1;
    for (col = 0; row_result && col < BOARD_SIZE; col++)
      if (squareM[row][col] != mark)
        row_result = 0;
    if (row_result)
      result = 1;
  }

  // Look for a column filled with mark.
  for (col = 0; !result && col < BOARD_SIZE; col++) {
    int col_result = 1;
    for (row = 0; col_result && row < BOARD_SIZE; row++)
      if (squareM[row][col] != mark)
        col_result = 0;
    if (col_result)
      result = 1;
  }

  // Look for a diagonal filled with mark.
  if (!result) {
    int diag1_result = 1;
    for (row = 0; diag1_result && row < BOARD_SIZE; row++)
      if (squareM[row][row] != mark)
        diag1_result = 0;
    if (diag1_result)
      result = 1;
  }
  if (!result) {
    int diag2_result = 1;
    for (row = 0; diag2_result && row < BOARD_SIZE; row++)
      if (squareM[row][BOARD_SIZE - 1 - row] != mark)
        diag2_result = 0;
    if (diag2_result)
      result = 1;
  }
  return result;
}

void Board::write_column_headers() const
{
  cout << "          ";
  for (int j = 0; j < BOARD_SIZE; j++)
    cout << "|col" << setw(2) << j;
  cout << "|\n";
}

void Board::write_mostly_hyphens() const
{
  cout << "          ";
  for (int j = 0; j < BOARD_SIZE; j++)
    cout << "+-----";
  cout << "+\n";
}

void Board::write_mostly_spaces() const
{
  cout << "          ";
  for (int j = 0; j < BOARD_SIZE; j++)
    cout << "|     ";
  cout << "|\n";
}
