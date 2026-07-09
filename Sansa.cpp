#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Sansa.h"
#include "Character.h"
using namespace std;

Sansa::Sansa(string n, int r, int g, int mP) : Character(n, mP)
{
  respect = r;
  gold = g;
}

int Sansa::getRespect()
{
  return respect;
}

int Sansa::getGold()
{
  return gold;
}

string Sansa::getName()
{
  return name;
}

bool Sansa::changeRespect(int cR)
{
  return true; // not written
}

bool changeGold()
{
  return true; // not written
}

bool changeDays()
{
  return true; // not written
}

bool changeMapPosition()
{
  return true; // not written
}

bool openInventory()
{
  return true; // not written
}