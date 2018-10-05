// RandomPlayer.h

#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "Player.h"

class RandomPlayer : public Player {
public:
  RandomPlayer(const Mystring& nameA, char mark, const Board *boardA);
  // PROMISES:
  //  Initializes object by passing all arguments to the Player ctor.
               
  ~RandomPlayer();

  void make_move(int& row, int& col);
  // PROMISES:
  //   Gives values to row and col based on the strategy outlined
  //   on the Lab 9 handout.
};

#endif
