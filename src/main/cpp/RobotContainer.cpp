// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/button/Button.h>

#include "commands/TeleopArcadeDrive.h"

RobotContainer::RobotContainer() : m_autodrive(&m_drive, &m_arm) {
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {

  frc2::Button([this] {return m_controller.GetRawButton(5); }).WhileHeld(new Grab(&m_arm));
  frc2::Button([this] {return m_controller.GetRawButton(6); }).WhileHeld(new Release(&m_arm));
 
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(4); }));

  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(frc2::PrintCommand("Button A Pressed"))
      .WhenReleased(frc2::PrintCommand("Button A Released"));

  // Setup SmartDashboard options.
  // m_chooser.SetDefaultOption("Mondrian Map", &m_autoMondrian);
  // m_chooser.AddOption("Auto Routine Distance", &m_autoDistance);
  // m_chooser.AddOption("Auto Routine Time", &m_autoTime);
  frc::SmartDashboard::PutData("Auto Selector", &m_chooser);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return &m_autodrive;
}
