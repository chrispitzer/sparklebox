#include "../globals.h"


namespace EEPROM {
  void loadData () {
    // TODO - actually load this from EEPROM. :P

    // Get all this data from EEPROM
    // these dummy values are for the `portal` piece
    uint16_t numberOfStrips = 16;
    uint16_t numberOfLedsInEachStrip[16] = {
      10, 300, 10, 10,
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
    // 2 is the built-in led on the dev board.

    // set all those values into `Globals`
    Globals.numberOfStrips = numberOfStrips;
    Globals.totalNumberOfLeds = 0;
    for (int i=0; i<numberOfStrips; i++) {
      // set values for this strip...
      Globals.pinNumberForEachStrip[i] = pinNumberForEachStrip[i];
      Globals.numberOfLedsInEachStrip[i] = numberOfLedsInEachStrip[i];
      Globals.ledOffsetForEachStrip[i] = Globals.totalNumberOfLeds;

      // increment total number of LEDS to account for this strip...
      // This will also be the offset for the next strip (if there's a next strip)
      Globals.totalNumberOfLeds += numberOfLedsInEachStrip[i];
    }
  }
}
