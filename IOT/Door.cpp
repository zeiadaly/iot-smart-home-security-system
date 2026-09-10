#include "Door.h"

void initDoor() {
  pinMode(DOOR_PIN, INPUT_PULLUP);
}

void isDoorOpen() {
  int DOOR_STATE =0;
  DOOR_STATE = digitalRead(DOOR_PIN);
 Serial.print("DOOOOOOOOOOOOOOOOR: ");
  delay(100);
    if (DOOR_STATE ==1){
    digitalWrite(Parking_Buzzer, HIGH);
  } else {
    digitalWrite(Parking_Buzzer, LOW);
  }
  delay(100);
}
