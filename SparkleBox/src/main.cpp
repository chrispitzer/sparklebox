#define FASTLED_ALLOW_INTERRUPTS 0


#include "FastLED.h"

FASTLED_USING_NAMESPACE




/*

TODOs

Scene Data:
[
  {
    name: "Purple Glitter",    //  max length: 20 characters
    patterns: [
      {
        id: some_pattern_id,
        setting1:
      }

    ]

  }
]



These are the functions we need...

* directorRunFrame
* sceneRunFrame(
  time= an "unsigned int" (32 bit), that is what frame we are on.
)



* patternRunFrame(
  pattern_type_id= an id that tells us which pattern to run - each pattern is a funciton

  frame_number = this is what "time" we are at
  shared_random_number = 16 bit number - this is a random number that is shared, for this frame, with all pattern generators.
  unique_random_number = 16 bit number - this is 

  settingA = float
  settingB = float
  settingC = float
  settingD = float
  settingE = float

  number_of_pixels_to_emit = unsigned short int
)


* a pattern (a fairly simple example)




============= Patterns ==============



loop () {
  // loop runs every frame

  directorRunFrame()

}


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




















#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    150
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          255
#define FRAMES_PER_SECOND  120

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns





void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}



void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}


void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
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

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
}
