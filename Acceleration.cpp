
#include "Acceleration.h"

Acceleration::Acceleration() {
    substate = pusherState;
}

int Acceleration::main() {
    int nextState = STATE_ACCEL;

    switch (substate) {
        case pusherState:
            Physics_setAccel(Physics_pusherAccel);

            // If pusher has disengaged, use prop
            if (getPusherState() == false) {
                Physics_setAccel(Physics_propAccel);
                substate = propState;
            }
            break;
        case propState:
            Physics_setAccel(Physics_propAccel);
            engagePropulsion();

            // Make sure there's fuel
            if (getPropulsionState() == true) {
                Physics_expendPropellant(); // Use fuel
            } else {
                nextState = STATE_COAST;

                // Turn off simulated prop
                Physics_setAccel(0.0);
            }

            break;
    }

    return nextState;
}

bool Acceleration::getPusherState() {
    // Assume pusher disengages after 480m
    return (Pod_getPosition() < 480);
}

bool Acceleration::getPropulsionState() {
    // Return true if there's propellant left
    return Pod_hasPropellant();
}

void Acceleration::engagePropulsion() {
    // Do nothing of interest. Handled by Physics.
}
