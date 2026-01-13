#include <Joystick.h>

// Crée un objet Joystick
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK, // Type joystick
  0, // boutons
  0, // hat switches
  true, // X
  true, // Y
  false, // Z
  false, // Rx
  false, // Ry
  false, // Rz
  true, // rudder
  true, // throttle
  true, // accelerator
  false, // brake
  true  // steering
);

void setup() {
  // Initialise le joystick
  Joystick.begin();
}

void loop() {
  // Lire la valeur analogique de A0
  int sensorValue = analogRead(A0);

  // Mapper la valeur analogique (0-1023) vers la plage du rudder (-32767 à 32767)
  //int rudderValue = map(sensorValue, 0, 1023, -32767, 32767);

  // Mettre à jour la valeur du rudder
  Joystick.setXAxis(sensorValue);
  Joystick.setYAxis(sensorValue);
  Joystick.setRudder(sensorValue);
  Joystick.setThrottle(sensorValue);
  Joystick.setAccelerator(sensorValue);
  Joystick.setSteering(sensorValue);

  // Petite pause pour stabilité
  delay(100);
}
