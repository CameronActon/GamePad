#include "hearts_MASK.h"
#include "hearts_PIX.h"
#include "powers_MASK.h"
#include "powers_PIX.h"

int heartStartX = 20;
int heartDisplayBuffer = 2; 

// Display hearts based on health
void displayHearts() {
  tft.setClipRect(heartStartX, screenH - 35, heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), hearts_H);
  if(heroHealth == 3){
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
  } else if (heroHealth == 2){
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
  } else if (heroHealth == 1){
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
  }
  tft.updateScreen();
}

void displayPowers(int weapStat, int speedStat) {
  tft.setClipRect(screenW/2 - 4, screenH - 45 - 4, (powers_W*2) + 24, powers_H + 8);
  tft.drawRect(screenW/2 - 4, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
  tft.drawRGBBitmap(screenW/2, screenH - 45, powers_PIX[0], powers_MASK[0], powers_W, powers_H);

  tft.drawRect(screenW/2 - 4 + powers_W + 16, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
  tft.drawRGBBitmap(screenW/2 + powers_W + 16, screenH - 45, powers_PIX[2], powers_MASK[2], powers_W, powers_H);
  tft.updateScreen();
}
