#include "enemy_MASK.h"
#include "enemy_PIX.h"

#define enemyW 16
#define enemyH 16

Metro enemyFrameTimer = Metro(250);
Metro enemyBrainTimer = Metro(1000);

int enemyMargin = 1;
float enemyX = 0;
int enemyW = 32;
int enemyStatus = 1;
float enemyY = 0;
int enemyH = 32;
int enemyType = 0; 
float enemyXDir = 0;
int enemyFrame = 0;
int enemyHealth = 1; 
float enemyYDir = 0;
int enemySmart = 3;
float enemySpeed = 0.15;


void animateEnemy(){
  if(enemyFramTimer.check()){
    if(enemy
  }
}
void drawEnemy(){
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

  float nextX = enemyX + (enemyXDir * enemySpeed);
  float nextY = enemyY + (enemyYDir * enemySpeed);

  if(checkMove(curMode, nextX, nextY, enemyW, enemyH)){
    enemyX = nextX;
    enemyY = nextY;
  }

  if(
}
