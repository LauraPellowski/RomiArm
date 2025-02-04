// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Drivetrain.h"
#include "subsystems/Arm.h"

class AutoDrive
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 AutoDrive> {
 public:
  explicit AutoDrive(Drivetrain* drive, Arm* arm);

 private:
  Drivetrain* m_drive;
  Arm* m_arm;
};
