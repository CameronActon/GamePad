#include "mmScreens_MASK.h"
#include "mmScreens_PIX.h"

bool initTitle = false;
bool initIntro = false;
bool initLvl0 = false;
bool initLvl1 = false;
bool initLvl2 = false;
bool initLvl3 = false;
bool initLvl4 = false;
bool initLvl5 = false;
bool initLvl6 = false;
bool initLvl7 = false;
bool initLvl8 = false;
bool initLoser = false;
bool initWinner = false;

void resetGame(){
  initTitle = false;
  initIntro = false;
  initLvl0 = false;
  initLvl1 = false;
  initLvl2 = false;
  initLvl3 = false;
  initLvl4 = false;
  initLvl5 = false;
  initLvl6 = false;
  initLvl7 = false;
  initLvl8 = false;
  initLoser = false;
  initWinner = false;

  heroHealth = 3;
  heroX = 150;
  heroY = 120;

  hasAmulet = false;
  chosenItem = false;
  hasDamageBuff = false;
  hasSpeedBuff = false; 

  heroSpeed = 0.5;
  heroDam = 1;

  enemyHealth = 3;
  enemyType = 0;
}

void titleScreen() {
  if (!initTitle) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, mmScreens_PIX[0], screenW, screenH);
    //tft.fillScreen(ILI9341_BLACK);
    tft.updateScreen();
    initTitle = true;
  }

  if(millis() > 1000){
     for (int i = 0; i < 4; i++) {
      if (buttons[i].rose()) {
        curMode = -1;
      }
    }
  }
}

void introScreen() {
  if (!initIntro) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, mmScreens_PIX[1], screenW, screenH);
    tft.updateScreen();
    initIntro = true;
  }

  for (int i = 0; i < 4; i++) {
    if (buttons[i].rose()) {
      curMode = 0;
    }
  }
}

void level0() {             //Amulet Room
  if (!initLvl0) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    
    displayHearts();
    displayPowers();
    
    initLvl0 = true;
  }

  drawLevel(curMode);
  displayEntity(4, (screenW/2) - (powers_W/2), 55); //Amulet
  drawHero();

  if(interaction[curMode][curTile] == 0x02 && buttons[0].rose()){ //Pick Up Amulet
    if(!hasAmulet){
      tft.setClipRect(40, 40, screenW - 40, screenH - UIHeight - 40); 
      drawLevel(curMode);
      hasAmulet = true;
    } 
  }
  if(hasAmulet){if(interaction[curMode][curTile] == 0x03 && buttonBuffer[3] == 1){curMode = 1; initLvl0 = false; heroX = 150; heroY = 130;}} //Advance to Cave Hole Room
}

void level1() {             //Cave Hole Room
  if (!initLvl1) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    
    displayHearts();
    displayPowers();
    
    initLvl1 = true;
  }

  drawLevel(curMode);
  drawHero();
  
  if(interaction[curMode][curTile] == 0x04 && buttonBuffer[3] == 1){curMode = 0; initLvl1 = false; heroX = 150; heroY = 40;} //Return to Amulet Room
  if(interaction[curMode][curTile] == 0x05 && buttonBuffer[3] == 1){curMode = 2; initLvl1 = false; heroX = 150; heroY = 100;} //Advance to "First Room"
}

void level2() {             //"First Room"
  if (!initLvl2) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();

    enemyX = 30;
    enemyY = 30;
    enemyHealth = 3;
    enemyStatus = true;
    initLvl2 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(enemyHealth == 0)
  if(interaction[curMode][curTile] == 0x06 && buttonBuffer[3] == 1){curMode = 3; initLvl2 = false; heroX = 40; heroY = 75;} //Advance to Level Three
}

void level3() {             //Level Three
  if (!initLvl3) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();


    enemyX = 250;
    enemyY = 100;
    enemyHealth = 3;
    enemyStatus = true;
    initLvl3 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  
  if(enemyHealth == 0){
    if(interaction[curMode][curTile] == 0x07 && buttonBuffer[3] == 1){curMode = 2; initLvl3 = false; heroX = 275; heroY = 75;} //Return to "First Room"
    if(interaction[curMode][curTile] == 0x08 && buttonBuffer[3] == 1){curMode = 4; initLvl3 = false; heroX = 150; heroY = 130;} //Advance to Level Four
  }
}

void level4() {             //Level Four
  if (!initLvl4) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();

    enemyX = 150;
    enemyY = 70;
    enemyHealth = 3;
    enemyStatus = true;
    initLvl4 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(enemyHealth == 0){
    if(interaction[curMode][curTile] == 0x09 && buttonBuffer[3] == 1){curMode = 3; initLvl4 = false; heroX = 150; heroY = 40;} //Return to Level Three
    if(interaction[curMode][curTile] == 0x0A && buttonBuffer[3] == 1){curMode = 5; initLvl4 = false; heroX = 40; heroY = 75;} //Advance to Clovis Merchant Room
  }
}

void level5() {             //Clovis Merchant Room
  if (!initLvl5) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();
    
    initLvl5 = true;
  }

  drawLevel(curMode);
  displayEntity(0, (screenW/3) - (hearts_W) - 8, screenH - UIHeight - 85); //heart
  displayEntity(1, (screenW/2) - (powers_W/2), screenH - UIHeight - 95); //Bow Upgrade
  displayEntity(3, screenW - (screenW/3) - (powers_W/2) + 13, screenH - UIHeight - 95); //Boots Upgrade
  drawHero();
  
  if(interaction[curMode][curTile] == 0x0B && buttonBuffer[3] == 1){curMode = 4; initLvl5 = false; heroX = 275; heroY = 75;} //Return to Level Four
  if(interaction[curMode][curTile] == 0x0C && buttons[0].rose()){ //Refill Hearts
    heroHealth = 3; 
    displayHearts(); 

    if(!chosenItem){
      tft.setClipRect(40, 40, screenW - 40, screenH - UIHeight - 40); 
      drawLevel(curMode);
      tft.updateScreen();
      chosenItem = true; 
    }
    
    displayPowers();
  } 
  if(interaction[curMode][curTile] == 0x0D && buttons[0].rose()){ //Add Arrow Up Item
    if(!chosenItem){
      hasDamageBuff= true;
      heroDam = 3;
    
      tft.setClipRect(40, 40, screenW - 40, screenH - UIHeight - 40);
      drawLevel(curMode);
      tft.updateScreen();
      chosenItem = true;
    }
    
    displayPowers();
  } 
  if(interaction[curMode][curTile] == 0x0E && buttons[0].rose()){ //Add Speed Up Item
    if(!chosenItem){
      hasSpeedBuff= true;
      heroSpeed = 0.8;
    
      tft.setClipRect(40, 40, screenW - 40, screenH - UIHeight - 40);
      drawLevel(curMode);
      tft.updateScreen();
      chosenItem = true;
    }
    
    displayPowers();
  } 
  if(interaction[curMode][curTile] == 0x0F && buttonBuffer[3] == 1){curMode = 6; initLvl5 = false; heroX = 40; heroY = 75;} //Advance to Level Six
}

void level6() {             //Level Six
  if (!initLvl6) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();

    enemyX = 250;
    enemyY = 75;
    enemyHealth = 3;
    enemyStatus = true;
    initLvl6 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();


  if(enemyHealth == 0){
    if(interaction[curMode][curTile] == 0x10 && buttonBuffer[3] == 1){curMode = 5; initLvl6 = false; heroX = 275; heroY = 75;} //Return to Clovis Merchant Room
    if(interaction[curMode][curTile] == 0x11 && buttonBuffer[3] == 1){curMode = 7; initLvl6 = false; heroX = 150; heroY = 40;} //Advance to Level Seven
  }
}

void level7() {             //Level Seven
  if (!initLvl7) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();

    enemyType = 0;

    enemyX = 50;
    enemyY = 120;
    enemyHealth = 3;
    enemyStatus = true;
    initLvl7 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  
  if(enemyHealth == 0){
    if(interaction[curMode][curTile] == 0x12 && buttonBuffer[3] == 1){curMode = 6; initLvl7 = false; heroX = 150; heroY = 130;} //Return to Level Six
    if(interaction[curMode][curTile] == 0x13 && buttonBuffer[3] == 1){curMode = 8; initLvl7 = false; heroX = 40; heroY = 75;} //Advance to Ogre Boss Level
  }
}

void level8() {             //Ogre Boss Room
  if (!initLvl8) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts();
    displayPowers();

    enemyType = 1;
    
    enemyX = 150;
    enemyY = 90;
    enemyHealth = 9;
    enemyStatus = true;
    initLvl8 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(interaction[curMode][curTile] == 0x14 && buttonBuffer[3] == 1){curMode = 7; initLvl8 = false; heroX = 275; heroY = 75;} //Return to Level Seven

  if(enemyHealth <= 0){
    delay(500);
    curMode = 10;
  }
}

void loseScreen() {
  if (!initLoser) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, mmScreens_PIX[2], screenW, screenH);
    tft.updateScreen();
    initLoser = true;
  }

  for (int i = 0; i < 4; i++) {
    if (buttons[i].rose()) {
      curMode = -2;

      resetGame();
    }
  }
}

void winScreen() {
  if (!initWinner) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, mmScreens_PIX[3], screenW, screenH);
    tft.updateScreen();
    initWinner = true;
  }

  for (int i = 0; i < 4; i++) {
    if (buttons[i].rose()) {
      curMode = -2;

      resetGame();
    }
  }
}

void runMode() {
 // Serial.println(curMode);
  switch (curMode) {
    case -2: titleScreen(); break;
    case -1: introScreen(); break;
    case 0: level0(); break;
    case 1: level1(); break;
    case 2: level2(); break;
    case 3: level3(); break;
    case 4: level4(); break;
    case 5: level5(); break;
    case 6: level6(); break;
    case 7: level7(); break;
    case 8: level8(); break;
    case 9: loseScreen(); break;
    case 10: winScreen(); break;
  }
}
