#pragma once

#include <string>
#include "RobotMap.h"



class Las {
 public:
  Las(RobotMap::LasSys &lasSys); // pass by reference 

  void OnUpdate(double dt); // delta time
  void solenoidHandler();
  void sparkHandler();
 private:
  const double motorInputDeadzone = 0.15;

  bool isPressed, isExtended, wasPressed = false;
  double motorAngVelPercentage;
  RobotMap::LasSys &_lasSys;
};


