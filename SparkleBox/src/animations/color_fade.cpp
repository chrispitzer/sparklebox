#include "animations.h"

// Variables
uint8_t currentColor = 0; // intentionally 1 byte to roll over after 255
int16_t speed = 1;

// For settings and memory, these defines are setting the index 
// Settings...
#define SPEED 0
static char const *SETTINGS_NAMES[] = {
  "Speed"
};
uint8_t const NUMBER_OF_SETTINGS = 1;

// Memory...
#define LAST_COLOR 0
#define INIT_LAST_COLOR 0
#define NUMBER_OF_MEMORIES 1


void initMemory () {
  // this should be correct, but we haven't set up `CurrentAnimation` yet...
  // CurrentAnimation.memory[LAST_COLOR] = INIT_LAST_COLOR;
}


void animate () {
  // retrieve memory
  // currentColor = CurrentAnimation.memory[MEMORY_LAST_COLOR];
  // speed = CurrentAnimation.settings[SETTING_SPEED];
  // currentColor += speed;

  // do the animation
  AnimationUtils::fillAllPixels (
    // CHSV( currentColor, 255, 255 )
    CHSV( 100, 255, 255 )
  );

  // store memory for next frame
  // CurrentAnimation.memory[MEMORY_LAST_COLOR] = currentColor;
}



void AnimationSetUpFunctions::ColorFadeSetUp () {
  // we miiiiiiight not need this anymore...

  /*
  // Animation Basics.
  Animations::ColorFade.name = (char *)"Color Fade";
  Animations::ColorFade.initializeAnimationMemory = initMemory;
  Animations::ColorFade.animate = animate;

  // Settings
  Animations::ColorFade.numberOfSettings = 2;
  Animations::ColorFade.settingsNames = {
    "first setting",
    "second setting"
  };
  //. Animations::ColorFade.
  //   "Movement Speed",
  //   "Starting Color"
  // };

  // Animations::ColorFade.

  */

}


animation_struct_t Animations::ColorFade = {
  "Color Fade",
  NUMBER_OF_MEMORIES,
  NUMBER_OF_SETTINGS,
  SETTINGS_NAMES,
  initMemory,
  animate
};
