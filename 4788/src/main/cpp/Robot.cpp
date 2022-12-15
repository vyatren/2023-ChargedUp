#include "Robot.h"


using namespace frc;

double currentTimeStamp;
double lastTimeStamp;
double dt = 0;


void Robot::RobotInit() {
  robotMap.lasSys.doubleSolenoid = new DoubleSolenoid(99, frc::PneumaticsModuleType::CTREPCM, 99, 99);
  robotMap.lasSys.xboxController = new XboxController(0);
  robotMap.lasSys.spark = new Spark(99);
  robotMap.lasSys.sparkMax = new rev::CANSparkMax(99, rev::CANSparkMax::MotorType::kBrushless);

  las = new Las(robotMap.lasSys);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  las->solenoidHandler();
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}


