#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Sansa.h"
#include "Character.h"
#include "Task.h"
#include "Location.h"

using namespace std;

class Game
{
private:
  int currentDay;
  int dailyActions;
  Sansa sansa{2, 60, 0};
  vector<Location> map;

public:
  Game();
  Sansa getSansa();
  int getCurrentDay();
  void changeDay();
  void start();
  void takeTurn();
  void printMap();
  bool isOver();
  void endGame();
};

#endif