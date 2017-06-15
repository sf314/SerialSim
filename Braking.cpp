// Braking state implementation file

#include "Braking.h"

Braking::Braking() {
    // Empty initializer
}

int Braking::main() {
    int nextState = STATE_BRAKE;

    float x = Pod_getPosition();
    float v = Pod_getVelocity();
    float a = Pod_getAccel();

    // Check velocity. Only use friction below threshold.
    if (v > BRAKING_LOWSPEED_THRESHOLD) {
        // Modulate Eddy Current brakes
        float tgtAccel = requiredAccel(v, x);
        float brakePercent = brakePercentFromAccel(tgtAccel);
        actuateEddyBrakes(brakePercent);
    } else {
        // Activate friction brakes
        actuateFrictionBrakes();

        if (v <= 0) {
            nextState = STATE_OFF;
            Physics_setAccel(0.0);
        }
    }

    return nextState;
}

float Braking::requiredAccel(float v, float x) {
    return ((0 - vel * vel) / (2 * (TARGET_POS - pos)));
}

float Braking::brakePercentFromAccel(float ac) {
    // Calculate amount to apply brakes based on desired deceleration
    // Here, basically map desired accel to maximum
    // 0 for no deployment, 1 for full deployment
    return (float)(ac / BRAKING_EDDY_MAX);
}

void Braking::actuateEddyBrakes(float percent) {
    // Apply brake percentage.
    // 0 amount = no actuation (0 m/s2), 1 amount = full actuation (-54 m/s2)
    Physics_setAccel(percent * BRAKING_EDDY_MAX);
}

void Braking::actuateFrictionBrakes() {
    Physics_setAccel(Physics_brakeAccelFriction);
}
