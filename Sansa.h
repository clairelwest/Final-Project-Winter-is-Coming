#ifndef SANSA_H
#define SANSA_H

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Task.h"
#include "Location.h"
using namespace std;

class Sansa : public Character
{
private:
  int respect;
  int gold;
  int mapPosition;
  int mutton;
  int potatoes;
  int arrows;
  int firewood;
  int blankets;
  bool killPetyr;
  int confidencePoints;
  void interactBrienne(int cD);
  void interactArya();
  void interactJon();
  void interactPetyr();
  void buyMutton();
  void buyPotatoes();
  void buyFirewood();
  void chopFirewood();
  void inspireConfidence();

public:
  Sansa(int r, int g, int mP);
  int chooseAction();
  void travel(vector<Location> map);
  int getRespect();
  int getGold();
  int getMapPosition();
  bool getKillPetyr();
  void addRespect(int cR);
  void addGold(int g);
  bool setMapPosition(int t);
  void printInventory();
  void interact(Character c, int cD);
  void completeTask(Task t);
  void printStatus();
  bool bundleComplete();
};

#endif