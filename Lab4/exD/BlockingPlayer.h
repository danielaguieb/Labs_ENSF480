// BlockingPlayer.h

#ifndef BLOCKINGPLAYER_H
#define BLOCKINGPLAYER_H

#include "Player.h"

class BlockingPlayer : public Player {
public:
  BlockingPlayer(const Mystring& nameA, char mark, const Board *boardA);
  // PROMISES:
  //  Initializes object by passing all arguments to the Player ctor.
               
  ~BlockingPlayer();

  void make_move(int& row, int& col);
  // PROMISES:
  //   Gives values to row and col based on the strategy outlined
  //   on the Lab 9 handout.

private:
  // Helper functions for make_move.
  int test_for_block(int row, int col);
  void random_move(int& row, int& col);
};

#endif
