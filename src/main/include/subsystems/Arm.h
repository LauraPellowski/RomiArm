// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>

namespace ArmConstants {
constexpr int gripClosed = 2400;
constexpr int gripOpen = 600;
constexpr int maxWrist = 1900;
constexpr int minWrist = 600;
constexpr int maxShoulder = 1300;
constexpr int minShoulder = 600;

}  // namespace ArmConstants

class Arm : public frc2::SubsystemBase {
 public:
  Arm();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Grab();
  void Release();
  void Tilt();
  void Lift();

 private:

  int gripPos = ArmConstants::gripOpen;
  int wristPos = ArmConstants::maxWrist; // Fully "extended"
  int shoulderPos = ArmConstants::maxShoulder; // Lowered

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Servo grip{4}; // Grab/Release object on PWM 2 (Romi Ext 2)
  frc::Servo wrist{5}; // Tilts grip up/down on PWM 3 (Romi Ext 3)
  frc::Servo shoulder{6} ; // Raises/lowers arm on PWM 4 (Romi Ext 4)

};
