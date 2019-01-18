#include "globals.h"
#include "animations/animations.h"
#include "utils/leds.h"
#include "directors/dispatch.h"


// Global data objects
globals_struct_t Globals;


void setup() {
  // TODO - we need to make this run based on a toggleable setting.
  Serial.begin(9600);

  // Set up all the animation libraries...
  AnimationSetUpFunctions::setUpAllAnimations();

  // load in the flash memory...
  EEPROM::loadData();

  // Init the LEDs...
  instantiateLedStrips();
}


void loop() {
  dispatchDirector();
}
