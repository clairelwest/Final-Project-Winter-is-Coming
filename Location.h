#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "Character.h"
#include "Task.h"
using namespace std;

class Location
{
private:
  string name;
  string banner;
  vector<Character> residents;
  vector<Task> tasks;

public:
  Location(string n, string b, vector<Character> r, vector<Task> t);
  string getName();
  void printBanner();
  vector<Character> getResidents();
  vector<Task> getTasks();
  optional<Character> talkTo();
  Task findTask();
};

#endif