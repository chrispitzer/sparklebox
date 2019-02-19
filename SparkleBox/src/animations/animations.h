#ifndef ANIMATIONS_H
  #define ANIMATIONS_H

  // SparkleBox Stuff.
  #include "../globals.h"

  struct animator_t {
    // Animator Name
    char const *name;
    // (read right to left) "`name` is a pointer to a constant char."

    // Settings & Memory
    uint8_t const numberOfMemories;
    uint8_t const numberOfSettings;
    char const * const *settingsNames;
    /* Ok... So that last line is a doosey. But remember - read lines
       about pointers from right to left... So that last line reads:

    --CODE----------------------------   --EXPLANATION--------------
    char const * const *settingsNames;
                        ^^^^^^^^^^^^^    settingsNames is...
    char const * const *settingsNames;
                 ^^^^^^^                 ...a constant pointer to...
    char const * const *settingsNames;
         ^^^^^^^                         ...a constant pointer to...
    char const * const *settingsNames;
    ^^^^                                 ...a char.

    so...
    "settingsNames is a constant pointer to a constant pointer to a char."
    And because any pointer can be an array, this is also...
    "settingsNames is a constant array of constant arrays of chars."
    And because an array of chars is a string...
    "settingsNames is a constant array of constant strings."

    *** phew ***

    */

    // Pointers to Methods
    void (*initMemory)();
    void (*animate)();
  };

  struct animator_workspace_t {
    uint16_t numberOfPixels;
    // `leds` will actually be an array of leds.
    CRGB *leds;
    // `memories` will actually be an array of floats.
    float_t *memories;
    // `settings` will actually be an array of floats.
    float_t *settings;
  };
  extern CRGB ledBufferA[];
  extern CRGB ledBufferB[];
  extern animator_workspace_t CurrentAnimation;

  namespace Animators {
    extern animator_t ColorFade;
  }

  namespace AnimationUtils {
    extern void renderFrame (); // a frame has multiple layers
    extern void renderLayer (); // a layer has an animation and multiple effects
    extern void renderAnimation (); // an animation outputs an array of colors
    extern void renderEffect (); // an effect has an input array of colors and an output array of colors

    extern void setUpCurrentAnimation ();
  }

  namespace DrawingUtils {
    extern void fillAllPixels (CHSV hsv);
    extern void fillAllPixels (CRGB rgb);
  }

  namespace AnimatorSetUpFunctions {

    // TODO - this miiiiiiight not be necessary. Delete it after we have
    // a few animations that exist if we aren't using it yet.

    // -vvv- Declare all animation set up functions here -vvv-
    extern void ColorFadeSetUp ();

    // This will be called by `dispatch.cpp` at setup time.
    extern void setUpAllAnimations ();
  }


#endif