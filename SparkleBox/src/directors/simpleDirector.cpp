#include "simpleDirector.h"
#include "../patterns/patterns.h"


// scenes

void setupSimpleDirector () {
  // prepare scenes here...?

  // this is here if we need setup stuff.
}


void prepareNextPattern () {

}


void tickSimpleDirector (uint32_t frameNumber) {
  colorAllLeds(CRGB(0,0,frameNumber%255));
  FastLED.show();

  /*

  // TODO - parse the scene info and pass it to the thingies.

  if (frameNumber % 300 = 0) {
    prepareNextScene();
  }
    patternSettings.
    tickColorRotate();
  } else {
    tickRainbowSlugs();
  }
  */
}
