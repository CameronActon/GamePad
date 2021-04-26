#include "enemy_MASK.h"
#include "enemy_PIX.h"
#include "boss_MASK.h"
#include "boss_PIX.h"

Metro enemyFrameTimer = Metro(100);
Metro enemyBrainTimer = Metro(1000);

float enemyX = 0;
float enemyY = 0;

int enemyType = 0;
bool enemyStatus = true;
int enemyHealth = 3;

float enemyXDir = 0;
float enemyYDir = 0;

int enemyFrame = 0; 

int enemySmart = 3;
float enemySpeed = 0.15;

void updateEnemyDir(){
  if(enemyBrainTimer.check()){
    int n = random(0, enemySmart);

    if(n == 0){
      enemyXDir = random(-1, 2);
      enemyYDir = random(-1, 2);
    } else {
      if(heroX < enemyX){ enemyXDir = -1;
      } else { enemyXDir = 1; }

      if(heroY < enemyX){ enemyYDir = -1;
      } else { enemyYDir = 1;  }
    }
  }
}

void moveEnemy(){
  float nextX = enemyX + (enemyXDir * enemySpeed);
  float nextY = enemyY + (enemyYDir * enemySpeed);

  if(checkMove(curMode, nextX, nextY, enemy_W, enemy_H)){
    enemyX = nextX;
    enemyY = nextY;
  }
}

void animateEnemy(){
  if(enemyFrameTimer.check()){
    if(enemyType == 0){
      if(enemyXDir >= 0){ enemyFrame = 0 + ((enemyFrame + 1) % 6); }
      else { enemyFrame = 6 + ((enemyFrame + 1) % 6); }
    } else if (enemyType == 1) {
      if(enemyXDir >= 0){ enemyFrame = 3 + ((enemyFrame + 1) % 3); }
      else { enemyFrame = 0 + ((enemyFrame + 1) % 3); }
    }
  }
}

void drawEnemy(){
  if(enemyStatus){
    updateEnemyDir();
    moveEnemy();
    animateEnemy();

    if(enemyType == 0){
      tft.setClipRect(enemyX - 2, enemyY - 2, enemy_W + 4, enemy_H + 4);
      drawLevel(curMode);
      tft.drawRGBBitmap(enemyX, enemyY, enemy_PIX[enemyFrame], enemy_MASK[enemyFrame], enemy_W, enemy_H);
      tft.updateScreen();
    } else if (enemyType == 1) {
      tft.setClipRect(enemyX - 2, enemyY - 2, boss_W + 4, boss_H + 4);
      drawLevel(curMode);
      tft.drawRGBBitmap(enemyX, enemyY, boss_PIX[enemyFrame], boss_MASK[enemyFrame], boss_W, boss_H);
      tft.updateScreen();
    }
  }
}
