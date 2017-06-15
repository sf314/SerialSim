#ifndef PHY_h
#define PHY_h

// Variables

// Time varables
extern long currentTime;
extern long previousTime;
extern long deltaT;

// Assumed constants
extern float Physics_pusherAccel;
extern float Physics_propAccel;
extern float Physics_brakeAccelFriction;

// Physical variables
extern float pos;
extern float vel;
extern float acc;
extern float maxSpeed;

// Resources
extern float propellant;
extern float massFlowRate;

// Functions
void Physics_update(void);

float Physics_getAccel(void);

float Physics_getVelocity(void);

float Physics_getPosition(void);

// Important for doing stuff involving accel or brakes!
void Physics_setAccel(float x);

void Physics_printTelemetry(void);

void Physics_expendPropellant(void);

bool Pod_hasPropellant(void);

float Pod_getPosition(void);
float Pod_getVelocity(void);
float Pod_getAccel(void);



#endif
