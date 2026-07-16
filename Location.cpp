#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <optional>
#include "Location.h"
#include "Character.h"
using namespace std;

Location::Location(string n, string b, vector<Character> r, vector<Task> t) // Location constructor
{
  name = n;
  banner = b;
  residents = r;
  tasks = t;
}
string Location::getName()
{
  return name;
}

void Location::printBanner()
{
  cout << banner;
}

vector<Character> Location::getResidents()
{
  return residents;
}

vector<Task> Location::getTasks()
{
  return tasks;
}

optional<Character> Location::talkTo() // Displays the characters that you can interact with in Sansa's current location
{
  if (residents.empty())
  {
    cout << "There is no one to talk to in " << name << endl;
    return nullopt;
  }
  int option = 0;
  cout << "You can speak to:" << endl;
  for (int i = 0; i < static_cast<int>(residents.size()); i++)
  {
    cout << i + 1 << ". " << residents[i].getName() << endl;
  }
  while (option < 1 || option > static_cast<int>(residents.size()))
  {
    cout << "Please select an option: ";
    cin >> option;
  }
  cout << endl;
  return residents[option - 1];
}

Task Location::findTask() // Displays the availible tasks in Sansa's current location
{
  int option = 0;
  cout << "You can:" << endl;
  for (int i = 0; i < static_cast<int>(tasks.size()); i++)
  {
    cout << i + 1 << ". " << tasks[i].getName() << endl;
  }
  while (option < 1 || option > static_cast<int>(tasks.size()))
  {
    cout << "Please select an option: ";
    cin >> option;
  }
  cout << endl;
  return tasks[option - 1];
}
