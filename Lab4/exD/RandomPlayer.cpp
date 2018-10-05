// RandomPlayer.cpp

#include "RandomPlayer.h"
#include "Board.h"
#include <vector>
using namespace std;
#include <assert.h>
#include "distribs.h"
#include "mystring.h"

RandomPlayer::RandomPlayer(const Mystring& nameA, char mark,const Board *boardA)
: Player(nameA, mark, boardA)
{
}

RandomPlayer::~RandomPlayer()
{
}

void RandomPlayer::make_move(int& row, int& col)
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

