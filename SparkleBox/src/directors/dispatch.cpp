// without this interrupts setting FastLED will crash the ESP32. Fun!
#define FASTLED_ALLOW_INTERRUPTS 0

// libraries
#include "Arduino.h"
#include "FastLED.h"

// TODO..... is this line actually helpful for anything?
FASTLED_USING_NAMESPACE

// directors
#include "simpleDirector.h"

// Pixel and Microcontroller settings
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define MAX_LEDS 3000

// working variables
unsigned int numberOfLeds;
unsigned int frameNumber = 0;
unsigned char selectedDirector = 0;

// pixel arrays.
// TODO: this is wasteful. Maybe fix this later.
CRGB leds[MAX_LEDS];
CRGB tempLeds[MAX_LEDS];

typedef struct {
  uint32_t num_leds_configured;
  CRGB leds[MAX_LEDS];
  CRGB tempLeds[MAX_LEDS];
} test_led_struct_t;

test_led_struct_t global_led_struct;

// these should be pulled out of a user configurable `global settings`
// part of memory... It should be in EEPROM.

// unsigned short int numLeds = 100;
// #define MAX_NUMBER_OF_LEDS 1000
// CHSV nextFrame[MAX_NUMBER_OF_LEDS];

// #define NUM_LEDS 1000
// CRGB leds[NUM_LEDS];


void setupDirectors (int numberOfLeds) {
  numberOfLeds = 100; // TODO: this should come from EEPROM
  global_led_struct.num_leds_configured = 100;

  // set all possible LEDs to black
  fill_solid(leds, MAX_LEDS, CRGB(0,0,0));
  fill_solid(tempLeds, MAX_LEDS, CRGB(0,0,0));

  // set up the leds
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, numberOfLeds);

  // call the setup function for each director.
  setupSimpleDirector(numberOfLeds);
}

void dispatchDirector () {
  frameNumber++;

  // set all leds to black.
  fill_solid(leds, numberOfLeds, CRGB(0,0,0));
  fill_solid(tempLeds, numberOfLeds, CRGB(0,0,0));

  switch (selectedDirector) {
    case 0:
      tickSimpleDirector(leds, tempLeds, numberOfLeds, frameNumber);
      tickSimpleDirector(&global_led_struct, frameNumber);
      break;
    default:
      Serial.println("Woah!! we don't have a valid director selected!");
      break;
  }

  // TODO - dalay here until 1/30 of a second has gone by.
  FastLED.show();
}


/*
void printarray (int arg[], int length) {
    for (int n = 0; n < length; n++) {
        cout << arg[n] << " ";
        cout << "\n";
    }
}

int main ()
{
     int firstarray[] = {5, 10, 15};
     int secondarray[] = {2, 4, 6, 8, 10};
     printarray(firstarray, 3);
     printarray(secondarray, 5);

     return 0;
}
*/
