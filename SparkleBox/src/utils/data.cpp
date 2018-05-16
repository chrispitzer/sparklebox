#include "data.h"

typedef enum {
  STRIP_A = 15,
  STRIP_B = 2,
  STRIP_C = 0,
  STRIP_D = 4,
  STRIP_E = 5,
  STRIP_F = 18,
  STRIP_G = 19,
  STRIP_H = 21,
  STRIP_I = 22,
  STRIP_J = 23,
  STRIP_K = 13,
  STRIP_L = 12,
  STRIP_M = 14,
  STRIP_N = 27,
  STRIP_O = 26,
  STRIP_P = 25,
} led_strip_pins_t;

#if 1
  const uint16_t pinNumForEachStrip[16] = {
    STRIP_A, STRIP_B, STRIP_C, STRIP_D, 
    STRIP_E, STRIP_F, STRIP_G, STRIP_H, 
    STRIP_I, STRIP_J, STRIP_K, STRIP_L, 
    STRIP_M, STRIP_N, STRIP_O, STRIP_P, 
  };
#else
  const uint16_t pinNumForEachStrip[16] = {
    15, 2, 0, 4,
    5, 18, 19, 21,
    22, 23, 13, 12,
    14, 27, 26, 25,
  };
#endif

void loadDataFromEEPROMAddLeds (const int pin_idx, const int offset, const int numLeds) {

  switch((led_strip_pins_t) pinNumForEachStrip[pin_idx]) {
    case STRIP_A:
      FastLED.addLeds<LED_TYPE, STRIP_A>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_B:
      FastLED.addLeds<LED_TYPE, STRIP_B>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_C:
      FastLED.addLeds<LED_TYPE, STRIP_C>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_D:
      FastLED.addLeds<LED_TYPE, STRIP_D>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_E:
      FastLED.addLeds<LED_TYPE, STRIP_E>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_F:
      FastLED.addLeds<LED_TYPE, STRIP_F>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_G:
      FastLED.addLeds<LED_TYPE, STRIP_G>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_H:
      FastLED.addLeds<LED_TYPE, STRIP_H>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_I:
      FastLED.addLeds<LED_TYPE, STRIP_I>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_J:
      FastLED.addLeds<LED_TYPE, STRIP_J>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_K:
      FastLED.addLeds<LED_TYPE, STRIP_K>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_L:
      FastLED.addLeds<LED_TYPE, STRIP_L>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_M:
      FastLED.addLeds<LED_TYPE, STRIP_M>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_N:
      FastLED.addLeds<LED_TYPE, STRIP_N>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_O:
      FastLED.addLeds<LED_TYPE, STRIP_O>(&globalLeds.leds[offset], numLeds);
      break;
    case STRIP_P:
      FastLED.addLeds<LED_TYPE, STRIP_P>(&globalLeds.leds[offset], numLeds);
      break;
  }
}

void loadDataFromEEPROM () {
  // TODO - actually load this from EEPROM. :P

  // Get all this data from EEPROM
  globalLeds.numberOfStrips = 16;

  // dummy values, setting this up for the Portal piece Chance and
  // Chrispy are working on.
  uint16_t numLedsInEachStrip[16] = {
    30, 50, 55, 60,
    32, 52, 57, 62,
    32, 52, 57, 62,
    34, 54, 59, 64,
  };

  globalLeds.totalNumberOfLeds = 0;
  for (int i=0; i<globalLeds.numberOfStrips; i++) {
    // working values for this strip
    int numLeds = numLedsInEachStrip[i];
    const int pin = pinNumForEachStrip[i];
    int offset = globalLeds.totalNumberOfLeds;

    // set the values for this strip
    globalLeds.pinNumberForStrip[i] = pin;
    globalLeds.numberOfLedsInStrip[i] = numLeds;
    globalLeds.ledOffsetForStrip[i] = globalLeds.totalNumberOfLeds;

    // set up the strip in FastLED
    //FastLED.addLeds<LED_TYPE, pin>(&globalLeds.leds[offset], numLeds);//FIXME "pin" is a variable and must be a constant that is known at compile time. #define values aure usually used for this
    //FastLED.addLeds<LED_TYPE, 1>(&globalLeds.leds[offset], numLeds);
    loadDataFromEEPROMAddLeds (i, offset, numLeds);

    // increment total leds
    globalLeds.totalNumberOfLeds += numLeds;
  }

}
