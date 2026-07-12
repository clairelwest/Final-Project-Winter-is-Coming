#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <optional>
#include "Character.h"
#include "Task.h"
#include "Location.h"
#include "Sansa.h"
#include "ASCII.h"
#include "Game.h"
using namespace std;

constexpr int CHECK_INVENTORY = 1;
constexpr int VIEW_MAP = 2;
constexpr int COMPLETE_TASK = 3;
constexpr int TALK_TO_SOMEONE = 4;
constexpr int TRAVEL = 5;

void introduceBrienne()
{
  printBrienne();
  cout << "Brienne: Hello my lady" << endl;
  cout << "Brienne: I am afraid I have recived some bad news." << endl;
  cout << "Brienne: Winter is only 9 days away!" << endl;
  cout << "Brienne: Before it comes you must prepare the supplies Winterfell needs to survive the cold." << endl;
  cout << "Brienne: We will need a complete bundle of 50 mutton, 50 potatos, 100 arrows, 100 firewood, and 20 blankets." << endl;
  cout << "Brienne: If you have any questions you can always come to me!" << endl;
}

void intro()
{
  printMainHeader();
  cout << winterfellBanner();
  string confirm = "";
  cout << "Sansa: Hello my name is Sansa Stark!" << endl;
  cout << "Sansa: I am the Queen of the North, and have many duties to attend to." << endl;
  cout << "Sansa: Will you assist me?" << endl;
  cin >> confirm;

  while (confirm != "yes" && confirm != "no")
  {
    cout << "Sansa: A yes or no please." << endl;
    cin >> confirm;
  }

  if (confirm == "no")
  {
    cout << "Sansa: I'm sorry to hear that." << endl;
    return;
  }
  else if (confirm == "yes")
  {
    cout << "Sansa: Wonderful thank you!" << endl;
  }

  cout << "Sansa: I should start my day by checking in with my advisor Brienne of Tarth." << endl;
}

Game::Game()
{
  currentDay = 1;
  dailyActions = 2;
  map = {
      Location("Winterfell", winterfellBanner(), {Character(Character::BRIENNE), Character(Character::ARYA)}, {2, 3, 4}),
      Location("The Village", theVillageBanner(), {}, {0, 1, 4}),
      Location("The Wall", theWallBanner(), {Character(Character::JON)}, {3, 4}),
      Location("The Vale", theValeBanner(), {Character(Character::PETYR)}, {1})};
}

Sansa Game::getSansa()
{
  return sansa;
}

int Game::getCurrentDay()
{
  return currentDay;
}

void Game::changeDay()
{
  currentDay++;
  printDay(currentDay);
  dailyActions = 2;
  map[sansa.getMapPosition()].printBanner();

  cout << "Gold: " << sansa.getGold() << endl;
  cout << "Respect: " << sansa.getRespect() << endl;
}

void Game::start()
{
  intro();
  printDay(currentDay);
  introduceBrienne();
}

void Game::printMap()
{
  cout << R"(
  -----------------------------------
                    [The Wall]
                        |
  [The Village] -- [Winterfell] (home)
                        |
                    [The Vale]
  -----------------------------------
  )";
  cout << "Currrent Location: " << map[sansa.getMapPosition()].getName() << endl;
}

void Game::takeTurn()
{
  switch (sansa.chooseAction())
  {
  case CHECK_INVENTORY:
    sansa.printInventory();
    break;
  case VIEW_MAP:
    printMap();
    break;
  case COMPLETE_TASK:
  {
    dailyActions--;
    Task task = map[sansa.getMapPosition()].findTask();
    sansa.completeTask(task);
    break;
  }
  case TALK_TO_SOMEONE:
  {
    optional<Character> character = map[sansa.getMapPosition()].talkTo();
    if (character.has_value())
    {
      sansa.interact(character.value(), currentDay);
    }
    break;
  }
  case TRAVEL:
    dailyActions--;
    sansa.travel(map);
    break;
  }
  if (dailyActions <= 0)
  {
    changeDay();
  }
}

bool Game::isOver()
{
  if (currentDay >= 10)
  {
    return true;
  }
  return false;
}

void Game::endGame()
{
  printWinter();
  sansa.printInventory();

  if (sansa.bundleComplete() && sansa.getRespect() > 0)
  {
    printWin();
    if (sansa.getKillPetyr())
    {
      printKillPetyr();
    }
  }
  else
  {
    printLoss();
    if (sansa.getRespect() <= 0)
    {
      printPetyrTakeWinterfell();
    }
  }
}