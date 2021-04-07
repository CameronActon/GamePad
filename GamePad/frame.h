#include <Metro.h>

//Timer used in sampling framerate
Metro sampleTimer = Metro(1000);

int frames;

void checkFrame() {
  frames++;
  if (sampleTimer.check()) {
    Serial.println(frames);
    frames = 0;
  }
}
