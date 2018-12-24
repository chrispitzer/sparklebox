#include "dispatch.h"

// working variables
uint32_t frameNumber = 0;
uint8_t selectedDirector = 0;


void setupDirectors () {
  loadDataFromEEPROM();
  instantiateLedStrips();
}


void dispatchDirector () {

  // STEP 1
  // get this calling an animator.
  // Pipe that animator to the output pixels.
  // Send that to the LED strip.
  blackAllLeds();
  Animations::ColorRotate.animate();
  // ColorRotate();
  FastLED.show();
  delay(10);



  // STEP 2
  // Run one animator
  // pipe that to the output pixels
  // run another animator
  // pipe that to the output pixels on top of the first signal
  // send that to the LED strip.



  // STEP 3
  // Have a concept of an oscilator


  // STEP 4
  // pipe the oscilator to the animator


}
