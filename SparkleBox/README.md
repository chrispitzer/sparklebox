# Sparklebox

Sparklebox is a rad-ass led synthesizer!

# The loop() cycle, on processor 1.

* [ RECIPE LOAD PHASE ] Load the current scene specs into the renderer
* [ RENDER PHASE ] Run the scene
  * [ set up the LED memory ]
    * zero out the pixels on both buffers.
  * [ Layer Render loop ] run this loop until done for all layers...
    * [ prep current animation workspace ] Prep the CurrentAnimation workspace for the next layer.
    * [ LAYER FRAME RENDER PHASE ] run the animator to render this frame...
      * this will put a frame into the LED buffer on CurrentAnimation
    * [ LAYER API PHASE ] stream this layer to API if wanted
    * [ EFFECTS PHASE ] ... TODO ... this is where we loop for each effect.
    * [ MERGE PHASE ] merge the pixel data into the other buffer
* [ OUTPUT PHASE ] send the data to the pixels.

# The loop() cycle on procerssor 2.

* [ WEB REQUEST PHASE ] Check for an http request.
  * 
  
