// HumanPlayer.h
// HumanPlayer class interface
// A modified version of ENGG 335 Lab 9 Exercise D

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {

public:
  HumanPlayer(const Mystring& nameA, char mark, const Board *boardA);
  // PROMISES:
  //  Initializes object by passing all arguments to the Player ctor.
               
  ~HumanPlayer();

  void make_move(int& row, int& col);
  // REQUIRES:
  //   User is ready to respond to prompts for input.
  // PROMISES:
  //   Gives values to row and col by asking the user for input
  //   on cin.
};

#endif
