// without this interrupts setting FastLED will crash the ESP32. Fun!
#define FASTLED_ALLOW_INTERRUPTS 0

// libraries
#include "Arduino.h"
#include "FastLED.h"
FASTLED_USING_NAMESPACE

// directors
#include "simpleDirector.h"

// Pixel and Microcontroller settings
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define MAX_LEDS 3000

// working variables
// unsigned int numberOfLeds;
unsigned int frameNumber = 0;
unsigned char selectedDirector = 0;

// pixel arrays.
// TODO: this is wasteful. Maybe fix this later.
// CRGB leds[MAX_LEDS];

// TODO - this struct isn't working yet...
// test_led_struct_t global_led_struct;




void setupDirectors (
    CRGB **ledStrips,
    unsigned int numberOfStrips,
    unsigned int numberOfLedsPerStrip
  ) {

  for (int i=0; i<numberOfStrips; i++) {
    // start them off as black.
    fill_solid(ledStrips[i], numberOfLedsPerStrip, CRGB::Black);

    // set up FastLED for this strip
    FastLED.addLeds<LED_TYPE, DATA_PIN>(ledStrips[i], numberOfLedsPerStrip);
  }

  // TODO - make this compile...
  //global_led_struct.num_leds_configured = 100;

  // call the setup function for each director.
  // setupSimpleDirector(numberOfLeds);
}

void dispatchDirector (
    CRGB **ledStrips,
    unsigned int numberOfStrips,
    unsigned int numberOfLedsPerStrip
  ) {
  frameNumber++;

  // set all leds to black.
  // fill_solid(leds, numberOfLeds, CRGB(0,0,0));

  switch (selectedDirector) {
    case 0:
      tickSimpleDirector(leds, numberOfLeds, frameNumber);

      // TODO - figure out struct syntax
      // tickSimpleDirector(&global_led_struct, frameNumber);
      break;
    default:
      Serial.println("Woah!! we don't have a valid director selected!");
      break;
  }

  // TODO - dalay here until 1/30 of a second has gone by.
  FastLED.show();
}


void startDirector () {
  // Get all this data from EEPROM
  unsigned int numberOfStrips = 16;
  unsigned int numberOfLedsPerStrip = 100;
  unsigned char dataPinsForStrips[] = {
    15, 2, 0, 4, 5, 18, 19, 21, 22, 23, 13, 12, 14, 27, 26, 25
  };

  // pixel arrays.
  CRGB ledStrips[numberOfStrips][numberOfLedsPerStrip];

  // surrogate
  CRGB *pointersToLedStrips[numberOfStrips];
  for (int i = 0; i < numberOfStrips; ++i) {
    pointersToLedStrips[i] = ledStrips[i];
  }

  setupDirectors(pointersToLedStrips, numberOfStrips, numberOfLedsPerStrip);

  while (true) {
    dispatchDirector(pointersToLedStrips, numberOfStrips, numberOfLedsPerStrip);
  }
}
// void process_pointer_2_pointer(int **array, size_t rows, size_t cols)