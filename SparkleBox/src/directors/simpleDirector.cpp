#include "simpleDirector.h"


void setupSimpleDirector () {
  // this is here if we need setup stuff.
}


void tickSimpleDirector (uint32_t frameNumber) {
  // start the rainbow based on the frame number. This will slide it to
  // the "right" over time.
  uint8_t currentColor = frameNumber % 255; // intentionally 1 byte to roll over after 255

  // CHSV hsv;
  // CRGB rgb;

  CHSV hsv( currentColor, 255, 255); // pure blue in HSV Rainbow space
  CRGB rgb;
  hsv2rgb_rainbow( hsv, rgb);
  colorAllLeds(rgb);

  // for (uint16_t ledIndex=0; ledIndex < globalLeds.totalNumberOfLeds; ledIndex++) {

  //     hsv.setHSV( currentColor, 255, 255); // pure blue in HSV Rainbow space
  //     hsv2rgb_rainbow( hsv, rgb);

  //     globalLeds.leds[ledIndex] = rgb;

  //     currentColor+=13;
  //     Serial.println(currentColor);
  // }
}
