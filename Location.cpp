#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Location.h"
using namespace std;

Location::Location(string n, int mP)
{
  name = n;
  mapPosition = mP;
}
string Location::getName()
{
  return name;
}

int Location::getMapPosition()
{
  return mapPosition;
}

int Location::distanceToo()
{
  return 0;
}