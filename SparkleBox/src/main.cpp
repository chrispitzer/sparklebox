// libraries
#include "Arduino.h"

// directors
#include "directors/dispatch.h"


/*

time = 0
currently_selected_scene = 3
diretorRunFrame (shared_rng) {

  // Directors are in charge of running scenes, and then outputting the
  // color data from the scenes to the LEDs.

  // A basic director might just run one scene, for all the pixels, and dump
  // that data into the LEDs.

  // A slightly more involved director might run one scene for a while, then
  // switch to another one after a while.

  // Maybe it might cross fade between scenes.

  // Maybe (WAAAAAY in the future) it might override data in the scene spec
  // based on things like sensors, etc.


  time += 1
  scene_spec = utils.data.get_scene_spec(currently_selected_scene)
  director_rng = utils.random.generate_random_number()

  ... something about the nubmer of pixels that the scene is being rendered for...?

  light_pattern = sceneRunFrame(scene_spec, pixel_count, time, director_rng)

  // maybe wait until it's time for the next frame to be emitted (1/30 of a second, for instance?)
  fast_led.emit(light_pattern)
}


sceneRunFrame (scene_spec, pixel_count, time, director_rng) {
  // Scenes are in charge of running all the patterns within them,
  // and also blending the results of those patterns together, and then
  // returning the sum of that blend to the director.

  lights_sum = utils.LEDs.get_blank_pixel_array(pixel_count)
  scene_rng = utils.random.generate_random_number()

  for (pattern_spec in scene_spec.patterns) {
    pattern_rng = utils.random.generate_random_number()
    pattern_lights = patternRunFrame(pattern_spec, pixel_count, time, director_rng, scene_rng, pattern_rng)
    utils.leds.blend_lights_together
  }
}


pattern_map: {
  1: sp
}

patternRunFrame (pattern_spec, pixel_count, time, director_rng, scene_rng, pattern_rng) {
  id = pattern_spec.id
  switch (id) {
    1:
      return rainbows(pattern_spec, pixel_count, time, director_rng, scene_rng, pattern_rng)
    2:
      return sparkles(pattern_spec, pixel_count, time, director_rng, scene_rng, pattern_rng)
    3:
      return etc(pattern_spec, pixel_count, time, director_rng, scene_rng, pattern_rng)
  }
}



*/


void setup() {
  setupDirectors();
  Serial.begin(9600);
}


void loop() {
  // maybe we could eventually pass in WHICH director we are interested
  // in working with?
  dispatchDirector();
}


/* These were the demo ones...

void rainbow() {
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void addGlitter( fract8 chanceOfGlitter) {
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void rainbowWithGlitter() {
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}


void confetti() {
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon() {
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm() {
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}


// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

void nextPattern() {
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}
*/

