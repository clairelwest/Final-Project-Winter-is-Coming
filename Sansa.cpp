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

void printMenu()
{
  cout << R"(
  1. Check Inventory
  2. View Map
  3. Complete Task
  4. Talk to Someone
  5. Travel
  )";
  cout << "Please select an option: ";
}

void travelMenu(vector<Location> map)
{
  for (int i = 0; i < static_cast<int>(map.size()); i++)
  {
    cout << i + 1 << ". " << map[i].getName() << endl;
  }
  cout << "Please select an option: ";
}

void Sansa::printStatus()
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
    cout << "Brienne: We still have supplies to gather before winter." << endl;
  }
  else
  {
    cout << "Brienne: Excellent work my lady! We are prepared for winter." << endl;
  }
}

void Sansa::interactBrienne(int cD)
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
    printStatus();
    break;
  case 2:
    cout << "Brienne: We have " << 9 - cD << " days till winter." << endl;
    break;
  }
}

void Sansa::interactArya()
{
  string confirm;
  cout << "Arya: Hello sister" << endl;
  cout << "Arya: Do you need help with anything?" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "Arya: A simple yes or no is all I need." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    string confirm2;
    cout << "Arya: Have you decided that Petyr is too dangerous to keep alive after all?" << endl;
    cin >> confirm2;
    while (confirm2 != "yes" && confirm2 != "no")
    {
      cout << "Arya: A simple yes or no is all I need." << endl;
      cin >> confirm2;
    }
    if (confirm2 == "yes")
    {
      cout << "Arya: Took you long enough. I'll begin my preperations." << endl;
      cout << "Respect +1" << endl;
      respect++;
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

void Sansa::interactJon()
{
  string confirm;
  cout << "Jon: Hello Sansa!" << endl;
  cout << "Jon: Do you need anything at Winterfell?" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "Jon: Just need a yes or no." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    string confirm2;
    cout << "Jon: Will you be needing more arrows for winter?" << endl;
    cin >> confirm2;
    while (confirm2 != "yes" && confirm2 != "no")
    {
      cout << "Jon: Just need a yes or no." << endl;
      cin >> confirm2;
    }
    if (confirm2 == "yes")
    {
      cout << "Jon: I'll give you all that I can spare." << endl;
      cout << "Jon: Oh and Sansa, make sure you're carefull aroud Petyr, you know he wants control of Winterfell." << endl;
      cout << "Jon: I'll be off then, take care sister." << endl;
      arrows += 100;
      cout << "Arrows +100" << endl;
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

void Sansa::interactPetyr()
{
  string confirm;
  cout << "Petyr: Hello Sansa dear." << endl;
  cout << "Petyr: Is there somthing I can do to be of service?" << endl;
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
      gold += 50;
      respect -= 2;
      cout << "Gold +50" << endl;
      cout << "Respect -2" << endl;
    }
  }
  else if (confirm == "no")
  {
    cout << "Petyr: Well I apreciate you visiting me." << endl;
    cout << "Petyr: Feel free to come again if you ever need my assistance." << endl;
  }
}

void Sansa::buyMutton()
{
  string confirm;
  cout << "Do you wish to purchase 25 mutton for 20 gold?" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    if (gold >= 20)
    {
      cout << "Mutton +25" << endl;
      cout << "Gold -20" << endl;
      mutton += 25;
      gold -= 20;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::buyPotatoes()
{
  string confirm;
  cout << "Do you wish to purchase 25 potatoes for 15 gold?" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    if (gold >= 15)
    {
      cout << "Potatoes +25" << endl;
      cout << "Gold -15" << endl;
      potatoes += 25;
      gold -= 15;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::buyFirewood()
{
  string confirm;
  cout << "Do you wish to purchase 50 firewood for 25 gold?" << endl;
  cin >> confirm;
  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }
  if (confirm == "yes")
  {
    if (gold >= 25)
    {
      cout << "Firewood +50" << endl;
      cout << "Gold -25" << endl;
      firewood += 50;
      gold -= 25;
    }
    else
    {
      cout << "You do not have enough gold for this." << endl;
    }
  }
}

void Sansa::chopFirewood()
{
  cout << "===============" << endl;
  cout << "Chopping Firewood..." << endl;
  cout << "===============" << endl;
  firewood += 10;
  cout << "Firewood +10" << endl;
}

void Sansa::inspireConfidence()
{
  confidencePoints--;
  if (confidencePoints > 0)
  {
    printSansa();
    respect++;
    if (confidencePoints == 3)
    {
      cout << "= Sansa has given food to the poor =" << endl;
    }
    if (confidencePoints == 2)
    {
      cout << "= Sansa has given toys to the children =" << endl;
    }
    if (confidencePoints == 1)
    {
      cout << "= Sansa has comissioned repairs =" << endl;
    }
    cout << "Respect +1" << endl;
  }
  else
  {
    cout << "There is nothing more Sansa can do to inspire confidence." << endl;
  }
}

Sansa::Sansa(int r, int g, int mP) : Character(Character::SANSA)
{
  respect = r;
  gold = g;
  mapPosition = mP;
  killPetyr = false;
  confidencePoints = 4;

  ifstream inFile("Resources.txt");
  if (!inFile.is_open())
  {
    cout << "Error: could not open Resources.txt" << endl;
  }

  string line;
  while (getline(inFile, line))
  {
    int space1 = line.find(' ');
    mutton = stoi(line.substr(0, space1));
    int space2 = line.find(' ', space1 + 1);
    potatoes = stoi(line.substr(space1 + 1, space2 - space1 - 1));
    int space3 = line.find(' ', space2 + 1);
    arrows = stoi(line.substr(space2 + 1, space3 - space2 - 1));
    int space4 = line.find(' ', space3 + 1);
    firewood = stoi(line.substr(space3 + 1, space4 - space3 - 1));
    blankets = stoi(line.substr(space4 + 1));
  }
  inFile.close();
}

int Sansa::chooseAction()
{
  int option = 0;
  do
  {
    printMenu();
    cin >> option;
  } while (option < 1 || option > 5);
  cout << endl;
  return option;
}

void Sansa::travel(vector<Location> map)
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
  case 4: // Inspire Confidence
    inspireConfidence();
    break;
  }
}

bool Sansa::bundleComplete()
{
  if (mutton >= 50 && potatoes >= 50 && arrows >= 100 && firewood >= 100 && blankets >= 20)
  {
    return true;
  }
  return false;
}