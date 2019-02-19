#include "animations.h"


// set up the `CurrentAnimation` workspace. And the LED data buffers.
CRGB ledBufferA[MAX_LEDS];
CRGB ledBufferB[MAX_LEDS];

animator_workspace_t CurrentAnimation{
  MAX_LEDS,
  ledBufferA
};

/*
const CurrentFrameSpecs = [
  {
    animation: {
      animator: ponter to some animator
      settings: [
        10,
        20,
        30,
        40,
        50
      ]
    },
    effect: {
      // hold for version 0.2
    },
    opacity: 0.75
  },
  {
    animation: {
      animator: ponter to some animator
      settings: [
        10,
        20,
        30,
        40,
        50
      ]
    },
    effect: {
      // hold for version 0.2
    },
    opacity: 0.75
  }
]


*/



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
    // hold for version 0.2
  }

  extern void setUpCurrentAnimation () {
    // something about... look at settings for this frame or something...
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

