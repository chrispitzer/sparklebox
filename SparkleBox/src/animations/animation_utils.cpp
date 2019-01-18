#include "animations.h"


// set up the `CurrentAnimation` workspace. And the LED data buffers.
CRGB ledBufferA[MAX_LEDS];
CRGB ledBufferB[MAX_LEDS];
animation_workspace_t CurrentAnimation{
  MAX_LEDS,
  ledBufferA
};


namespace AnimationUtils {

  extern void fillAllPixels (CHSV hsv) {
    CRGB rgb;
    hsv2rgb_rainbow(hsv, rgb);
    fillAllPixels(rgb);
  }

  extern void fillAllPixels (CRGB rgb) {
    // fill_solid(
    //   CurrentAnimation.leds,
    //   CurrentAnimation.numberOfLeds,
    //   rgb
    // );
  }

  extern void setUpCurrentAnimation () {
    // something about... look at settings for this scene or something...
    // But for right now let's set up CurrentAnimation for the animator we're
    // testing - colorFade!
    Animations::ColorFade.initializeAnimationMemory();
  }

}


namespace AnimationSetUpFunctions {
  extern void setUpAllAnimations () {
    ColorFadeSetUp();
  }
}

