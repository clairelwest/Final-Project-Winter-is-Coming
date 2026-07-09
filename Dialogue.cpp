#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ASCII.h"
using namespace std;

void intro()
{
  printMainHeader();
  printWinterfell();
  string confirm = "";
  cout << "Hello my name is Sansa Stark!" << endl;
  cout << "I am the Queen of the North, and have many duties to attend to." << endl;
  cout << "Will you assist me?" << endl;
  cin >> confirm;

  while (confirm != "yes" && confirm != "no")
  {
    cout << "A yes or no please." << endl;
    cin >> confirm;
  }

  if (confirm == "no")
  {
    cout << "I'm sorry to hear that." << endl;
    return;
  }
  else if (confirm == "yes")
  {
    cout << "Wonderful thank you!" << endl;
  }

  cout << "I should start my day by checking in with my advisor Brienne of Tarth." << endl;
}

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

void travelMenu()
{
  cout << R"(
  1. Winterfell
  2. The Village
  3. The Wall
  4. The Vale
  )";
  cout << "Please select an option: ";
}

void introduceBrienne()
{
  cout << "Hello my lady, my name is Brienne of Tarth." << endl;
  cout << "I am afraid I have recived some bad news." << endl;
  cout << "Winter is only 9 days away!" << endl;
  cout << "Before it comes you must prepare the supplies Winterfell needs to survive the cold." << endl;
  cout << "We will need a complete bundle of 50 mutton, 50 potatos, 100 arrows, 100 firewood, and 20 blankets." << endl;
  cout << "If you have any questions you can always come to me!" << endl;
}

void brienneMenu()
{
  cout << "Good day my lady!" << endl;
  cout << "What can I do for you?" << endl;
  int option = 0;

  while (option > 0 && option < 3)
  {
    cout << R"(
  Please Select an Option:
  1. Check Current Goal
  2. How Long Until Winter
  )";
    cin >> option;
  }
}