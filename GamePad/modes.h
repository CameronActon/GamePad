bool initIntro = false;
bool initLvl0 = false;
bool initLvl1 = false;
bool initLv12 = false;
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

void level0() {
  if (!initLvl0) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    initLvl0 = true;
  }

  drawLevel(curMode);
  drawHero();
}

void level1() {
  if (!initLvl1) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(1);
    tft.updateScreen();
    initLvl1 = true;
  }

  drawLevel(curMode);
  drawHero();
}

void runMode() {
  switch (curMode) {
    case -1: introScreen(); break;
    case 0: level0(); break;
    case 1: level1(); break;
//    case 2: level2(); break;
//    case 3: level3(); break;
//    case 4: level4(); break;
//    case 5: level5(); break;
//    case 6: level6(); break;
//    case 7: level7(); break;
//    case 8: level8(); break;
  }
}
