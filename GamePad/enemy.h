#include "enemy_MASK.h"
#include "enemy_PIX.h"

#define enemyW 16
#define enemyH 16

Metro enemyFrameTimer = Metro(100);
Metro enemyBrainTimer = Metro(1000);

float enemyX = 0;
float enemyY = 0;

int enemyStatus = 1;

int enemyType = 0; 

float enemyXDir = 0;
float enemyYDir = 0;

int enemyFrame = 0;
int enemyHealth = 1; 

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

  if(checkMove(curMode, nextX, nextY, enemyW, enemyH)){
    enemyX = nextX;
    enemyY = nextY;
  }
}

void animateEnemy(){
  if(enemyFrameTimer.check()){
    if(enemyXDir >= 0){ enemyFrame = 0 + ((enemyFrame + 1) % 6); }
    else { enemyFrame = 6 + ((enemyFrame + 1) % 6); }
  }
}

void drawEnemy(){
  updateEnemyDir();
  moveEnemy();
  animateEnemy();  

  tft.setClipRect(enemyX - 2, enemyY - 2, enemyW + 4, enemyH + 4);
  drawLevel(curMode);
  tft.drawRGBBitmap(enemyX, enemyY, enemy_PIX[enemyFrame], enemy_MASK[enemyFrame], enemyW, enemyH);
  tft.updateScreen();
}
