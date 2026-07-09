#include <iostream>
#include <string>
#include <vector>
#ifndef GAME_H
#define GAME_H
using namespace std;

class Game
{
private:
  int currentDay;
  int mutton;
  int potatos;
  int arrows;
  int firewood;
  int blankets;

public:
  Game();
  int getCurrentDay();
  void start();
  void takeTurn();
  void printMap();
  bool isOver();
  void endGame();
  void getInventory();
  void getAvailableTask();
  void getAvailableChar();
  void addMutton(int m);
  void addPotatos(int p);
  void addArrows(int a);
  void addFirewood(int f);
  void addBlankets(int b);
};

#endif