//Moji's Mystery
//Cameron Acton
//CRT 360 Advanced Prototyping || GamePad

#include "frame.h"
#include "screen.h"
#include "controls.h"
#include "tile.h"
#include "hero.h"

void setup() {
  Serial.begin(9600); //Open a Serial connection

  initScreen();
  initControls();
}

void loop() {
  //checkFrame();
  drawLevel(1);
  tft.updateScreen();
  
  getControls();
  drawHero();
  
}
