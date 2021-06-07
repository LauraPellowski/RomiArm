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
    //grip.Set(1.0); // "Full Left"?
    grip.Set(0.2); // "Full Left"?
    //printf("grip position: %f\n",grip.GetRaw());
}

// Open grip
void Arm::Release() { 
    //grip.Set(0.0); 
    printf("Arm::Release\n");
    grip.Set(0.75); 
    //printf("grip position: %f\n",grip.GetRaw());
}

void Arm::Stop() {
    grip.Set(0.5);
}

void Arm::TiltUp() {
    wrist.Set(1.0);
}

void Arm::TiltDn() {
    wrist.Set(0.0);
}

void Arm::Lift() {
    shoulder.Set(1.0);
}

void Arm::Lower() {
    shoulder.Set(0.0);
}