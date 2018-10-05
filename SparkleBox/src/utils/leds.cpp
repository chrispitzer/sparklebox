#include "leds.h"


void colorAllLeds (CRGB color) {
  fill_solid(Globals.leds, Globals.totalNumberOfLeds, color);
  Serial.println("make it a color!");
}


void blackAllLeds () {
  Serial.println("black");
  colorAllLeds(CRGB(0,0,0));
}


void redAllLeds () {
  Serial.println("red");
  colorAllLeds(CRGB(255,0,0));
}


void greenAllLeds () {
  Serial.println("green");
  colorAllLeds(CRGB(0,255,0));
}


void blueAllLeds () {
  Serial.println("blue");
  colorAllLeds(CRGB(0,0,255));
}


int offsetInGlobals = 0;
void instantiateAnLedStrip (uint16_t pin, uint16_t numberOfLeds) {
  // TODO - redo this. We're not building a general purpose framework that will run on anything.
  // This can be opinionated and pick 8 fixed pins on the ESP32.

  switch(pin) {
    case PIN_0:
      FastLED.addLeds<LED_TYPE, PIN_0, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_1:
      FastLED.addLeds<LED_TYPE, PIN_1, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_2:
      FastLED.addLeds<LED_TYPE, PIN_2, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_3:
      FastLED.addLeds<LED_TYPE, PIN_3, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_4:
      FastLED.addLeds<LED_TYPE, PIN_4, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_5:
      FastLED.addLeds<LED_TYPE, PIN_5, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    // case PIN_6:
    //   FastLED.addLeds<LED_TYPE, PIN_6, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_7:
    //   FastLED.addLeds<LED_TYPE, PIN_7, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_8:
    //   FastLED.addLeds<LED_TYPE, PIN_8, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_9:
    //   FastLED.addLeds<LED_TYPE, PIN_9, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_10:
    //   FastLED.addLeds<LED_TYPE, PIN_10, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_11:
    //   FastLED.addLeds<LED_TYPE, PIN_11, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    case PIN_12:
      FastLED.addLeds<LED_TYPE, PIN_12, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_13:
      FastLED.addLeds<LED_TYPE, PIN_13, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_14:
      FastLED.addLeds<LED_TYPE, PIN_14, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_15:
      FastLED.addLeds<LED_TYPE, PIN_15, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_16:
      FastLED.addLeds<LED_TYPE, PIN_16, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_17:
      FastLED.addLeds<LED_TYPE, PIN_17, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_18:
      FastLED.addLeds<LED_TYPE, PIN_18, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_19:
      FastLED.addLeds<LED_TYPE, PIN_19, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    // case PIN_20:
    //   FastLED.addLeds<LED_TYPE, PIN_20, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    case PIN_21:
      FastLED.addLeds<LED_TYPE, PIN_21, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_22:
      FastLED.addLeds<LED_TYPE, PIN_22, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_23:
      FastLED.addLeds<LED_TYPE, PIN_23, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    // case PIN_24:
    //   FastLED.addLeds<LED_TYPE, PIN_24, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    case PIN_25:
      FastLED.addLeds<LED_TYPE, PIN_25, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_26:
      FastLED.addLeds<LED_TYPE, PIN_26, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    case PIN_27:
      FastLED.addLeds<LED_TYPE, PIN_27, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      break;
    // case PIN_28:
    //   FastLED.addLeds<LED_TYPE, PIN_28, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_29:
    //   FastLED.addLeds<LED_TYPE, PIN_29, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_30:
    //   FastLED.addLeds<LED_TYPE, PIN_30, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_31:
    //   FastLED.addLeds<LED_TYPE, PIN_31, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_32:
    //   FastLED.addLeds<LED_TYPE, PIN_32, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_33:
    //   FastLED.addLeds<LED_TYPE, PIN_33, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_34:
    //   FastLED.addLeds<LED_TYPE, PIN_34, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_35:
    //   FastLED.addLeds<LED_TYPE, PIN_35, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_36:
    //   FastLED.addLeds<LED_TYPE, PIN_36, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_37:
    //   FastLED.addLeds<LED_TYPE, PIN_37, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_38:
    //   FastLED.addLeds<LED_TYPE, PIN_38, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_39:
    //   FastLED.addLeds<LED_TYPE, PIN_39, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_40:
    //   FastLED.addLeds<LED_TYPE, PIN_40, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_41:
    //   FastLED.addLeds<LED_TYPE, PIN_41, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_42:
    //   FastLED.addLeds<LED_TYPE, PIN_42, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_43:
    //   FastLED.addLeds<LED_TYPE, PIN_43, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_44:
    //   FastLED.addLeds<LED_TYPE, PIN_44, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_45:
    //   FastLED.addLeds<LED_TYPE, PIN_45, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_46:
    //   FastLED.addLeds<LED_TYPE, PIN_46, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_47:
    //   FastLED.addLeds<LED_TYPE, PIN_47, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_48:
    //   FastLED.addLeds<LED_TYPE, PIN_48, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_49:
    //   FastLED.addLeds<LED_TYPE, PIN_49, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    // case PIN_50:
    //   FastLED.addLeds<LED_TYPE, PIN_50, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
    //   break;
    default:
      Serial.println("Pin not found!");
      Serial.println(pin);
  }
  offsetInGlobals += numberOfLeds;
}


void instantiateLedStrips () {
  for (int i=0; i<Globals.numberOfStrips; i++) {
    instantiateAnLedStrip(
      Globals.pinNumberForEachStrip[i],
      Globals.numberOfLedsInEachStrip[i]
    );
  }
}
