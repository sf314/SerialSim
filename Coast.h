// Coast state header file

#ifndef _coast_h
#define _coast_h

#include "Physics.h"
#include "Constants.h"

/*
Responsible for calculating absolute last moment to brake (buffer?)
*/

class Coast {
public:
    Coast();
    int main();
private:
    bool brakeDistanceMet();
    float targetBuffer;
};

#endif
