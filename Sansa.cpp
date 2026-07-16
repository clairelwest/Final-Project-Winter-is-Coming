#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Sansa.h"
#include "Character.h"
#include "Task.h"
#include "ASCII.h"
#include "Location.h"
using namespace std;

void printMenu() // Prints the turn menu
{
  cout << R"(
  1. Check Inventory
  2. View Map
  3. Complete Task
  4. Talk to Someone
  5. Travel
  6. Hint
  )";
  cout << "Please select an option: ";
}

void travelMenu(vector<Location> map) // Prints the travel menu
{
  for (int i = 0; i < static_cast<int>(map.size()); i++)
  {
    cout << i + 1 << ". " << map[i].getName() << endl;
  }
  cout << "Please select an option: ";
}

bool Sansa::printStatus() // Tells the play what still needs to be gathered
{
  int muttonNeeded = 50 - mutton;
  if (muttonNeeded < 0)
  {
    muttonNeeded = 0;
  }
  int potatoesNeeded = 50 - potatoes;
  if (potatoesNeeded < 0)
  {
    potatoesNeeded = 0;
  }
  int arrowsNeeded = 100 - arrows;
  if (arrowsNeeded < 0)
  {
    arrowsNeeded = 0;
  }
  int firewoodNeeded = 100 - firewood;
  if (firewoodNeeded < 0)
  {
    firewoodNeeded = 0;
  }
  int blanketsNeeded = 20 - blankets;
  if (muttonNeeded < 0)
  {
    firewoodNeeded = 0;
  }
  cout << " === Suplies Status === " << endl;
  cout << "Respect: " << respect << "/4" << endl;
  cout << "Mutton Needed: " << muttonNeeded << endl;
  cout << "Potatoes Needed: " << potatoesNeeded << endl;
  cout << "Arrows Needed: " << arrowsNeeded << endl;
  cout << "Firewood Needed: " << firewoodNeeded << endl;
  cout << "Blankets Needed: " << blanketsNeeded << endl;
  if (muttonNeeded != 0 || potatoesNeeded != 0 || arrowsNeeded != 0 || firewoodNeeded != 0 || blanketsNeeded != 0)
  {
    return false;
  }
  return true;
}

void Sansa::interactBrienne(int cD) // Runs when sansa talks to Brienne
{
  printBrienne();
  cout << "Brienne: Good day my lady!" << endl;
  cout << "Brienne: What can I do for you?" << endl;
  int option = 0;

  while (option < 1 || option > 2)
  {
    cout << R"(

  1. Check Current Status
  2. How Long Until Winter
  Please Select an Option: )";
    cin >> option;
  }
  cout << endl;
  switch (option)
  {
  case 1:
  {
    bool complete = printStatus();
    if (complete)
    {
      cout << "Brienne: Excellent work my lady! We are prepared for winter." << endl;
    }
    else
    {
      cout << "Brienne: We still have supplies to gather before winter." << endl;
    }
    break;
  }
  case 2:
    cout << "Brienne: We have " << 10 - cD << " days till winter." << endl;
    break;
  }
}

void Sansa::interactArya() // Runs when sansa talks to Arya
{
  string confirm;
  cout << "Arya: Hello sister" << endl;
  cout << "Arya: Do you need help with anything? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "Arya: A simple yes or no is all I need." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    string confirm2;
    cout << "Arya: Have you decided that Petyr is too dangerous to keep alive after all? (yes or no)" << endl;
    cin >> confirm2;
    while (confirm2 != "yes" && confirm2 != "no")
    {
      cout << "Arya: A simple yes or no is all I need." << endl;
      cin >> confirm2;
    }
    if (confirm2 == "yes")
    {
      cout << "Arya: Took you long enough. I'll begin my preperations." << endl;
      if (!killPetyr)
      {
        cout << "Respect +1" << endl;
        respect++;
      }
      killPetyr = true;
    }
    else if (confirm2 == "no")
    {
      cout << "Arya: Whatever you say. Let me know when you change your mind." << endl;
      killPetyr = false;
    }
  }
  else if (confirm == "no")
  {
    cout << "Arya: Well I'll be on my way then." << endl;
  }
}

void Sansa::interactJon() // Runs when sansa talks to Jon
{
  string confirm;
  cout << "Jon: Hello Sansa!" << endl;
  cout << "Jon: Do you need anything at Winterfell? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "Jon: Just need a yes or no." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    string confirm2;
    cout << "Jon: Will you be needing more arrows for winter? (yes or no)" << endl;
    cin >> confirm2;
    while (confirm2 != "yes" && confirm2 != "no")
    {
      cout << "Jon: Just need a yes or no." << endl;
      cin >> confirm2;
    }
    if (confirm2 == "yes")
    {
      if (arrows == 0)
      {
        cout << "Jon: I'll give you all that I can spare." << endl;
        cout << "Jon: Oh and Sansa, make sure you're carefull aroud Petyr, you know he wants control of Winterfell." << endl;
        cout << "Jon: I'll be off then, take care sister." << endl;
        arrows += 100;
        cout << "Arrows +100" << endl;
      }
      else
      {
        cout << "Jon: We are running low, but I see what I can do." << endl;
        cout << "Jon: I'll be off then, take care sister." << endl;
        cout << "Arrows +20" << endl;
        arrows += 20;
      }
    }
    else if (confirm2 == "no")
    {
      cout << "Jon: Well let me know if you change your mind, take care sister." << endl;
      cout << "Jon: Oh and Sansa, make sure you're carefull aroud Petyr, you know he wants control of Winterfell." << endl;
    }
  }
  else if (confirm == "no")
  {
    cout << "Jon: I'll be off then, take care sister." << endl;
    cout << "Jon: Oh and Sansa, make sure you're carefull aroud Petyr, you know he wants control of Winterfell." << endl;
  }
}

void Sansa::interactPetyr() // Runs when Sansa talks to Petyr
{
  string confirm;
  cout << "Petyr: Hello Sansa dear." << endl;
  cout << "Petyr: Is there somthing I can do to be of service? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "Petyr: Is that a yes or a no?." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    int confirm2;
    cout << "Petyr: What does my dear Sansa require of me?" << endl;
    cout << "1. Blankets" << endl;
    cout << "2. Gold" << endl;
    cout << "Please select an option: ";
    cin >> confirm2;
    while (confirm2 != 1 && confirm2 != 2)
    {
      cout << "Please select a vaild option: ";
      cin >> confirm2;
    }
    if (confirm2 == 1)
    {
      cout << "Petyr: Of course my dear." << endl;
      cout << "Petyr: Farwell Sansa, feel free to vist whenever you want." << endl;
      blankets += 20;
      cout << "Blankets +20" << endl;
    }
    else if (confirm2 == 2)
    {
      cout << "Petyr: Of course my dear." << endl;
      cout << "Petyr: It's a pity Winterfell has been so depleted. I would do anything to see it restored." << endl;
      cout << "Sansa: Winterfell is doing well, our need is merely due to winters swift and unexpected aproach." << endl;
      cout << "Petyr: I mean no offense my dear." << endl;
      gold += 60;
      respect -= 2;
      cout << "Gold +60" << endl;
      cout << "Respect -2" << endl;
      queenInTheNorth = false;
    }
  }
  else if (confirm == "no")
  {
    cout << "Petyr: Well I apreciate you visiting me." << endl;
    cout << "Petyr: Feel free to come again if you ever need my assistance." << endl;
  }
}

void Sansa::buyMutton() // Sansa loses gold and gains mutton
{
  string confirm;
  cout << "Do you wish to purchase 20 mutton for 20 gold? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    if (gold >= 20)
    {
      cout << "Mutton +20" << endl;
      cout << "Gold -20" << endl;
      mutton += 20;
      gold -= 20;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::buyPotatoes() // Sansa loses gold and gains potatoes
{
  string confirm;
  cout << "Do you wish to purchase 20 potatoes for 10 gold? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    if (gold >= 10)
    {
      cout << "Potatoes +20" << endl;
      cout << "Gold -10" << endl;
      potatoes += 20;
      gold -= 10;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::buyFirewood() // Sansa loses gold and gains firewood
{
  string confirm;
  cout << "Do you wish to purchase 40 firewood for 20 gold? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    if (gold >= 20)
    {
      cout << "Firewood +40" << endl;
      cout << "Gold -20" << endl;
      firewood += 40;
      gold -= 20;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::chopFirewood() // Sansa gains a smaller amount of firewood
{
  cout << "===============" << endl;
  cout << "Chopping Firewood..." << endl;
  cout << "===============" << endl;
  firewood += 20;
  cout << "Firewood +20" << endl;
}

void Sansa::inspireConfidence() // Sansa loses firewood/mutton/potatoes and gain respect
{
  confidencePoints--;
  if (confidencePoints > 0)
  {
    if (confidencePoints == 2)
    {
      string confirm;
      cout << "Do you wish to use 10 firewood for repairs? (yes or no)" << endl;
      cin >> confirm;
      while (confirm != "yes" && confirm != "no")
      {
        cout << "A yes or no please." << endl;
        cin >> confirm;
      }
      cout << endl;
      if (confirm == "yes")
      {
        if (firewood >= 10)
        {
          printSansa();
          cout << "= Sansa has comissioned repairs =" << endl;
          respect++;
          cout << "Respect +1" << endl;
          cout << "Firewood -10" << endl;
          firewood -= 10;
        }
        else
        {
          cout << "You do not have enough firewood for this." << endl;
        }
      }
    }
    if (confidencePoints == 1)
    {
      string confirm;
      cout << "Do you wish to use 10 mutton/potatoes to feed the poor? (yes or no)" << endl;
      cin >> confirm;
      while (confirm != "yes" && confirm != "no")
      {
        cout << "A yes or no please." << endl;
        cin >> confirm;
      }
      cout << endl;
      if (confirm == "yes")
      {
        int confirm2;
        cout << "1. Give Mutton" << endl;
        cout << "2. Give Potatoes" << endl;
        cout << "Please select an option: ";
        cin >> confirm2;
        while (confirm2 != 1 && confirm2 != 2)
        {
          cout << "Please select a vaild option: ";
          cin >> confirm2;
        }
        cout << endl;
        if (confirm2 == 1)
        {
          if (mutton >= 10)
          {
            printSansa();
            cout << "= Sansa has given mutton to the poor =" << endl;
            respect++;
            cout << "Respect +1" << endl;
            cout << "Mutton -10" << endl;
            mutton -= 10;
          }
          else
          {
            cout << "You do not have enough mutton for this." << endl;
          }
        }
        else if (confirm2 == 2)
        {
          if (potatoes >= 10)
          {
            printSansa();
            cout << "= Sansa has given potatoes to the poor =" << endl;
            respect++;
            cout << "Respect +1" << endl;
            cout << "Potatoes -10" << endl;
            potatoes -= 10;
          }
          else
          {
            cout << "You do not have enough potatoes for this." << endl;
          }
        }
      }
    }
  }
  else
  {
    cout << "There is nothing more Sansa can do to inspire confidence." << endl;
  }
}

void Sansa::intimidateFarmers() // Sansa loses respect and gains potatoes
{
  string confirm;
  cout << "Do you wish to lose respect to gain 30 potatoes? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    cout << "= Sansa increases farm production through fear =" << endl;
    cout << "Potatoes +30" << endl;
    cout << "Respect -1" << endl;
    potatoes += 30;
    respect--;
  }
}

void Sansa::enlistNightsWatch() // Sansa loses respect and gains firewood
{
  string confirm;
  cout << "Do you wish to lose respect to gain 40 firewood? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    cout << "= Sansa orders the Night's Watch to chop wood =" << endl;
    cout << "Firewood +40" << endl;
    cout << "Respect -1" << endl;
    firewood += 40;
    respect--;
  }
}

void Sansa::tradePotatoes() // Sansa loses potatoes and gains mutton
{
  string confirm;
  cout << "Do you wish to trade 20 potatoes for 10 mutton? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    if (potatoes >= 20)
    {
      cout << "= Sansa exchanges potatoes for mutton =" << endl;
      cout << "Mutton +10" << endl;
      cout << "Potatoes -20" << endl;
      mutton += 10;
      potatoes -= 20;
    }
    else
    {
      cout << "You do not have enough potatoes for this." << endl;
    }
  }
}

void Sansa::hireHunters() // Sansa loses arrows and gains mutton
{
  string confirm;
  cout << "Do you wish to trade 20 arrows for 20 mutton? (yes or no)" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  cout << endl;
  if (confirm == "yes")
  {
    if (arrows >= 20)
    {
      cout << "= Sansa exchanges arrows for mutton =" << endl;
      cout << "Mutton +20" << endl;
      cout << "Arrows -20" << endl;
      mutton += 20;
      arrows -= 20;
    }
    else
    {
      cout << "You do not have enough arrows for this." << endl;
    }
  }
}

Sansa::Sansa(int r, int g, int mP) : Character(Character::SANSA) // Sansa constructor
{
  respect = r;
  gold = g;
  mapPosition = mP;
  mutton = 0;
  potatoes = 0;
  arrows = 0;
  firewood = 0;
  blankets = 0;
  killPetyr = false;
  queenInTheNorth = true;
  confidencePoints = 3;
}

int Sansa::chooseAction() // Runs the menu for taking turns
{
  int option = 0;
  do
  {
    printMenu();
    cin >> option;
  } while (option < 1 || option > 6);
  cout << endl;
  return option;
}

void Sansa::travel(vector<Location> map) // Allows sansa to travel
{
  int travelOption = 0;
  while (travelOption < 1 || travelOption > 4)
  {
    travelMenu(map);
    cin >> travelOption;
  }
  printTraveling();
  setMapPosition(travelOption - 1);
  map[mapPosition].printBanner();
}

int Sansa::getRespect()
{
  return respect;
}

int Sansa::getGold()
{
  return gold;
}

int Sansa::getMapPosition()
{
  return mapPosition;
}

bool Sansa::getKillPetyr()
{
  return killPetyr;
}

bool Sansa::getQueen()
{
  return queenInTheNorth;
}

void Sansa::addRespect(int cR)
{
  respect += cR;
}

void Sansa::addGold(int g)
{
  gold += g;
}

bool Sansa::setMapPosition(int t)
{
  mapPosition = t;
  return true;
}

void Sansa::printInventory()
{
  cout << endl;
  cout << "=== Inventory ===" << endl;
  cout << "Gold: " << gold << endl;
  cout << "Mutton: " << mutton << endl;
  cout << "Potatos: " << potatoes << endl;
  cout << "Arrows: " << arrows << endl;
  cout << "Firewood: " << firewood << endl;
  cout << "Blankets: " << blankets << endl;
}

void Sansa::interact(Character c, int cD)
{
  switch (c.getIndex())
  {
  case BRIENNE:
    interactBrienne(cD);
    break;
  case ARYA:
    interactArya();
    break;
  case JON:
    interactJon();
    break;
  case PETYR:
    interactPetyr();
    break;
  }
}

void Sansa::completeTask(Task t)
{
  switch (t.getIndex())
  {
  case 0: // BUYMUTTON
    buyMutton();
    break;
  case 1: // BUYPOTATOES
    buyPotatoes();
    break;
  case 2: // BUYFIREWOOD
    buyFirewood();
    break;
  case 3: // CHOPFIREWOOD
    chopFirewood();
    break;
  case 4: // INSPIRECONFIDENCE
    inspireConfidence();
    break;
  case 5: // INTIMIDATEFARMERS
    intimidateFarmers();
    break;
  case 6: // ENLISTNIGHTSWATCH
    enlistNightsWatch();
    break;
  case 7: // TRADEPOTATOES
    tradePotatoes();
    break;
  case 8: // HIREHUNTERS
    hireHunters();
    break;
  }
}

bool Sansa::bundleComplete() // Checks if Sansa has all supplies
{
  if (mutton >= 50 && potatoes >= 50 && arrows >= 100 && firewood >= 100 && blankets >= 20)
  {
    return true;
  }
  return false;
}