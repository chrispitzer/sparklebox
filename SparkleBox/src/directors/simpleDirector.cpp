#include "simpleDirector.h"
#include "../patterns/patterns.h"


void setupSimpleDirector () {
  // this is here if we need setup stuff.
}


void tickSimpleDirector (uint32_t frameNumber) {


  // TODO - parse the scene info and pass it to the thingies.

  if (frameNumber % 200 < 100) {
    tickColorRotate();
  } else {
    tickRainbowSlugs();
  }
}
