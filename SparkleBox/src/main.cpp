#include "globals.h"

#include "directors/dispatch.h"


// Global data objects
led_struct_t globalLeds;
pattern_instance_settings_t patternSettings;


void setup() {
  // TODO - remove this from the live code.
  Serial.begin(9600);

  setupDirectors();
}


void loop() {
  dispatchDirector();
}
