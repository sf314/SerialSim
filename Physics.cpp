// Model physics in this simulated universe!

#include "Physics.h"

#include "Arduino.h"

// Time varables
long currentTime = 0;
long previousTime = 0;
long deltaT = 10; // 0.005 physics tick

// Assumed constants
float Physics_pusherAccel = 9.8;
float Physics_propAccel = 7.91;
float Physics_brakeAccelFriction = -10.0;

// Physical variables
float pos = 0.0;
float vel = 0.0;
float acc = 0.0;
float maxSpeed = 0.0;

// Resources
float propellant = 48.3;
float massFlowRate = 23.0;

// Functions
void Physics_update() {
    float dT = (float)(currentTime - previousTime) / 1000.0;
    // Calculate physical variables
    vel = vel + acc * dT;
    pos = pos + vel * dT + 0.5 * acc * dT * dT;

    // Keep track of maxSpeed
    if (vel > maxSpeed) {
        maxSpeed = vel;
    }

    // Increment time in loop()
    previousTime = currentTime;
}

float Physics_getAccel() {
    return acc;
}

float Physics_getVelocity() {
    return vel;
}

float Physics_getPosition() {
    return pos;
}

// Important for doing stuff involving accel or brakes!
void Physics_setAccel(float x) {
    acc = x;
}

void Physics_expendPropellant() {
    propellant = propellant - (massFlowRate * deltaT);
}

bool Pod_hasPropellant() {
    return (propellant > 0);
}

float Pod_getPosition() {
    return pos;
}
float Pod_getVelocity() {
    return vel;
}
float Pod_getAccel() {
    return acc;
}
