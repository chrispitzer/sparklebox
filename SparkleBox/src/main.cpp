#include "globals.h"

#include "directors/dispatch.h"


// Global data objects
globals_struct_t Globals;


void setup() {
  // TODO - remove this from the live code.
  Serial.begin(9600);

  setupDirectors();
}


void loop() {
  dispatchDirector();
}
