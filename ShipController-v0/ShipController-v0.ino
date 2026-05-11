#include <Joystick.h>

//**** Potentiometers ****
int enginePort = A0;
int engineStbd = A1;
int rudder = A2;

//**** Buttons ****
int play = 0;
int view = 1;
int speed = 2;
int horn = 3;

// Creating the Joystick
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK, // Type of joystick
  4, // number of boutons
  0, // hat switches
  true, // X
  true, // Y
  false, // Z
  false, // Rx
  false, // Ry
  false, // Rz
  true, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false  // steering
);

void setup() {
  // Initialisation of the joystick
  Joystick.begin();
}

void loop() {

  //**** Update joystick values ****
  // Potentiometers
  Joystick.setXAxis(analogRead(enginePort));
  Joystick.setYAxis(analogRead(engineStbd));
  Joystick.setRudder(analogRead(rudder));

  //Buttons
  Joystick.setButton(0, digitalRead(play));
  Joystick.setButton(1, digitalRead(view));
  Joystick.setButton(2, digitalRead(speed));
  Joystick.setButton(3, digitalRead(horn));

  // Update delay
  delay(100);
}
