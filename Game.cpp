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
constexpr int HINT = 6;

void introduceBrienne() // Runs as part of the game intro
{
  printBrienne();
  cout << "Brienne: Hello my lady" << endl;
  cout << "Brienne: I am afraid I have recieved some bad news." << endl;
  cout << "Brienne: Winter is only 10 days away!" << endl;
  cout << "Brienne: Before it comes you must prepare the supplies Winterfell needs to survive the cold." << endl;
  cout << "Brienne: We will need a complete bundle of:" << endl;
  cout << " - 50 mutton" << endl;
  cout << " - 50 potatos" << endl;
  cout << " - 100 arrows" << endl;
  cout << " - 100 firewood" << endl;
  cout << " - 20 blankets" << endl;
  cout << "Brienne: If you have any questions you can always come to me!" << endl;
}

void intro() // Game intro
{
  printMainHeader();
  cout << winterfellBanner();
  string confirm = "";
  cout << "Sansa: Hello my name is Sansa Stark!" << endl;
  cout << "Sansa: I am the Queen of the North, and have many duties to attend to." << endl;
  cout << "Sansa: Will you assist me? (yes or no)" << endl;
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

Game::Game() // Game class constructor creates map vector and location objects and establishes the tasks and characters at each location
{
  currentDay = 1;
  dailyActions = 2;
  map = {
      Location("Winterfell", winterfellBanner(), {Character(Character::BRIENNE), Character(Character::ARYA)}, {2, 3, 4, 8}),
      Location("The Village", theVillageBanner(), {}, {0, 1, 4, 5}),
      Location("The Wall", theWallBanner(), {Character(Character::JON)}, {3, 4, 6, 8}),
      Location("The Vale", theValeBanner(), {Character(Character::PETYR)}, {1, 5, 7})};
}

Sansa Game::getSansa()
{
  return sansa;
}

int Game::getCurrentDay()
{
  return currentDay;
}

void Game::changeDay() // Runs after Sansa has used all her daily actions
{
  currentDay++;
  printDay(currentDay);
  dailyActions = 2;
  map[sansa.getMapPosition()].printBanner();
  printMap();
  sansa.printInventory();
  cout << endl;
  cout << "=== Respect: " << sansa.getRespect() << "/4 ===" << endl;
}

void Game::start() // Game intro
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

void Game::takeTurn() // Calls Sansas functions according to the option the player selected and checks if the day is over
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
  case HINT:
    cout << "Sansa needs to collect all the nessesary supplies before winter." << endl;
    cout << "Sansa can do this by completing tasks and talking to people." << endl;
    cout << "Different locations have different characters and tasks, so you will need to travel." << endl;
    cout << "Be carefull with how you spend gold, and don't let your respect drop below 0." << endl;
    break;
  }
  if (dailyActions <= 0 && currentDay < 10)
  {
    changeDay();
  }
  else if (currentDay >= 10)
  {
    currentDay++;
    printDay(currentDay);
  }
}

bool Game::isOver() // Checks if the game has ended
{
  return (currentDay >= 11 || sansa.getRespect() < 0 || sansa.bundleComplete());
}

void Game::endGame() // Displays the game results
{
  printWinter();
  sansa.printStatus();
  if (sansa.bundleComplete() && sansa.getRespect() > 0)
  {
    printWin();
    if (sansa.getKillPetyr())
    {
      printKillPetyr();
    }
    if (sansa.getQueen())
    {
      cout << "           === The Queen in The North === " << endl;
      cout << "= Special Ending: Never accept gold from Petyr Baelish =" << endl;
      printTheNorth();
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