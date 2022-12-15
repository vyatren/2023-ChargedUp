#include "liamcode.h"


Las::Las(RobotMap::LasSys &lasSys) : _lasSys(lasSys) {}

void Las::OnUpdate(double dt){
    solenoidHandler();
    sparkHandler();
}
void Las::solenoidHandler(){
  if (!wasPressed){
    if (_lasSys.xboxController->GetLeftBumperPressed()){
      wasPressed = true;
       if (isExtended) { // retract
        _lasSys.doubleSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
        
      } else{ // extend
        _lasSys.doubleSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
      }
    }
    if (_lasSys.xboxController->GetLeftBumperReleased()){
      wasPressed = false;
    }
  }
}
void Las::sparkHandler(){
  // left trigger = anticlockwise (shaft pointing out)
  // right trigger = clockwise (shaft pointing out)
  motorAngVelPercentage = _lasSys.xboxController->GetRightTriggerAxis() - _lasSys.xboxController->GetLeftTriggerAxis();
  if (abs(motorAngVelPercentage) > motorInputDeadzone){
    _lasSys.sparkMax->Set(motorAngVelPercentage);
  } else {
    _lasSys.sparkMax->Set(0);
  }
}