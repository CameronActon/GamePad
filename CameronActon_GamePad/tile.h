#include "backgroundTiles_MASK.h"
#include "backgroundTiles_PIX.h"

#define tileW 16         // 16 Tiles Across
#define tileH 12         // 12 Tiles Down
#define tileSize 20      // Tile Width (in pixels)
#define numLevels 6      // Number of Levels

int levels[numLevels][tileW * tileH] {
  // Level 0 - Amulet Room
  {
    0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x09, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x01, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0B, 0x0A ,0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02,
    
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  },
  // Level 1 - Cave Hole Room
  {
    0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x09, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x15, 0x13, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x16, 0x14, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x04, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x06,
    0x01, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0B, 0x0A ,0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02,
    
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  },
};

void drawLevel(int thisLevel) {
  for (int y = 0; y < tileH; y++) {
    for (int x = 0; x < tileW; x++) {
      int index = x + (y * tileW);
      int whichTile = levels[thisLevel][index];

      int finalX = x * tileSize;
      int finalY = y * tileSize;
      tft.drawRGBBitmap(finalX, finalY, backgroundTiles_PIX[whichTile], tileSize, tileSize);
    }
  }
}
