#include "data.h"


void loadDataFromEEPROM () {
  // TODO - actually load this from EEPROM. :P

  // Get all this data from EEPROM
  // these dummy values are for the `portal` piece
  uint16_t numberOfStrips = 16;
  uint16_t numberOfLedsInEachStrip[16] = {
    30, 50, 55, 60,
    32, 52, 57, 62,
    32, 52, 57, 62,
    34, 54, 59, 64,
  };
  uint16_t pinNumberForEachStrip[16] = {
    15, 2, 0, 4,
    5, 18, 19, 21,
    22, 23, 13, 12,
    14, 27, 26, 25,
  };

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
