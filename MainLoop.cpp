#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Game.h"
using namespace std;

int main()
{
  Game game;
  game.start(); // Runs the game intro

  while (!game.isOver()) // Continues taking turns while the game is not over
  {
    game.takeTurn();
  }

  game.endGame(); // Checks conditions and displays appropriate ending

  return 0;
}