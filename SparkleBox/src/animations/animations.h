#ifndef ANIMATIONS_H
  #define ANIMATIONS_H

  // SparkleBox Stuff.
  #include "../globals.h"

  // struct functionDaemon {
  //    int id;
  //    //double (*funcp); // function pointer
  //    double  (*fp)(double);      // Function pointer
  // }

  struct animation_struct_t {
    char *name;
    // void (*init)();
    // void (*animate)();
  };

  namespace Animations {
    extern animation_struct_t ColorFade;
  }

  namespace AnimationUtils {
    extern void fillAllPixels (CHSV hsv);
    extern void fillAllPixels (CRGB rgb);
  }

  namespace AnimationSetUpFunctions {
    extern void ColorFadeSetUp ();
  }


#endif