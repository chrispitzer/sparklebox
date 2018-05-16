#include "data.h"

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
  uint16_t pinNumForEachStrip[16] = {
    15, 2, 0, 4,
    5, 18, 19, 21,
    22, 23, 13, 12,
    14, 27, 26, 25,
  };

  globalLeds.totalNumberOfLeds = 0;
  for (int i=0; i<globalLeds.numberOfStrips; i++) {
    // working values for this strip
    int numLeds = numLedsInEachStrip[i];
    int pin = pinNumForEachStrip[i];
    int offset = globalLeds.totalNumberOfLeds;

    // set the values for this strip
    globalLeds.pinNumberForStrip[i] = pin;
    globalLeds.numberOfLedsInStrip[i] = numLeds;
    globalLeds.ledOffsetForStrip[i] = globalLeds.totalNumberOfLeds;

    // set up the strip in FastLED
    FastLED.addLeds<LED_TYPE, pin>(&globalLeds.leds[offset], numLeds);

    // increment total leds
    globalLeds.totalNumberOfLeds += numLeds;
  }

}
