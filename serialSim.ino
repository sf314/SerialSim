// Simulate pod telemetry via serial commands
// Based on AZLoop/sim terminal simulation (but with serial commands!)
// It's an interactive simulator!

#include <Arduino.h>
#include <math.h>

#include "Physics.h"
#include "Constants.h"

#include "Stable.h"
#include "Acceleration.h"
#include "Coast.h"
#include "Braking.h"
#include "Emergency.h"

#include "Telemetry.h"

// Create state objects
Stable stable;
Acceleration accel;
Coast coast;
Braking brake;
Emergency emergency;

long startTime = 0;

void setup() {
    Serial.begin(9600);
    delay(500);
    Serial.println("Welcome to the simulator");
    delay(500)

    Serial.println("Providing telem fields");
        Serial.println("ID, 1, Position");
        Serial.println("ID, 2, Velocity");
        Serial.println("ID, 3, Accel");
        Serial.println("ID, 4, Tel1");
        Serial.println("ID, 5, Tel2");
        Serial.println("ID, 6, Tel3");
    delay(500)
    
    Serial.println("Entering stable state...");
    delay(1000);

    // Special loop to handle Stable state
    stableStateLoop();

    startTime = millis();
}

// Init state information
int currentState = STATE_ACCEL;
int nextState = STATE_ACCEL;

void loop() {
    // Keep time updated
    currentTime = millis() - startTime;

    // Parse incoming commands
    if (Serial.available()) {
        char c = Serial.read();
        parse(c);
        Serial.println("Received " + c);
    }

    // Main runloop
    if (1) {
        // Calculate physics
        Physics_update();

        // Switch on state
        switch (currentState) {
            case STATE_STABLE:
                nextState = stable.main();
                break;
            case STATE_ACCEL:
                nextState = accel.main();
                break;
            case STATE_COAST:
                nextState = coast.main();
                break;
            case STATE_BRAKE:
                nextState = brake.main();
                break;
            case STATE_EMERGENCY:
                nextState = emergency.main();
                break;
            case STATE_OFF:
                // Do things before shutting down
                break;
            default:
                Serial.println("Invalid state");
                nextState = STATE_EMERGENCY;
                break;
        }

        //nextState = // Systems stuff

        // Set next state
        currentState = nextState;

        // Update time
        //previousTime = currentTime;

        // Send telemetry
        Telemetry_send();
    }

    // Do nothing if you're off
    if (currentState == STATE_OFF) {
        Serial.println("Final speed achieved: " + String(maxSpeed));
        Serial.println("Runtime: " + String(float(currentTime) / 1000.0));
        while (1);
    }

}












// ********** Stable state loop ************************************************
float stableStateLoop() {
    bool loaded = false;
    bool ready = false;

    Serial.println("Press 'x' to load pod");

    while (!loaded) {
        if (Serial.available()) {
            char c = Serial.read();
            switch (c) {
                case 'x':
                    loaded = true;
                    delay(500);
                    break;
                default:
                    Serial.println("Nope, try again");
            }
        }
    }

    Serial.println("Push start ('s') to begin");

    while (!ready) {
        if (Serial.available()) {
            char c = Serial.read();
            switch (c) {
                case 's':
                    ready = true;
                    Physics_setAccel(Physics_pusherAccel);
                    break;
                default:
                    Serial.println("Nope, try again");
            }
        }
    }

    // Now commence the run
}

// ********** Runtime command parsing logic ************************************
void parse(char c) {
    switch (c) {
        case 'x': // Emergency stop command
            nextState = STATE_EMERGENCY;
            break;
    }
}
