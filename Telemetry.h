// Printing Telemetry

#ifndef _telemetry_h
#define _telemetry_h

#include "Arduino.h"
#include "Physics.h"

void Telemetry_send() {
    Serial.print("TELEM, ");
    Serial.print(Pod_getPosition()) + Serial.print(", ");
    Serial.print(Pod_getVelocity()) + Serial.print(", ");
    Serial.print(Pod_getAccel()) + Serial.print(", ");
    Serial.print(3 * sin(0 + ((float)currentTime / 1000.0) + 21)); Serial.print(", ");
    Serial.print(2 * sin(1 + ((float)currentTime / 1000.0) + 18)); Serial.print(", ");
    Serial.print(6 * sin(2 + ((float)currentTime / 1000.0) + 12)); Serial.println();

}

#endif
