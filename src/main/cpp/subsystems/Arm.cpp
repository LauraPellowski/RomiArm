// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Arm.h"

Arm::Arm() = default;

// This method will be called once per scheduler run
void Arm::Periodic() {}

// Close grip
void Arm::Grab() {
    printf("Arm::Grab\n");
    grip.Set(1.0); // "Full Left"?
    printf("grip position: %f\n",grip.GetRaw());
//    wrist.Set(0.0);
//    wrist.SetRaw(2400);
//   shoulder.Set(0.0);
//    shoulder.SetRaw(2400);
}

// Open grip
void Arm::Release() { 
    grip.Set(0.0); 
    printf("Arm::Release\n");
    printf("grip position: %f\n",grip.GetRaw());
//    wrist.Set(1.0);
//    wrist.SetRaw(600);
//    shoulder.Set(1.0);
//    shoulder.SetRaw(600);
}

void Arm::Tilt() {

}

void Arm::Lift() {

}
