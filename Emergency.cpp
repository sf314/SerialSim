// Emergency state implementation file

#include "Emergency.h"

Emergency::Emergency() {
    // Empty initializer
}

int Emergency::main() {
    int nextState = STATE_EMERGENCY;

    // 1. Ensure pusher is disengaged
    if (Pod_getPosition() < 480) {
        Physics_setAccel(0.0);
        return nextState;
    }

    // 2. Deploy brakes
    Physics_setAccel(-64.0); // Both eddy and friction;

    // 3. State change condition
    if (Pod_getVelocity() < 0.5) {
        nextState = STATE_OFF;
    }

    return nextState;
}
