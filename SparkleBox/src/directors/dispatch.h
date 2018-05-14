// To make sure you don't declare the function more than once by including
// the header multiple times.
#ifndef DIRECTOR_DISPATCH_H

  #define DIRECTOR_DISPATCH_H
  #include "FastLED.h"

// Pixel and Microcontroller settings
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define MAX_LEDS 3000
  typedef struct {
    uint32_t num_leds_configured;
    CRGB leds[MAX_LEDS]; // 3000 should come from MAX_LEDS in dispatch.cpp...
    CRGB tempLeds[MAX_LEDS];
  } test_led_struct_t;

  extern test_led_struct_t global_led_struct;

  void startDirector();
  // void setupDirectors();
  // void dispatchDirector();

#endif
