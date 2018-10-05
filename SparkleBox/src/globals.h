#ifndef GLOBALS_H
  #define GLOBALS_H

  // FastLED
  #define FASTLED_ALLOW_INTERRUPTS 0
  #include "FastLED.h"
  FASTLED_USING_NAMESPACE

  // Arduino
  #include "Arduino.h"

  // Pixel and Microcontroller settings
  #define DATA_PIN 2
  #define LED_TYPE WS2812B
  #define MAX_STRIPS 30
  #define MAX_LEDS 3000
  #define MAX_ANIMATIONS_PER_SCENE 30
  #define STRIP_COLOR_ORDER BGR

  // Structs
  typedef struct {
    uint16_t numberOfStrips;
    uint16_t numberOfLedsInEachStrip[MAX_STRIPS];
    uint16_t ledOffsetForEachStrip[MAX_STRIPS];
    uint16_t pinNumberForEachStrip[MAX_STRIPS];
    uint16_t totalNumberOfLeds;
    CRGB leds[MAX_LEDS];
    CRGB sceneWorkingLeds[MAX_LEDS];
  } globals_struc_t;

  typedef struct {
    uint16_t numberOfLeds;
    CRGB leds[MAX_LEDS];

    // these are the parameters for the current animation
    float settings[10];

    // settings for the animation go here.
    // feel free to be like `animation_settings_struct my_settings`...
  } current_animation_workspace_struct_t;

  // globals variables
  extern globals_struc_t Globals;
  extern current_animation_workspace_struct_t CurrentAnimation;

#endif
