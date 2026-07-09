#include <iostream>
#include <string>
#include <vector>
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;

class Character
{
private:
  string name;
  int mapPosition;

public:
  Character(string n, int mP);
  string getName();
  int getMapPosition();
};

#endif