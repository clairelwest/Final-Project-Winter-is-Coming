#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task
{
private:
  string name;
  int index;

public:
  static constexpr int BUYMUTTON = 0;
  static constexpr int BUYPOTATOES = 1;
  static constexpr int BUYFIREWOOD = 2;
  static constexpr int CHOPFIREWOOD = 3;
  static constexpr int INSPIRECONFIDENCE = 4;
  Task(int i);
  string getName();
  int getIndex();
};

#endif