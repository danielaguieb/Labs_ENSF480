// Referee.cpp

#include "xo_constants.h"
#include "Referee.h"
#include "Player.h"
#include "Board.h"
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;
#include "string.h"

Referee::Referee(Board* boardA, Player* x_playerA, Player* o_playerA)
  : boardM(boardA), 
    x_playerM(x_playerA), 
    o_playerM(o_playerA)
{
    assert(x_playerA->mark() == LETTER_X);
    assert(o_playerA->mark() == LETTER_O);
}

void Referee::run_a_game()
{
  boardM->clear();

  cout << "\nThe Referee is starting a game.  Here is the board:\n\n";
  boardM->display();
  cout << "Press the Enter key to continue ... ";
  string junk;
  getline(cin, junk);

  while( !boardM->x_wins() && !boardM->o_wins() && !boardM->is_full() ) {
    get_a_move(x_playerM);
    if ( !boardM->x_wins() && !boardM->is_full() )
      get_a_move(o_playerM);
  }
  
  cout << "\nTHE GAME IS OVER: ";
  if ( boardM->x_wins() )
    cout << x_playerM->name() << " is the winner!\n\n";
  else if ( boardM->o_wins() )
    cout << o_playerM->name() << " is the winner!\n\n";
  else
    cout << "the game is a tie.\n\n";
}

void Referee::get_a_move(Player *the_player)
{
  // Get a move.
  cout << "\nReferee asks player " << the_player->name() << " to move.\n";
  int row;
  int col;
  the_player->make_move(row, col);
  boardM->put_mark(row, col, the_player->mark());

  // Display the result.
  cout << "Player " << the_player->name() 
       << " put an " << the_player->mark()
       << " at (row=" << row << ", col=" << col << ").";
  cout << "  Here is the updated board:\n\n";
  boardM->display();
  cout << "Press the Enter key to continue ...";
  string junk;
  getline(cin, junk);
}
