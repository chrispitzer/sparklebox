// To make sure you don't declare the function more than once by including
// the header multiple times.
#ifndef DIRECTOR_DISPATCH_H

  #define DIRECTOR_DISPATCH_H
  #include "FastLED.h"

  typedef struct {
    uint32_t num_leds_configured;
    CRGB leds[3000]; // 3000 should come from MAX_LEDS in dispatch.cpp...
    CRGB tempLeds[3000];
  } test_led_struct_t;

  extern test_led_struct_t global_led_struct;

  void startDirector();
  // void setupDirectors();
  // void dispatchDirector();

#endif
