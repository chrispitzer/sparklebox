#include "data.h"

typedef enum {
  PIN_0 = 0, PIN_1 = 1, PIN_2 = 2, PIN_3 = 3, PIN_4 = 4, PIN_5 = 5, PIN_6 = 6, PIN_7 = 7, PIN_8 = 8, PIN_9 = 9, PIN_10 = 10,
  PIN_11 = 11, PIN_12 = 12, PIN_13 = 13, PIN_14 = 14, PIN_15 = 15, PIN_16 = 16, PIN_17 = 17, PIN_18 = 18, PIN_19 = 19, PIN_20 = 20,
  PIN_21 = 21, PIN_22 = 22, PIN_23 = 23, PIN_24 = 24, PIN_25 = 25, PIN_26 = 26, PIN_27 = 27, PIN_28 = 28, PIN_29 = 29, PIN_30 = 30,
  PIN_31 = 31, PIN_32 = 32, PIN_33 = 33, PIN_34 = 34, PIN_35 = 35, PIN_36 = 36, PIN_37 = 37, PIN_38 = 38, PIN_39 = 39, PIN_40 = 40,
  PIN_41 = 41, PIN_42 = 42, PIN_43 = 43, PIN_44 = 44, PIN_45 = 45, PIN_46 = 46, PIN_47 = 47, PIN_48 = 48, PIN_49 = 49, PIN_50 = 50,
} led_strip_pins_t;

#if 1
  const uint16_t pinNumForEachStrip[16] = {
    PIN_15, PIN_2, PIN_0, PIN_4,
    PIN_5, PIN_18, PIN_19, PIN_21,
    PIN_22, PIN_23, PIN_13, PIN_12,
    PIN_14, PIN_27, PIN_26, PIN_25,
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
  Serial.println('adding strip on pin');
  Serial.println('adding strip on pin');
  Serial.println(pinNumForEachStrip[pin_idx]);

  return;
  /*

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
  */
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
    delay(1000);
    Serial.println("about to set up an led strip");
    Serial.println(i);
    Serial.println(pin);
    // loadDataFromEEPROMAddLeds (i, offset, numLeds);

    // increment total leds
    globalLeds.totalNumberOfLeds += numLeds;
  }

}
