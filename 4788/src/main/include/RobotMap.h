#pragma once
#include <string>

#include <frc/TimedRobot.h>
#include <frc/DoubleSolenoid.h>
#include <frc/XboxController.h>
#include <frc/motorcontrol/Spark.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SendableChooser.h>
// #include "startup.h"
// #include "RobotStart.h"
// #include "RobotStartup.h"

#include <ctre/Phoenix.h>

// #include <frc/RobotBase.h>

struct RobotMap {
    struct LasSys {
        frc::DoubleSolenoid *doubleSolenoid;
        frc::XboxController *xboxController;
        frc::Spark *spark;
        rev::CANSparkMax *sparkMax;
    }; LasSys lasSys;
};