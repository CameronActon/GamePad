#include "mojiSprites_MASK.h"
#include "mojiSprites_PIX.h"

#define heroW 16
#define heroH 24

float heroX = 150;
float heroY = 120;

float heroSpeed = .5;
int heroDir;
int heroFrame = 0;
Metro heroFrameTimer = Metro(100);

Metro positionPrintTimer = Metro(50);

bool heroHasBow;
bool heroHasSpeed;

int heroHealth = 3;

void moveHero() {
  float nextX = heroX + (heroSpeed * float(joystickBuffer[0]));
  float nextY = heroY + (heroSpeed * float(joystickBuffer[1]));

  if(checkMove(curMode, nextX, nextY, heroW, heroH)){
    heroX = nextX;
    heroY = nextY;
  }

  if(joystickBuffer[0] == -1){ heroDir = -1; }
  else if(joystickBuffer[0] == 1 || joystickBuffer[1] != 0){ heroDir = 1; }
}

void animateHero(){
  if(heroFrameTimer.check()){
    if(buttonBuffer[1] == 0 && buttonBuffer[2] == 0){
      if(joystickBuffer[0] != 0 && heroDir == -1){ heroFrame = 0 + ((heroFrame + 1) % 3); }
      else if(joystickBuffer[0] != 0 && heroDir == 1){ heroFrame = 6 + ((heroFrame + 1) % 3); }  
    } else {
      if(buttonBuffer[1] == 1){ heroFrame = 3 + ((heroFrame + 1) % 3); }
      else if(buttonBuffer[2] == 1){ heroFrame = 9 + ((heroFrame + 1) % 3); }
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
