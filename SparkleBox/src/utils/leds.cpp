#include "leds.h"


void colorAllExistingLeds (CRGB color) {
  fill_solid(globalLeds.leds, globalLeds.totalNumberOfLeds, color);
  fill_solid(globalLeds.sceneWorkingLeds, globalLeds.totalNumberOfLeds, color);
  fill_solid(globalLeds.patternWorkingLeds, globalLeds.totalNumberOfLeds, color);
}

void blackAllLeds () {
  colorAllExistingLeds(CRGB(0,0,0));
}

void redAllLeds () {
  colorAllExistingLeds(CRGB(255,0,0));
}

void greenAllLeds () {
  colorAllExistingLeds(CRGB(0,255,0));
}

void blueAllLeds () {
  colorAllExistingLeds(CRGB(0,0,255));
}