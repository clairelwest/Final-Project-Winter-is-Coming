#include <iostream>
#include <string>
#include <vector>
#include "ASCII.h"
#include "Game.h"
using namespace std;

void printMainHeader()
{
  cout << R"(
  ====================
    Winter Is Coming
  ====================
  
  )";
}

void printDay(int cD)
{
  cout << endl;
  cout << "==========" << endl;
  cout << "Day " << cD << endl;
  cout << "==========" << endl;
  cout << endl;
}

void printWinter()
{
  cout << R"(   * - * - * - * - *
  *  Winter is Here  *
    * - * - * - * - * 
  )";
}

void printTraveling()
{
  cout << R"(
  ================
  Traveling...
  ================
  
  )";
}

void printWinterfell()
{
  cout << R"(
  === Winterfell ===
      _   |~  _
     [_]--'--[_]
     | | /^\ | |
     |_|_|I|_|_|
  ==================
  
)";
}

void printTheVillage()
{
  cout << "  === The Village ===" << endl;
  cout << "           |   _ " << endl;
  cout << "  |\\./.\\/.\\|.|. _" << endl;
  cout << "~~|.|_|.|_|.|.|.|_|.|~~" << endl;
  cout << "  ===================" << endl;
}

void printTheWall()
{
  cout << " === The Wall ===" << endl;
  cout << "___ ___ /|\\___ ___" << endl;
  cout << "___|___|(=)|___|___" << endl;
  cout << "___|___|`='|___|___" << endl;
  cout << " ================" << endl;
}

void printTheVale()
{
  cout << "=== The Vale ===" << endl;
  cout << "       |~" << endl;
  cout << "      /|\\ " << endl;
  cout << "     |-.-|" << endl;
  cout << "     '-:-'" << endl;
  cout << "      [|]" << endl;
  cout << "================" << endl;
}