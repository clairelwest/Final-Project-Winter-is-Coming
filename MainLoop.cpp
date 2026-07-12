#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Game.h"
using namespace std;

int main()
{
  Game game;
  game.start();

  while (!game.isOver())
  {
    game.takeTurn();
  }

  game.endGame();

  return 0;
}