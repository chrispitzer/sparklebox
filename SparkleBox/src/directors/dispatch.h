// To make sure you don't declare the function more than once by including
// the header multiple times.
#ifndef DIRECTOR_DISPATCH_H

  #define DIRECTOR_DISPATCH_H

typedef struct {
  uint32_t num_leds_configured;
  CRGB leds[MAX_LEDS];
  CRGB tempLeds[MAX_LEDS];
} test_led_struct_t;

  extern test_led_struct_t global_led_struct;

  void setupDirectors();
  void dispatchDirector();

#endif
