// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Release.h"

Release::Release(Arm *arm) : m_arm(arm) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_arm);
}

// Called when the command is initially scheduled.
void Release::Initialize() {
  printf("Command->Release\n");
  m_arm->Release();
}

// Called repeatedly when this Command is scheduled to run
void Release::Execute() {
}

// Called once the command ends or is interrupted.
void Release::End(bool interrupted) {
  printf("Command->Release Interrupted\n");
  m_arm->Stop();
}

// Returns true when the command should end.
bool Release::IsFinished() {
  return false;
}
