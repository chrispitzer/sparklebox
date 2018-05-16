// without this interrupts setting FastLED will crash the ESP32. Fun!
// #define FASTLED_ALLOW_INTERRUPTS 0

// libraries
#include "simpleDirector.h"
// #include "Arduino.h"
// #include "FastLED.h"
// #include "dispatch.h"


void setupSimpleDirector () {
  // this is here if we need setup stuff.
}

void tickSimpleDirector (uint32_t frameNumber) {
  // make the rainbow
  uint8_t currentColor = frameNumber % 255; // intentionally 1 byte to roll over after 255
  uint16_t currentStripLength;
  uint16_t currentStripOffset = 0;

  for (uint16_t stripIndex=0; stripIndex < globalLeds.numberOfStrips; stripIndex++) {
    currentStripLength = globalLeds.numberOfLedsInStrip[stripIndex];
    for (uint16_t ledIndex=0; ledIndex < currentStripLength; ledIndex++) {
      globalLeds.leds[currentStripOffset + ledIndex].setHSV(currentColor, 255, 255);
      currentColor++;
    }
    currentStripOffset += currentStripLength;
  }
}
