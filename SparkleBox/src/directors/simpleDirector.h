// To make sure you don't declare the function more than once by including
// the header multiple times.
#ifndef SIMPLE_DIRECTOR_H

  #define SIMPLE_DIRECTOR_H
  #include "FastLED.h"

  void setupSimpleDirector (unsigned short int numOfPixels);
  CRGB* tickSimpleDirector(/* unsigned int frameNumber */);

#endif
