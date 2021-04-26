int getHitChance = 200;

// Check to See if Hero & Enemies Collide
boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = false;                                // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}    // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}    // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}    // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}    // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = true;}
  return canMove;
}

void fight(){
  bool canFight =false;
  if(enemyType == 0) { canFight = checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, enemy_W, enemy_H); }
  else if(enemyType == 1) { canFight = checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, boss_W, boss_H); }

//  Serial.println(heroHealth);
//  Serial.println(enemyHealth);
  
  if(canFight){
    //Hero Attacking the Enemy
    if(buttons[1].rose() || buttons[2].rose()){ 
        enemyHealth -= heroDam;

      if(enemyHealth <= 0){
        enemyStatus = false;

        if(enemyType == 0){
          tft.setClipRect(enemyX - 2, enemyY - 2, enemy_W + 4, enemy_H + 4);
          drawLevel(curMode);
          tft.updateScreen();
        } else if (enemyType == 1){  
          tft.setClipRect(enemyX - 2, enemyY - 2, boss_W + 4, boss_H + 4);
          drawLevel(curMode);
          tft.updateScreen();
        }

        enemyX = 0;
        enemyY = 0;
      }
    }
    
    if(random(getHitChance) == 0){
      heroHealth -= 1;
      displayHearts();

      if(heroHealth <= 0){
        curMode = 9; //Losing Screen

      }
    }
    
  }
}
