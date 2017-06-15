// Coast state implementation file

#include "Coast.h"

Coast::Coast() {
    targetBuffer = 10; // For calculations, stop the pod 10m before target.
}

int Coast::main() {
    int nextState = STATE_COAST;

    if (brakeDistanceMet()) {
        nextState = STATE_BRAKE;
        Physics_setAccel(BRAKING_EDDY_MAX);
    }

    return nextState;
}

bool Coast::brakeDistanceMet() {
    // Check for braking distance
    float x = Pod_getPosition();
    float v = Pod_getVelocity();
    float a = BRAKING_EDDY_MAX;
    float tgt = TARGET_POS - targetBuffer;

    // Calculate suicide burn distance
    float brakeStartPosition = tgt + ((v * v) / (2 * a));

    // Check if passed brake start position
    if (x >= brakeStartPosition) {
        return true;
    } else {
        return false;
    }
}
