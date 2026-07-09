#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Character.h"
#include "Location.h"
#include "Sansa.h"
#include "ASCII.h"
#include "Game.h"
using namespace std;

int main()
{
  Game game;
  Sansa sansa("Sansa Stark", 10, 100, 0);
  Location winterfell("Winterfell", 0);
  Location theVillage("The Village", 1);
  Location theWall("The Wall", 2);
  Location theVale("The Vale", 3);
  Character brienne("Brienne of Tarth", 0);
  Character arya("Arya Stark", 0);
  Character jon("Jon Snow", 2);
  Character petyr("Petyr Baelish", 3);

  game.start();

  while (!game.isOver())
  {
    game.takeTurn();
  }

  game.endGame();

  return 0;
}