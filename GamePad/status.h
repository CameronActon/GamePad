#include "hearts_MASK.h"
#include "hearts_PIX.h"
#include "powers_MASK.h"
#include "powers_PIX.h"

int heartStartX = 20;
int heartDisplayBuffer = 2;

// Display hearts based on health
void displayHearts() {
  tft.setClipRect(heartStartX, screenH - 35, heartStartX + (hearts_W * 2) + (heartDisplayBuffer * 2), hearts_H);
  if (heroHealth >= 3) {
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W * 2) + (heartDisplayBuffer * 2), screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
  } else if (heroHealth == 2) {
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W * 2) + (heartDisplayBuffer * 2), screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
  } else if (heroHealth == 1) {
    tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
    tft.drawRGBBitmap(heartStartX + (hearts_W * 2) + (heartDisplayBuffer * 2), screenH - 35, hearts_PIX[1], hearts_MASK[1], hearts_W, hearts_H);
  }
  tft.updateScreen();
}

void displayPowers() {
  if(!hasDamageBuff){
    tft.setClipRect(screenW / 2 - 4, screenH - 45 - 4, (powers_W * 2) + 24, powers_H + 8);
    tft.drawRect(screenW / 2 - 4, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
    tft.drawRGBBitmap(screenW / 2, screenH - 45, powers_PIX[0], powers_MASK[0], powers_W, powers_H);
  } else if (hasDamageBuff){  
    tft.setClipRect(screenW / 2 - 4, screenH - 45 - 4, (powers_W * 2) + 24, powers_H + 8);
    tft.drawRect(screenW / 2 - 4, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
    tft.drawRGBBitmap(screenW / 2, screenH - 45, powers_PIX[1], powers_MASK[1], powers_W, powers_H);
  }

  if(!hasSpeedBuff){
    tft.drawRect(screenW / 2 - 4 + powers_W + 16, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
    tft.drawRGBBitmap(screenW / 2 + powers_W + 16, screenH - 45, powers_PIX[2], powers_MASK[2], powers_W, powers_H);
    tft.updateScreen();
  } else if (hasSpeedBuff){
    tft.drawRect(screenW / 2 - 4 + powers_W + 16, screenH - 45 - 4, powers_W + 8, powers_H + 8, ILI9341_WHITE);
    tft.drawRGBBitmap(screenW / 2 + powers_W + 16, screenH - 45, powers_PIX[3], powers_MASK[3], powers_W, powers_H);
    tft.updateScreen();
  }

}

void displayEntity(int ID, int x_, int y_) {
  if (ID == 4 && !hasAmulet) { //Amulet
    tft.setClipRect(x_, y_, powers_W, powers_H);
    tft.drawRGBBitmap(x_, y_, powers_PIX[ID], powers_MASK[ID], powers_W, powers_H);
    tft.updateScreen();
  } else if (ID == 3 && !chosenItem && !hasSpeedBuff){ //Boots
    tft.setClipRect(x_, y_, powers_W, powers_H);
    tft.drawRGBBitmap(x_, y_, powers_PIX[ID], powers_MASK[ID], powers_W, powers_H);
    tft.updateScreen();
  } else if (ID == 1 && !chosenItem && !hasDamageBuff){ //Bow
    tft.setClipRect(x_, y_, powers_W, powers_H);
    tft.drawRGBBitmap(x_, y_, powers_PIX[ID], powers_MASK[ID], powers_W, powers_H);
    tft.updateScreen();
  } else if (ID == 0 && !chosenItem && heroHealth < 3){ //Heart Container
    tft.setClipRect(x_, y_, hearts_W, hearts_H);
    tft.drawRGBBitmap(x_, y_, hearts_PIX[ID], hearts_MASK[ID], hearts_W, hearts_H);
    tft.updateScreen();
  }
}
