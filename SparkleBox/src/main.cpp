#include "globals.h"

#include "directors/dispatch.h"
#include "scenes/dispatch.h"
#include "patterns/dispatch.h"


// This is our main global object!
led_struct_t globalLeds;


void setup() {
  setupDirectors();
  setupScenes();
  setupPatterns();

  // TODO - remove this from the live code.
  Serial.begin(9600);
}


void loop() {
  dispatchDirector();
}
