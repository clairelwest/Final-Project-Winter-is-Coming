#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
private:
  string name;
  int index;

public:
  static constexpr int SANSA = 0;
  static constexpr int BRIENNE = 1;
  static constexpr int ARYA = 2;
  static constexpr int JON = 3;
  static constexpr int PETYR = 4;
  Character(int i);
  string getName();
  int getIndex();
};

#endif