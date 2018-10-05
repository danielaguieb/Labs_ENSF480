// Game.cpp
// main program file for tic-tac-toe game.


#include "Referee.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "BlockingPlayer.h"
#include "xo_constants.h"
#include "Game.h"
#include "mystring.h"
#include "line_eaters.h"
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


Player* Game::create_player(char mark, Board *board)
{
    assert(mark == LETTER_X || mark == LETTER_O);
    
    // Get the name.
    Mystring name("");
    cout << "\nPlease enter the name of the " << mark << " player: ";
    eat_line_keep_one_word(name);
    if (cin.fail()) kill_the_program();
    while (name == "") {
        cout << "Please try again: ";
        eat_line_keep_one_word(name);
        if (cin.fail()) kill_the_program();
    }
    
    // Get the player type.
    const int NUMBER_OF_TYPES = 3;
    cout << "\nWhat type of player is " << name.c_str() << "?\n";
    cout << "  1: human\n"
    << "  2: Random Player\n"
    << "  3. Blocking Player\n";
    
    cout << "Please enter a number in the range 1-" << NUMBER_OF_TYPES << ": ";
    int player_type = 0;
    int input_success = 0;
    eat_line_keep_one_int(player_type, input_success);
    while (!input_success
           || player_type < 1
           || player_type > NUMBER_OF_TYPES)
    {
        cout << "Please try again.\n";
        cout << "Enter a number in the range 1-" << NUMBER_OF_TYPES << ": ";
        eat_line_keep_one_int(player_type, input_success);
        if (cin.fail()) kill_the_program();
    }
    
    // Create a Player object.
    Player *result = 0;
    switch(player_type) {
        case 1:
            result = new HumanPlayer(name, mark, board);
            break;
        case 2:
            result = new RandomPlayer(name, mark, board);
            break;
        case 3:
            result = new BlockingPlayer(name, mark, board);
            break;
        default:
            cerr << "\nDefault case in switch should not be reached.\n"
            << "  Program terminated.\n";
            abort();
    }
    return result;
}



int main()
{
  srand( (unsigned int) time(0) );
  Game game;
  Board *the_board = new Board;
  Player *x_player = game.create_player(LETTER_X, the_board);
  Player *o_player = game.create_player(LETTER_O, the_board);

  Referee *the_ref = new Referee(the_board, x_player, o_player);
  char yes_or_no;
  do {
    the_ref->run_a_game();
    cout << "\nPlay another game? (y/n) ";
    yes_or_no = eat_line_keep_one_char();
    if (cin.fail()) kill_the_program();
  }
  while (yes_or_no == 'y');

  delete the_board;
  delete the_ref;
  delete x_player;
  delete o_player;

  return 0;
}


