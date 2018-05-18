#include "simpleDirector.h"


void setupSimpleDirector () {
  // this is here if we need setup stuff.
}


void tickSimpleDirector (uint32_t frameNumber) {
  // start the rainbow based on the frame number. This will slide it to
  // the "right" over time.
  uint8_t currentColor = frameNumber % 255; // intentionally 1 byte to roll over after 255

  for (uint16_t ledIndex=0; ledIndex < globalLeds.totalNumberOfLeds; ledIndex++) {
      globalLeds.leds[ledIndex].setHSV(currentColor, 255, 255);
      currentColor++;
    }
  }
}
