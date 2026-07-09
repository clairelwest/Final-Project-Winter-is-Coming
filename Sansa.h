#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#ifndef SANSA_H
#define SANSA_H
using namespace std;

class Sansa : private Character
{
private:
  string name;
  int respect;
  int gold;
  int mapPosition;

public:
  Sansa(string n, int r, int g, int mP);
  int getRespect();
  int getGold();
  string getName();
  bool changeRespect(int cR);
  bool changeGold();
  bool changeMapPosition();
  bool openInventory();
};

#endif