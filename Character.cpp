#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

Character::Character(string n, int mP)
{
  name = n;
  mapPosition = mP;
}

string Character::getName()
{
  return name;
}

int Character::getMapPosition()
{
  return mapPosition;
}