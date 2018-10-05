// Referee.h

#ifndef REFEREE_H
#define REFEREE_H

// Tell the  compiler that the classes Board and Player exist.
class Board;
class Player;

class Referee {
public:
  Referee(Board* boardA, Player* x_playerA, Player* y_playerA);
  // REQUIRES:
  //   boardA points to a Board object.
  //   x_playerA and o_playerA point to Player objects.
  //   x_playerA->mark() == LETTER_X
  //   o_playerA->mark() == LETTER_O
  // PROMISES: 
  //   Initializes object by telling it which board players
  //   and which players it is associated with.

  void run_a_game();
  // PROMISES:
  //   Clears board, then runs a single game of tic-tac-toe.

private:
  Board *boardM;
  Player *x_playerM;
  Player *o_playerM;

  // Helper for run_a_game ...
  void get_a_move(Player *the_player);
};

#endif
