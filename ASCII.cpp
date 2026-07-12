#include <iostream>
#include <string>
#include <vector>
#include "ASCII.h"
#include "Game.h"
using namespace std;

void printMainHeader()
{
  cout << R"(
   __      __.__        __                    .__        
  /  \    /  \__| _____/  |_  ___________     |__| ______
  \   \/\/   /  |/    \   __\/ __ \_  __ \    |  |/  ___/
   \        /|  |   |  \  | \  ___/|  | \/    |  |\___ \ 
    \__/\  / |__|___|  /__|  \___  >__|       |__/____  >
             \/          \/          \/               \/ 
       _________                .__                
       \_   ___ \  ____   _____ |__| ____    ____  
       /    \  \/ /  _ \ /     \|  |/    \  / ___\ 
       \     \___(  <_> )  Y Y  \  |   |  \/ /_/  >  
        \______  /\____/|__|_|  /__|___|  /\___  / 
               \/             \/        \//_____/ 
  
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
  cout << R"(
   __      __.__        __         *          .__        
  /  \    /  \__| _____/  |_  ___________     |__| ______
  \   \/\/   /  |/    \   __\/ __ \_  __ \    |  |/  ___/
   \        /|  |   |  \  | \  ___/|  | \/    |  |\___ \ 
    \__/\  / |__|___|  /__|  \___  >__|       |__/____  >
             \/          \/          \/               \/ 
              ___ ___                        
    *        /   |   \   ___________   ____    *
            /    ~    \_/ __ \_  __ \_/ __ \ 
      *     \    Y    /\  ___/|  | \/\  ___/        *
             \___|_  /  \_____>__|    \_____>
                   \/
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

void printWin()
{
  cout << R"(
 _____.___.               __      __.__        
 \__  |   | ____  __ __  /  \    /  \__| ____  
  /   |   |/  _ \|  |  \ \   \/\/   /  |/    \ 
  \____   (  <_> )  |  /  \        /|  |   |  \
  / ______|\____/|____/    \__/\  / |__|___|  /
  \/                            \/          \/ 
          +++ WINTERFELL IS SAFE +++

  )";
}

void printLoss()
{
  cout << R"(
_____.___.              .____                        
\__  |   | ____  __ __  |    |    ____  ______ ____  
 /   |   |/  _ \|  |  \ |    |   /  _ \/  ___// __ \ 
 \____   (  <_> )  |  / |    |__(  <_> )___ \\  ___/
 / ______|\____/|____/  |_______ \____/____  >\___  > 
 \/                             \/                \/ 
          +++ WINTERFELL IS IN DANGER +++

  )";
}

void printKillPetyr()
{
  cout << R"(
  
  Sansa: Forgive me Lord Baelish, you told me never to trust you.

  Arya: I certainly never did.

    ====================
      Arya Kills Petyr
    ====================

  )";
}

void printPetyrTakeWinterfell()
{
  cout << R"(
  
  Petyr: It appears as though you have failed your people.

  Petyr: Fear not I will correct your mistake as the new Lord of Winterfell.

    ====================
    Petyr Takes The North
    ====================
    
  )";
}

string winterfellBanner()
{
  return R"(
  === Winterfell ===
      _   |~  _
     [_]--'--[_]
     | | /^\ | |
     |_|_|I|_|_|
  ==================
  
)";
}

string theVillageBanner()
{
  return R"(
  === The Village ===
           |   _ 
  |\ ./.\ /.\ |.|. _
~~|.|_|.|_|.|.|.|_|.|~~
  ===================

)";
}

string theWallBanner()
{
  return R"(
   === The Wall ===
  ___ ___ /|\ ___ ___
  ___|___|(=)|___|___
  ___|___|`='|___|___
   ================

)";
}

string theValeBanner()
{
  return R"(
  === The Vale ===
         |~
        /|\ 
       |-.-|
       '-:-'
        [|]
  ================

)";
}

void printBrienne()
{
  cout << R"(      .-.
    __|=|__
   (_/`-`\_)
   //\___/\\
   <>/   \<>
    \|_._|/
     <_I_>
      |||
     /_|_\

)";
}

void printSansa()
{
  cout << R"(
    mMm
   /(_)\
  //)^(\\
 /(/&@&\)\
/ /-~`~-\ \
`/       \'
 --------'

)";
}