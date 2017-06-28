// Printing Telemetry

#ifndef _telemetry_h
#define _telemetry_h

#include "Arduino.h"
#include "Physics.h"

void Telemetry_send() {
    float tel1 = 3 * sin(0 + ((float)currentTime / 1000.0) + 21);
    float tel2 = 3 * sin(1 + ((float)currentTime / 1000.0) + 18);
    float tel3 = 3 * sin(2 + ((float)currentTime / 1000.0) + 12);

    // Updated for new telemetry format!
    Serial.println("DAT, 1, " + String(Pod_getPosition));
    Serial.println("DAT, 2, " + String(Pod_getVelocity));
    Serial.println("DAT, 3, " + String(Pod_getAccel));

    Serial.println("DAT, 4, " + String(tel1));
    Serial.println("DAT, 5, " + String(tel2));
    Serial.println("DAT, 6, " + String(tel3));
}

#endif
