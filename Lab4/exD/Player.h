// Player.h
// Player class interface
// A modified version of ENGG 335 Lab 9 Exercise D

// Player is an abstract base class--a class derived from
// Player should implement the make_move function in a
// way that reflects the strategy of that kind of Player.

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;


#include "xo_constants.h"
#include "mystring.h"

class Board;

class Player {

public:
  Player(const Mystring& nameA, char markA, const Board *boardA);
  // REQUIRES:
  //   markA == LETTER_X || markA == LETTER_O
  //   boardA points to a Board object.
  // PROMISES: 
  //   Creates object with name nameA and mark markA, asscociated
  //   with Board boardA.
   
  virtual ~Player();

  const Mystring& name() const;
  // PROMISES: Returns name of player.

  char mark() const;
  // PROMISES: Returns player's mark: either LETTER_X or LETTER_O.

  virtual void make_move(int& row, int& col) = 0;
  // Derived classes should override this function.

protected:
  Mystring nameM;
  const Board *boardM;
  char its_markM;
  char opponent_markM;
};

#endif
