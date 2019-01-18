#ifndef ANIMATIONS_H
  #define ANIMATIONS_H

  // SparkleBox Stuff.
  #include "../globals.h"

  struct animation_struct_t {
    // Animator Name
    char const *name;

    // Settings & Memory
    uint8_t const numberOfMemories;
    uint8_t const numberOfSettings;
    char const * const *settingsNames;

    // Methods
    void (*initializeAnimationMemory)();
    void (*animate)();
  };

  namespace Animations {
    extern animation_struct_t ColorFade;
  }

  namespace AnimationUtils {
    extern void fillAllPixels (CHSV hsv);
    extern void fillAllPixels (CRGB rgb);
  }

  namespace AnimationSetUpFunctions {

    // TODO - this miiiiiiight not be necessary. Delete it after we have
    // a few animations that exist if we aren't using it yet.

    // -vvv- Declare all animation set up functions here -vvv-
    extern void ColorFadeSetUp ();

    // This will be called by `dispatch.cpp` at setup time.
    extern void setUpAllAnimations ();
  }


#endif