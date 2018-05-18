#include "data.h"


void loadDataFromEEPROM () {
  // TODO - actually load this from EEPROM. :P

  // Get all this data from EEPROM
  // these dummy values are for the `portal` piece
  uint16_t numberOfStrips = 16;
  uint16_t numberOfLedsInEachStrip[16] = {
    10, 10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10,
  };
  uint16_t pinNumberForEachStrip[16] = {
    15, 2, 0, 4,
    16, 17, 5, 18,
    19, 21, 22, 23,
    12, 14, 26, 25,
  };
  // 27 is glitchy

  // set all those values into `globalLeds`
  globalLeds.numberOfStrips = numberOfStrips;
  globalLeds.totalNumberOfLeds = 0;
  for (int i=0; i<numberOfStrips; i++) {
    // set values for this strip...
    globalLeds.pinNumberForEachStrip[i] = pinNumberForEachStrip[i];
    globalLeds.numberOfLedsInEachStrip[i] = numberOfLedsInEachStrip[i];
    globalLeds.ledOffsetForEachStrip[i] = globalLeds.totalNumberOfLeds;

    // increment total number of LEDS to account for this strip...
    // This will also be the offset for the next strip (if there's a next strip)
    globalLeds.totalNumberOfLeds += numberOfLedsInEachStrip[i];
  }
}
