#include "patterns.h"

// intentionally 1 byte to roll over after 255
uint8_t currentColor = 0;

// .....hm..... I want to put currentColor out here, but
// that means that this will trample other instances of itself.....
///////// do we need to pass in an object that is a sort of data locker that will be passed
// back to this frame later........????????
int16_t speed = 1;


// void ensureSettingsAreValid () {
//   if (speed > 255) {
//     speed = 255;
//   }
//   if (speed < -255) {
//     speed = -255;
//   }
// }


// void loadSettings () {
//   // frameNumber = patternSettings.frameNumber;
//   // speed = static_cast<int16_t>(patternSettings.settingA);
//   // ensureSettingsAreValid();
// }

void colorAllllLeds (CRGB color) {
  fill_solid(globalLeds.leds, globalLeds.totalNumberOfLeds, color);
  Serial.println("make it a color!");
  // fill_solid(globalLeds.sceneWorkingLeds, globalLeds.totalNumberOfLeds, color);
}


void ColorRotate () {
  currentColor += speed;

  // HSV (Rainbow) to RGB color conversion
  CHSV hsv( currentColor, 255, 255); // pure blue in HSV Rainbow space
  CRGB rgb;
  hsv2rgb_rainbow( hsv, rgb);
  // rgb will now be (0, 0, 255)  -- pure blue as RGB



  colorAllllLeds(rgb);
  // loadSettings();

  // currentColor = frameNumber % 255;


  
  Serial.println("Color Rotate!");
  // TODO - it would be really great if this could be called with just an array it dumps data into.
  // that way it wouldn't need to be aware of the whole shebang.


/*


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

  */

}
