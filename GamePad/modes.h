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

void introScreen() {
  if (!initIntro) {
    tft.setClipRect(0, 0, screenW, screenH);
    //tft.drawRGBBitmap(x, y, graphic[0], w, h);
    tft.fillScreen(ILI9341_BLACK);
    tft.updateScreen();
    initIntro = true;
  }

  for (int i = 0; i < 4; i++) {
    if (buttonBuffer[i]) {
      curMode = 0;
    }
  }
}

void level0() {             //Amulet Room
  if (!initLvl0) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    displayHearts(0);
    displayPowers(1,1);
    initLvl0 = true;
  }

  drawLevel(curMode);
  drawHero();

  //if(interaction[curMode][curTile] == 0x02 && buttonBuffer[3] == 1){updatePower(1);} //Pick Up Amulet
  if(interaction[curMode][curTile] == 0x03 && buttonBuffer[3] == 1){curMode = 1; initLvl0 = false; heroX = 150; heroY = 130;} //Advance to Cave Hole Room
}

void level1() {             //Cave Hole Room
  if (!initLvl1) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl1 = true;
  }

  drawLevel(curMode);
  drawHero();
  
  if(interaction[curMode][curTile] == 0x04 && buttonBuffer[3] == 1){curMode = 0; initLvl1 = false; heroX = 150; heroY = 30;} //Return to Amulet Room
  if(interaction[curMode][curTile] == 0x05 && buttonBuffer[3] == 1){curMode = 2; initLvl1 = false; heroX = 150; heroY = 100;} //Advance to "First Room"
}

void level2() {             //"First Room"
  if (!initLvl2) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    enemyX = 30;
    enemyY = 30;
    initLvl2 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();

  if(interaction[curMode][curTile] == 0x06 && buttonBuffer[3] == 1){curMode = 3; initLvl2 = false; heroX = 30; heroY = 75;} //Advance to Level Three
}

void level3() {             //Level Three
  if (!initLvl3) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl3 = true;
  }

  drawLevel(curMode);
  drawHero();

  
  if(interaction[curMode][curTile] == 0x07 && buttonBuffer[3] == 1){curMode = 2; initLvl3 = false; heroX = 275; heroY = 75;} //Return to "First Room"
  if(interaction[curMode][curTile] == 0x08 && buttonBuffer[3] == 1){curMode = 4; initLvl3 = false; heroX = 150; heroY = 130;} //Advance to Level Four
}

void level4() {             //Level Four
  if (!initLvl4) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl4 = true;
  }

  drawLevel(curMode);
  drawHero();
  
  if(interaction[curMode][curTile] == 0x09 && buttonBuffer[3] == 1){curMode = 3; initLvl4 = false; heroX = 150; heroY = 30;} //Return to Level Three
  if(interaction[curMode][curTile] == 0x0A && buttonBuffer[3] == 1){curMode = 5; initLvl4 = false; heroX = 30; heroY = 75;} //Advance to Clovis Merchant Room
}

void level5() {             //Clovis Merchant Room
  if (!initLvl5) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl5 = true;
  }

  drawLevel(curMode);
  drawHero();
  
  if(interaction[curMode][curTile] == 0x0B && buttonBuffer[3] == 1){curMode = 4; initLvl5 = false; heroX = 275; heroY = 75;} //Return to Level Four
  //if(interaction[curMode][curTile] == 0x0C && buttonBuffer[3] == 1){updatePower(1);} //Add extra heart item
  //if(interaction[curMode][curTile] == 0x0D && buttonBuffer[3] == 1){updatePower(1);} //Add Arrow Up Item
  //if(interaction[curMode][curTile] == 0x0E && buttonBuffer[3] == 1){updatePower(1);} //Add Speed Up Item
  if(interaction[curMode][curTile] == 0x0F && buttonBuffer[3] == 1){curMode = 6; initLvl5 = false; heroX = 30; heroY = 75;} //Advance to Level Six
}

void level6() {             //Level Six
  if (!initLvl6) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl6 = true;
  }

  drawLevel(curMode);
  drawHero();

  if(interaction[curMode][curTile] == 0x10 && buttonBuffer[3] == 1){curMode = 5; initLvl6 = false; heroX = 275; heroY = 75;} //Return to Clovis Merchant Room
  if(interaction[curMode][curTile] == 0x11 && buttonBuffer[3] == 1){curMode = 7; initLvl6 = false; heroX = 150; heroY = 30;} //Advance to Level Seven
}

void level7() {             //Level Seven
  if (!initLvl7) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl7 = true;
  }

  drawLevel(curMode);
  drawHero();

  if(interaction[curMode][curTile] == 0x12 && buttonBuffer[3] == 1){curMode = 6; initLvl7 = false; heroX = 150; heroY = 130;} //Return to Level Six
  if(interaction[curMode][curTile] == 0x13 && buttonBuffer[3] == 1){curMode = 8; initLvl7 = false; heroX = 30; heroY = 75;} //Advance to Ogre Boss Level
}

void level8() {             //Ogre Boss Room
  if (!initLvl8) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    initLvl8 = true;
  }

  drawLevel(curMode);
  drawHero();

  if(interaction[curMode][curTile] == 0x14 && buttonBuffer[3] == 1){curMode = 7; initLvl8 = false; heroX = 275; heroY = 75;} //Return to Ogre Boss Room
}

void runMode() {
 // Serial.println(curMode);
  switch (curMode) {
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
  }
}
