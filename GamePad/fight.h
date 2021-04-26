int getHitChance = 60;

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
  bool canFight = checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, enemyW,enemyH);

//  Serial.println(heroHealth);
  Serial.println(enemyHealth);
  
  if(canFight){
    //Hero Attacking the Enemy
    if(buttonBuffer[1] == 1 || buttonBuffer[2] == 1){ 
        enemyHealth -= heroDam;

      if(enemyHealth <= 0){
        enemyStatus = false;

        tft.setClipRect(enemyX - 2, enemyY - 2, enemyW + 4, enemyH + 4);
        drawLevel(curMode);
        tft.updateScreen();

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
