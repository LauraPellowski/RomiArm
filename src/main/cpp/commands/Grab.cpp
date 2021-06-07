// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Grab.h"

Grab::Grab(Arm *arm) : m_arm(arm) {
  // Use AddRequirements() here to declare subsystem dependencies.
  AddRequirements(m_arm);
}

// Called when the command is initially scheduled.
void Grab::Initialize() {
  printf("Command->Grab\n");
  m_arm->Grab();
}

// Called repeatedly when this Command is scheduled to run
void Grab::Execute() {
}

// Called once the command ends or is interrupted.
void Grab::End(bool interrupted) {
  printf("Command->Grab Interrupted\n");
  m_arm->Stop();
}

// Returns true when the command should end.
bool Grab::IsFinished() {
  return false;
}
