#include "dispatch.h"
#include "../animations/animations.h"
// #include "../utils/data.h"
// #include "../utils/leds.h"

// working variables
uint32_t frameNumber = 0;
uint8_t selectedDirector = 0;


void dispatchDirector () {

  // STEP 1
  // set all LEDs to black.


  // STEP 2
  // Run one animator
  // pipe that to the output pixels
  // run another animator
  // pipe that to the output pixels on top of the first signal
  // send that to the LED strip.

  // get this calling an animator.
  // Pipe that animator to the output pixels.
  // Send that to the LED strip.
  Animations::ColorFade.animate();
  // ColorRotate();
  FastLED.show();
  delay(10);


  // STEP 3
  // Have a concept of an oscilator


  // STEP 4
  // pipe the oscilator to the animator


}
