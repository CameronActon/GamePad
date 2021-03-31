//Moji's Mystery
//Cameron Acton
//CRT 360 Advanced Prototyping || GamePad

#include "frame.h"
#include "screen.h"
#include "tile.h"

void setup() {
  Serial.begin(9600); //Open a Serial connection

  initScreen();
}

void loop() {
  checkFrame();

  drawLevel(1);
  tft.updateScreen();
}
