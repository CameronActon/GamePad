#include "mojiSprites_MASK.h"
#include "mojiSprites_PIX.h"

#define heroW 11
#define heroH 16

float heroX = 150;
float heroY = 120;

float heroSpeed = .2;
int heroDir;
int heroFrame = 0;
Metro heroFrameTimer = Metro(100);

Metro positionPrintTimer = Metro(50);

void movement() {
  if (heroY < 160 && heroY > 0) {
    if (heroX < 300 && heroX > 0) {
      heroX = heroX + (heroSpeed * joystickBuffer[0]);
      heroY = heroY + (heroSpeed * joystickBuffer[1]);
    }
  }

  if(joystickBuffer[0] == -1){ heroDir = -1; }
  else if(joystickBuffer[0] == 1){ heroDir = 1; }
  else { heroDir = 0; }
}

void drawHero() {
  movement();
  
  if(heroFrameTimer.check()){
    if(buttonBuffer[0] == 0 && buttonBuffer[1] == 0){
      if(heroDir == -1){ heroFrame = (heroFrame + 1) % 3; }
      else if(heroDir == 1){ heroFrame = 5 + ((heroFrame + 1) % 3); } //Issue here with not looping animation through when '5' is first frame
      else { heroFrame = 0; }
    } else {
      if(buttonBuffer[0] == 1){ heroFrame = 3 + ((heroFrame + 1) % 2); } //Issue here with not looping animation through when '3' is first frame
      else if(buttonBuffer[1] == 1){ heroFrame = 8 + ((heroFrame + 1) % 2); }
    }
  }
  
  tft.setClipRect(heroX - 2, heroY - 2, heroW + 4, heroH + 4);
  tft.drawRGBBitmap(heroX, heroY, mojiSprites_PIX[heroFrame], mojiSprites_MASK[heroFrame], heroW, heroH);

  tft.updateScreen();

  if (positionPrintTimer.check()) {
    Serial.print(heroX);
    Serial.print("\t");
    Serial.print(heroY);
    Serial.println();
  }
}
