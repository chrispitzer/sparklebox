#include "animations.h"


namespace AnimationUtils {

  extern void setUpAllAnimations () {
    AnimationSetUpFunctions::ColorFadeSetUp();
  }

  extern void fillAllPixels (CHSV hsv) {
    CRGB rgb;
    hsv2rgb_rainbow(hsv, rgb);
    fillAllPixels(rgb);
  }

  extern void fillAllPixels (CRGB rgb) {
    fill_solid(
      CurrentAnimation.leds,
      CurrentAnimation.numberOfLeds,
      rgb
    );
  }

}
