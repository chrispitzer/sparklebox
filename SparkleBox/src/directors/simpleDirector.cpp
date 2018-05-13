// without this interrupts setting FastLED will crash the ESP32. Fun!
#define FASTLED_ALLOW_INTERRUPTS 0

// libraries
#include "Arduino.h"
#include "FastLED.h"

// working variables
unsigned short int numLeds;


void setupSimpleDirector (unsigned short int _numLeds) {
  numLeds = _numLeds;
}


unsigned char startingColorForFrame = 0;
CRGB* tickSimpleDirector (unsigned int frameNumber) {
  CRGB leds[numLeds];

  // rotate the starting color - this will move the rainbow to the right
  // frame by frame;
  startingColorForFrame++;

  // make the rainbow
  unsigned char currentColor = startingColorForFrame;
  for (int i; i<numLeds; i++) {
    leds[i].setHSV(currentColor, 255, 255);
    currentColor++;
  }

  return leds;
}
