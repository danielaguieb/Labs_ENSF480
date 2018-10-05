// BlockingPlayer.cpp

#include "BlockingPlayer.h"
#include "Board.h"

#include <assert.h>
#include "distribs.h"
#include <vector>
//#include <string>
using namespace std;

BlockingPlayer::BlockingPlayer(const Mystring& nameA,
                           char mark, 
                           const Board *boardA)
  : Player(nameA, mark, boardA)
{
}

BlockingPlayer::~BlockingPlayer()
{
}

void BlockingPlayer::make_move(int& row, int& col)
{
  int found_blocking_move = 0;
  for(int i = 0; !found_blocking_move && i < BOARD_SIZE; i++)
    for(int j = 0; !found_blocking_move && j < BOARD_SIZE; j++)
      if (boardM->get_mark(i, j) == SPACE_CHAR && test_for_block(i, j)) {
        found_blocking_move = 1;
        row = i;
        col = j;
      }
  
  if (!found_blocking_move)
    random_move(row, col);
}

int BlockingPlayer::test_for_block(int row, int col)
{
  int result;
  int i;
  int j;

  // Is opponent about to win across a row?
  result = 1;
  for (j = 0; j < BOARD_SIZE; j++)
    if (j != col && boardM->get_mark(row, j) != opponent_markM)
      result = 0;

  // Is opponent about to win down a column?
  if (!result) {
    result = 1;
    for (i = 0; i < BOARD_SIZE; i++)
      if (i != row && boardM->get_mark(i, col) != opponent_markM)
        result = 0;
  }

  // Is opponent about to win on a diagonal?
  if (!result && row == col) {
    result = 1;
    for (i = 0; i < BOARD_SIZE; i++)
      if (i != row && boardM->get_mark(i, i) != opponent_markM)
        result = 0;
  }  if (!result && row == (BOARD_SIZE - col - 1)) {
    result = 1;
    for (i = 0; i < BOARD_SIZE; i++)
      if (i != row 
          && boardM->get_mark(i, BOARD_SIZE - i - 1) != opponent_markM)
        result = 0;
  }

  return result;
}

void BlockingPlayer::random_move(int& row, int& col)
{
  vector<int> open_row;
  vector<int> open_col;
  int open_count = 0;
  for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++)
      if (boardM->get_mark(i, j) == SPACE_CHAR) {
        open_row.resize(open_count + 1);
        open_row[open_count] = i;
        open_col.resize(open_count + 1);
        open_col[open_count] = j;
        open_count++;
      }
  
  int random_index = discrete_unif(0, open_count - 1);
  row = open_row[random_index];
  col = open_col[random_index];
}
