// Constants.h
// Place all constants here

#ifndef _constants_h
#define _constants_h

// ********** State Constants *************************************************
#define STATE_EMERGENCY    -1          // Emergency State; Check all systems. Engage any safety protocals necessary.
#define STATE_OFF           0           // Off command. System shutdown.
#define STATE_STABLE        1           // Stable State;, waiting for command from operating termanal.
#define STATE_ACCEL         2           // Acceleration State; Accellerate down the track.
#define STATE_COAST         3           // Coasting State; Coasting down the track, checking location
#define STATE_BRAKE         4           // Braking State; Engage brakeing and prepare for stop.

// ********** Mission Constants ***********************************************
// In metres
#define TARGET_POS 1609

// ********** Systems Constants ***********************************************
#define  PASS     0
#define  FAIL     1

// ********** Waiting/Starting Constants **************************************

// ********** Accelerating Constants ******************************************

// ********** Coasting Constants **********************************************

// ********** Braking Constants ***********************************************
#define BRAKING_LOWSPEED_THRESHOLD 5.0
#define BRAKING_EDDY_MAX -54

#endif
