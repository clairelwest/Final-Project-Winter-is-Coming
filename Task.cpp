#include <iostream>
#include <string>
#include <vector>
#include "Task.h"
using namespace std;

Task::Task(int i)
{
  index = i;
  switch (index)
  {
  case BUYMUTTON:
    name = "Buy Mutton";
    break;
  case BUYPOTATOES:
    name = "Buy Potatoes";
    break;
  case BUYFIREWOOD:
    name = "Buy Firewood";
    break;
  case CHOPFIREWOOD:
    name = "Chop Firewood";
    break;
  case INSPIRECONFIDENCE:
    name = "Inspire Confidence";
    break;
  }
}

string Task::getName()
{
  return name;
}

int Task::getIndex()
{
  return index;
}