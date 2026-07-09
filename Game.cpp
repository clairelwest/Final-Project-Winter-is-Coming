#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Character.h"
#include "Location.h"
#include "Sansa.h"
#include "ASCII.h"
#include "Game.h"
#include "Dialogue.h"
using namespace std;

Game::Game()
{
  currentDay = 0;
  mutton = 0;
  potatos = 0;
  arrows = 0;
  firewood = 0;
  blankets = 0;
}

int Game::getCurrentDay()
{
  return currentDay;
}

void Game::start()
{
  intro();
  printDay(currentDay + 1);
  introduceBrienne();
}

void Game::getAvailableTask()
{
  cout << "this is a placeholder" << endl;
}

void Game::getAvailableChar()
{
  cout << "this is a placeholder" << endl;
}

void Game::printMap()
{
  cout << R"(
                    [The Wall]
                        |
  [The Village] -- [Winterfell] (home)
                        |
                    [The Vale]
  )";
}

void Game::takeTurn()
{
  currentDay++;
  if (currentDay != 1)
  {
    printDay(currentDay);
  }
  int option = 0;
  int dailyActions = 2;

  while (dailyActions > 0)
  {
    do
    {
      printMenu();
      cin >> option;
      if (option == 99)
      {
        currentDay = 9;
      }
    } while (option < 1 || option > 5);

    switch (option)
    {
    case 1:
      getInventory();
      break;
    case 2:
      printMap();
      break;
    case 3:
      getAvailableTask();
      dailyActions--;
      break;
    case 4:
      getAvailableChar();
      break;
    case 5:
      travelMenu();
      dailyActions--;
    }
  }
}

bool Game::isOver()
{
  if (currentDay == 9)
  {
    return true;
  }
  return false;
}

void Game::endGame()
{
  currentDay++;
  printDay(currentDay);
  printWinter();
  getInventory();
}

void Game::getInventory()
{
  cout << endl;
  cout << "=== Inventory ===" << endl;
  cout << "Mutton: " << mutton << endl;
  cout << "Potatos: " << potatos << endl;
  cout << "Arrows: " << arrows << endl;
  cout << "Firewood: " << firewood << endl;
  cout << "Blankets: " << blankets << endl;
}

void Game::addMutton(int m)
{
  mutton += m;
}

void Game::addPotatos(int p)
{
  potatos += p;
}

void Game::addArrows(int a)
{
  arrows += a;
}

void Game::addFirewood(int f)
{
  firewood += f;
}

void Game::addBlankets(int b)
{
  blankets += b;
}