#include "animations.h"


// working variables
CRGB tempRGB;

namespace DrawingUtils {

  extern void fillAllPixels (CHSV hsv) {
    hsv2rgb_rainbow(hsv, tempRGB);
    fillAllPixels(tempRGB);
  }

  extern void fillAllPixels (CRGB rgb) {
    fill_solid(
      CurrentAnimation.leds,
      CurrentAnimation.numberOfPixels,
      rgb
    );
  }

}
