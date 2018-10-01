#include "dispatch.h"

// working variables
uint32_t frameNumber = 0;
uint8_t selectedDirector = 0;


void setupDirectors () {
  loadDataFromEEPROM();
  instantiateLedStrips();

  // Start by blacking all POSSIBLE leds.
  fill_solid(globalLeds.leds, MAX_LEDS, CRGB(0,0,0));
  fill_solid(globalLeds.sceneWorkingLeds, MAX_LEDS, CRGB(0,0,0));
}


void dispatchDirector () {

  // STEP 1
  // get this calling an animator.
  // Pipe that animator to the output pixels.
  // Send that to the LED strip.
  blackAllLeds();
  Animations::ColorRotate();
  // ColorRotate();
  FastLED.show();
  delay(10);



  // STEP 2
  // Run one animator
  // pipe that to the output pixels
  // run another animator
  // pipe that to the output pixels on top of the first signal
  // send that to the LED strip.



  // STEP 3
  // Have a concept of an oscilator


  // STEP 4
  // pipe the oscilator to the animator


}


/*

scenes = [
    {
        name: "Under the Sea"
        animations: [
            {
                id: 5,
                opacity: .75,
                blending_thingy: ? maybe we want to tell this something about how to blend the layers in here? 
                setting_A: 123, // float
                setting_B: 123, // float
                setting_C: 123, // float
                setting_D: 123, // float
                setting_E: 123, // float
            },
            { ... },
            { ... },
            { ... },
        ]
    }
]

get_scene_spec (scene_id) {
    return scenes[scene_id]
}

*/