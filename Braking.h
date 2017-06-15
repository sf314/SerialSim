// Braking state header file

#ifndef _braking_h
#define _braking_h

#include "Physics.h"
#include "Constants.h"

class Braking {
public:
    Braking();
    int main();
private:
    float requiredAccel(float v, float x);
    float brakePercentFromAccel(float a);
    void actuateEddyBrakes(float percent);
    void actuateFrictionBrakes();
};

#endif
