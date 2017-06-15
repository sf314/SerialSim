// Acceleration state header file

#ifndef _acceleration_h
#define _acceleration_h

#include "Physics.h"
#include "Constants.h"

#define pusherState 0
#define propState 1

class Acceleration {
public:
    Acceleration();
    int main();

    bool getPusherState();
    bool getPropulsionState();

    void engagePropulsion();
private:
    int substate; // pusher or prop
};

#endif
