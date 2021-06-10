// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDrive.h"
#include "commands/DriveDistance.h"
#include "commands/Grab.h"
#include "commands/Release.h"
#include "commands/TurnDegrees.h"
#include "commands/Delay.h"
#include <units/angle.h>
#include <units/time.h>
#include <units/length.h>

double m_speed = 1.0;
auto m_distance = 80_in;
auto m_angle = 45_deg;
auto m_time = 20_s;

// :)
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoDrive::AutoDrive(Drivetrain* drive, Arm* arm) : m_drive(drive), m_arm(arm) {

  /*
From Kyle:
3 independent commands that are in parallel, not series:
(1) Delay a seconds, drive backwards for b seconds
(2) spin up shooter, delay c seconds, turn off shooter
(3) delay d seconds, turn jumbler for e seconds, turn off jumbler
That would allow for shoot then scoot or scoot then shoot by changing delays and durations, as required by our reliable minimum shooting range.

From Laura:

straight go through:
  (1) turn on spinner to pick up balls
  (2) drive forward for __ inches

  option 1
  (3) rotate right 90 degrees
  (4) drive forward for __ inches
  (5) rotate left 90 degrees
  (6) drive forward __ inches
  (7) reverse direction of spinner to spit out balls

  option 2
  (3) rotate right ~45 degrees
  (4) reverse direction of spinner to spit out balls
*/

/*
AddCommands (
    frc2::SequentialCommandGroup{ AutoDelay(a), 
                                  frc2::ParallelRaceGroup{ AutoDriveDistance(drivetrain, b), AutoDelay(5.0) }
                                },
    frc2::ParallelRaceGroup{ SpinUpShooter(shooter), AutoDelay(c) },
    frc2::SequentialCommandGroup{ AutoDelay(d),
                                  frc2::ParallelRaceGroup{ JumbleShooter(shooter, -1), AutoDelay(e) }
                                }
*/

AddCommands(
frc2::ParallelDeadlineGroup{
  Delay(m_time),
  frc2::SequentialCommandGroup{
    frc2::ParallelDeadlineGroup{ Grab(arm), 
      frc2::SequentialCommandGroup{ DriveDistance(m_speed, m_distance, m_drive), TurnDegrees(m_speed, m_angle, m_drive)},
    Release(arm)}}}
  );
}
