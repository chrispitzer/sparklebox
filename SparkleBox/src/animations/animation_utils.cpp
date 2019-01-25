#include "animations.h"


// set up the `CurrentAnimation` workspace. And the LED data buffers.
CRGB ledBufferA[MAX_LEDS];
CRGB ledBufferB[MAX_LEDS];

animation_workspace_t CurrentAnimation{
  MAX_LEDS,
  ledBufferA
};


namespace AnimationUtils {

  extern void renderFrame () {
    // Render each layer and composite them together.
    // clearOutputLeds ();
    
    for (int i=0; i<1; i++) {
      renderLayer ();
      // mergeLayer ();
    }
  }

  extern void renderLayer () {
    // A 
    renderAnimation();
    for (int i=0; i<0; i++) {
      renderEffect();
    }
  }

  extern void renderAnimation () {

  }

  extern void renderEffect () {

  }

  extern void setUpCurrentAnimation () {
    // something about... look at settings for this scene or something...
    // But for right now let's set up CurrentAnimation for the animator we're
    // testing - colorFade!
    CurrentAnimation.numberOfPixels = 5;
    Animators::ColorFade.initMemory();
  }

}


// This proably needs to be deleted...
namespace AnimatorSetUpFunctions {
  extern void setUpAllAnimations () {
    ColorFadeSetUp();
  }
}

