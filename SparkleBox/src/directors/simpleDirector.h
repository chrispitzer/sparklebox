// To make sure you don't declare the function more than once by including
// the header multiple times.
#ifndef SIMPLE_DIRECTOR_H

  #define SIMPLE_DIRECTOR_H
  #include "FastLED.h"
  #include "dispatch.h"

  void setupSimpleDirector ();
  /*
  void tickSimpleDirector(
    CRGB leds[],
    unsigned int numberOfLeds,
    unsigned int frameNumber
  );
  */
  void tickSimpleDirector (
    test_led_struct_t *led_struct_ptr,
    unsigned int frameNumber
  );

#endif
