#include "globals.h"
#include "animations/animations.h"
#include "utils/utils.h"


// Global data objects
globals_struct_t Globals;


void setup() {
  // TODO - we need to make this run based on a toggleable setting.
  Serial.begin(9600);
  delay(2000); // let you connect your serial monitor...

  // Set up all the animation libraries...
  AnimatorSetUpFunctions::setUpAllAnimations();

  // load in the flash memory...
  EEPROM::loadData();

  // Init the LEDs...
  instantiateLedStrips();
}


void loop() {
  Serial.println();
  Serial.println("----- in loop () -----");

  // -- RECIPE LOADER PHASE --
  // Load the recipe for the current animation from the buffer into memory.

  // -- RENDER PHASE --
  AnimationUtils::renderFrame();

  // -- OUTPUT PHASE --
  FastLED.show();
}
