#include "animations.h"


// Variables
uint8_t currentColor = 0; // intentionally 1 byte to roll over after 255
int16_t speed = 1;


// Addresses for data in memory/settings
// settings...
#define SETTING_SPEED 0
#define SETTING_SPEED_NAME "Speed"

// memory...
#define MEMORY_LAST_COLOR 0





animation_struct_t ColorFade;

// Testing area...
void AnimationSetUpFunctions::ColorFadeSetUp() {
  ColorFade.name = "Color Fade";
}




Animations::





// void init () {
//   CurrentAnimation.memory[MEMORY_LAST_COLOR] = 0;
// }

// void animate () {
//   // retrieve memory
//   currentColor = CurrentAnimation.memory[MEMORY_LAST_COLOR];
//   speed = CurrentAnimation.settings[SETTING_SPEED];
//   currentColor += speed;

//   // do the animation
//   CHSV hsv( currentColor, 255, 255);
//   AnimationUtils::fillAllPixels(hsv);

//   // store memory for next frame
//   CurrentAnimation.memory[MEMORY_LAST_COLOR] = currentColor;

//   // currentColor = frameNumber % 255;

//   // Serial.println("Color Fade!");
//   // TODO - it would be really great if this could be called with just an array it dumps data into.
//   // that way it wouldn't need to be aware of the whole shebang.
// }

// animation_struct_t Animations::ColorFade;
// Animations::ColorFade.name = "Color Fade";

// namespace Animations {

  // TODO - do we want to wrap this in another layer of namespace? For
  // instance, we could have a `ColorFade` namespace here with externs of
  // `MemoryDefaults` and `Animator`?

  // animation_struct_t ColorFade;

  // ColorFade.fav_number = 3;
  // ColorFade.name = "Color Fade";
  // ColorFade.init = &init;
  // ColorFade.animate = &animate;

// }
