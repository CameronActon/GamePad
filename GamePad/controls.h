#include <Bounce2.h>

int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[] = {0, 1, 2, 3};
int buttonBuffer[] = {0, 0, 0, 0};

int joystickPins[] = {A0, A1};
int joystickBuffer[] = {0, 0};
int joystickX;
int joystickY;

void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

void getControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].fell()) { buttonBuffer[i] =  1;} // button is not pressed anymore
    if (buttons[i].rose()) { buttonBuffer[i] = 0;} // button was just pressed

//    Serial.print(buttonBuffer[i]);
//    Serial.print("\t");
  }
  
  joystickX = analogRead(joystickPins[1]);
  joystickY = analogRead(joystickPins[0]);

  if(joystickX > 750){ joystickBuffer[0] = -1; }
  else if(joystickX < 450) { joystickBuffer[0] = 1; }
  else { joystickBuffer[0] = 0; }

  if(joystickY > 750){ joystickBuffer[1] = 1; }
  else if(joystickY < 450) { joystickBuffer[1] = -1; }
  else { joystickBuffer[1] = 0; }

//  Serial.print(joystickBuffer[0]);
//  Serial.print("\t");
//  Serial.print(joystickBuffer[1]);  
//  Serial.println();
}
