//Moji's Mystery
//Cameron Acton
//CRT 360 Advanced Prototyping || GamePad

int curMode = -2;

#include "frame.h"
#include "screen.h"
#include "controls.h"
#include "tile.h"
#include "interaction.h"
#include "hero.h"
#include "enemy.h"
#include "status.h"
#include "fight.h"
#include "modes.h"

void setup() {
  Serial.begin(9600); //Open a Serial connection

  initScreen();
  initControls();
  initNeighbors();
}

void loop() {
  getControls();
  runMode();
  //checkFrame();
  tft.updateScreen();
}
