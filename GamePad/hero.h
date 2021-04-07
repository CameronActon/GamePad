#include "mojiSprites_MASK.h"
#include "mojiSprites_PIX.h"

#define heroW 24
#define heroH 24

#define UIHeight 60

float heroX = 150;
float heroY = 120;

float heroSpeed = 1;
int heroDir;
int heroFrame = 0;
Metro heroFrameTimer = Metro(100);

Metro positionPrintTimer = Metro(50);

void moveHero() {
  float nextX = heroX + (heroSpeed * float(joystickBuffer[0]));
  float nextY = heroY + (heroSpeed * float(joystickBuffer[1]));

  if(checkMove(curMode, nextX, nextY, heroW, heroH)){
    heroX = nextX;
    heroY = nextY;
  }
  
//  if (nextY < (screenH - UIHeight - heroH) && nextY > 0) {
//    if (nextX < (screenW - heroW) && nextX > 0) {
//      heroX = nextX;
//      heroY = nextY;
//    }
//  }

  if(joystickBuffer[0] == -1){ heroDir = -1; }
  else if(joystickBuffer[0] == 1 || joystickBuffer[1] != 0){ heroDir = 1; }
}

void animateHero(){
  if(heroFrameTimer.check()){
    if(buttonBuffer[0] == 0 && buttonBuffer[1] == 0){
      if(joystickBuffer[0] != 0 && heroDir == -1){ heroFrame = 0 + ((heroFrame + 1) % 3); }
      else if(joystickBuffer[0] != 0 && heroDir == 1){ heroFrame = 5 + ((heroFrame + 1) % 3); }  //Issue here with not looping animation through when '5' is first frame
    } else {
      if(buttonBuffer[0] == 1){ heroFrame = 3 + ((heroFrame + 1) % 2); } //Issue here with not looping animation through when '3' is first frame
      else if(buttonBuffer[1] == 1){ heroFrame = 8 + ((heroFrame + 1) % 2); }
    }
  }
}

void drawHero() {
  moveHero();
  animateHero();
  
  tft.setClipRect(heroX - 2, heroY - 2, heroW + 4, heroH + 4);
  tft.drawRGBBitmap(heroX, heroY, mojiSprites_PIX[heroFrame], mojiSprites_MASK[heroFrame], heroW, heroH);

//  if (positionPrintTimer.check()) {
//    Serial.print(heroX);
//    Serial.print("\t");
//    Serial.print(heroY);
//    Serial.println();
//  }
}
