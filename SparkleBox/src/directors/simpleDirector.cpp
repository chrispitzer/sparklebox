// without this interrupts setting FastLED will crash the ESP32. Fun!
#define FASTLED_ALLOW_INTERRUPTS 0

// libraries

#include "Arduino.h"
#include "FastLED.h"
#include "dispatch.h"

// working variables
unsigned char startingColorForFrame = 0;

void setupSimpleDirector () {
  // this is here if we need setup stuff.
}

void tickSimpleDirector (
    test_led_struct_t *led_struct_ptr,
    unsigned int frameNumber
  ) {
  // rotate the starting color - this will move the rainbow to the right
  // frame by frame;
  startingColorForFrame++;

  // make the rainbow
  unsigned char currentColor = startingColorForFrame;
  for (int i; i < led_struct_ptr->num_leds_configured; i++) {
    led_struct_ptr->leds[i].setHSV(currentColor, 255, 255);
    currentColor++;
  }
}
