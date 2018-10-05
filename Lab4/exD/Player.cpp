// Player.cpp
// Player class implementation
// A modified version of ENGG 335 Lab 9 Exercise D

#include <assert.h>

#include "Player.h"

Player::Player(const Mystring& nameA, char mark, const Board *boardA)
  : nameM(nameA), boardM(boardA)
{
  assert(mark == LETTER_X || mark == LETTER_O);
  its_markM = mark;
  if (its_markM == LETTER_X)
    opponent_markM = LETTER_O;
  else
    opponent_markM = LETTER_X;
}

Player::~Player()
{
}

const Mystring& Player::name() const
{
	return nameM;
}

char Player::mark() const
{
  return its_markM;
}
