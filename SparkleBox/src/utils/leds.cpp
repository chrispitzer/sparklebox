#include "leds.h"


void colorAllLeds (CRGB color) {
  fill_solid(globalLeds.leds, globalLeds.totalNumberOfLeds, color);
  fill_solid(globalLeds.sceneWorkingLeds, globalLeds.totalNumberOfLeds, color);
  fill_solid(globalLeds.patternWorkingLeds, globalLeds.totalNumberOfLeds, color);
}


void blackAllLeds () {
  colorAllLeds(CRGB(0,0,0));
}


void redAllLeds () {
  colorAllLeds(CRGB(255,0,0));
}


void greenAllLeds () {
  colorAllLeds(CRGB(0,255,0));
}


void blueAllLeds () {
  colorAllLeds(CRGB(0,0,255));
}


int offsetInGlobals = 0;
void instantiateAnLedStrip (uint16_t pin, uint16_t numberOfLeds) {
  switch(pin) {
    case PIN_0:
      FastLED.addLeds<LED_TYPE, PIN_0>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_1:
      FastLED.addLeds<LED_TYPE, PIN_1>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_2:
      FastLED.addLeds<LED_TYPE, PIN_2>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_3:
      FastLED.addLeds<LED_TYPE, PIN_3>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_4:
      FastLED.addLeds<LED_TYPE, PIN_4>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_5:
      FastLED.addLeds<LED_TYPE, PIN_5>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_6:
      FastLED.addLeds<LED_TYPE, PIN_6>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_7:
      FastLED.addLeds<LED_TYPE, PIN_7>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_8:
      FastLED.addLeds<LED_TYPE, PIN_8>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_9:
      FastLED.addLeds<LED_TYPE, PIN_9>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_10:
      FastLED.addLeds<LED_TYPE, PIN_10>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_11:
      FastLED.addLeds<LED_TYPE, PIN_11>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_12:
      FastLED.addLeds<LED_TYPE, PIN_12>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_13:
      FastLED.addLeds<LED_TYPE, PIN_13>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_14:
      FastLED.addLeds<LED_TYPE, PIN_14>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_15:
      FastLED.addLeds<LED_TYPE, PIN_15>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_16:
      FastLED.addLeds<LED_TYPE, PIN_16>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_17:
      FastLED.addLeds<LED_TYPE, PIN_17>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_18:
      FastLED.addLeds<LED_TYPE, PIN_18>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_19:
      FastLED.addLeds<LED_TYPE, PIN_19>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_20:
      FastLED.addLeds<LED_TYPE, PIN_20>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_21:
      FastLED.addLeds<LED_TYPE, PIN_21>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_22:
      FastLED.addLeds<LED_TYPE, PIN_22>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_23:
      FastLED.addLeds<LED_TYPE, PIN_23>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_24:
      FastLED.addLeds<LED_TYPE, PIN_24>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_25:
      FastLED.addLeds<LED_TYPE, PIN_25>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_26:
      FastLED.addLeds<LED_TYPE, PIN_26>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_27:
      FastLED.addLeds<LED_TYPE, PIN_27>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_28:
      FastLED.addLeds<LED_TYPE, PIN_28>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_29:
      FastLED.addLeds<LED_TYPE, PIN_29>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_30:
      FastLED.addLeds<LED_TYPE, PIN_30>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_31:
      FastLED.addLeds<LED_TYPE, PIN_31>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_32:
      FastLED.addLeds<LED_TYPE, PIN_32>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_33:
      FastLED.addLeds<LED_TYPE, PIN_33>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_34:
      FastLED.addLeds<LED_TYPE, PIN_34>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_35:
      FastLED.addLeds<LED_TYPE, PIN_35>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_36:
      FastLED.addLeds<LED_TYPE, PIN_36>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_37:
      FastLED.addLeds<LED_TYPE, PIN_37>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_38:
      FastLED.addLeds<LED_TYPE, PIN_38>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_39:
      FastLED.addLeds<LED_TYPE, PIN_39>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_40:
      FastLED.addLeds<LED_TYPE, PIN_40>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_41:
      FastLED.addLeds<LED_TYPE, PIN_41>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_42:
      FastLED.addLeds<LED_TYPE, PIN_42>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_43:
      FastLED.addLeds<LED_TYPE, PIN_43>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_44:
      FastLED.addLeds<LED_TYPE, PIN_44>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_45:
      FastLED.addLeds<LED_TYPE, PIN_45>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_46:
      FastLED.addLeds<LED_TYPE, PIN_46>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_47:
      FastLED.addLeds<LED_TYPE, PIN_47>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_48:
      FastLED.addLeds<LED_TYPE, PIN_48>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_49:
      FastLED.addLeds<LED_TYPE, PIN_49>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_50:
      FastLED.addLeds<LED_TYPE, PIN_50>(&globalLeds.leds[offsetInGlobals], numberOfLeds);
      break;
  }
  offsetInGlobals += numberOfLeds;
}


void instantiateLedStrips () {
  for (int i=0; i<globalLeds.numberOfStrips; i++) {
    instantiateAnLedStrip(
      globalLeds.pinNumberForEachStrip[i],
      globalLeds.numberOfLedsInEachStrip[i]
    );
  }
}
