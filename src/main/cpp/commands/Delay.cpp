// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Delay.h"

Delay::Delay(units::second_t time) : m_time(time) {
  // Use addRequirements() here to declare subsystem dependencies.
  m_timer = frc::Timer();
}

// Called when the command is initially scheduled.
void Delay::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
//void Delay::Execute() {}

// Called once the command ends or is interrupted.
//void Delay::End(bool interrupted) {}

// Returns true when the command should end.
bool Delay::IsFinished() {
  return m_timer.Get() > m_time.to<double>();
}
