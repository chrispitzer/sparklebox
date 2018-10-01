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
  } led_struct_t;






  // this will be passed inth the setup thingy in the pattern, and then passed
  // back to it each time it is called. So the pattern will have it's own
  // instance settings.
  typedef struct {
    float_t settingA;
    float_t settingB;
    float_t settingC;
    float_t settingD;
    float_t settingE;
    float_t settingF;
    uint16_t numberOfLeds;
    uint16_t frameNumber;
  } pattern_instance_settings_t;


  enum class Pattern {
    colorRotate,
    solidColor,
  };

  // enum class Color { red, green = 20, blue };
  // Color r = Color::blue;
  // switch(r)
  // {
  //     case Color::red  : std::cout << "red\n";   break;
  //     case Color::green: std::cout << "green\n"; break;
  //     case Color::blue : std::cout << "blue\n";  break;
  // }
  // // int n = r; // error: no scoped enum to int conversion
  // int n = static_cast<int>(r); // OK, n = 21


  typedef struct {
    uint8_t numberOfPatterns;
    Pattern patterns[MAX_ANIMATIONS_PER_SCENE];
    pattern_instance_settings_t patternSettings[MAX_ANIMATIONS_PER_SCENE];
  } scene_instance_settings_t;


  // globals variables
  extern led_struct_t globalLeds;



#endif