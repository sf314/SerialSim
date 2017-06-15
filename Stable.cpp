// Stable state implementation file

#include "Stable.h"

Stable::Stable() {
    // No init stuff
}

int Stable::main() {
    int nextState = STATE_STABLE;

    // If pusher acceleration is detected, move to Accel state
    if (Pod_getAccel() >= 2) {
        nextState = STATE_ACCEL;
    }

    return nextState;
}
