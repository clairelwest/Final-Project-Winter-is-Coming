#include <iostream>
#include <string>
#include <vector>
#ifndef LOCATION_H
#define LOCATION_H
using namespace std;

class Location
{
private:
  string name;
  int mapPosition;

public:
  Location(string n, int mP);
  string getName();
  int getMapPosition();
  int distanceToo();
};

#endif