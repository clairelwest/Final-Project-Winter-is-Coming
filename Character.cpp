#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

Character::Character(int i)
{
  index = i;
  switch (index)
  {
  case SANSA:
    name = "Sansa Stark";
    break;
  case BRIENNE:
    name = "Brienne of Tarth";
    break;
  case ARYA:
    name = "Arya Stark";
    break;
  case JON:
    name = "Jon Snow";
    break;
  case PETYR:
    name = "Petyr Baelish";
    break;
  default:
    name = "";
    break;
  }
}

string Character::getName()
{
  return name;
}

int Character::getIndex()
{
  return index;
}