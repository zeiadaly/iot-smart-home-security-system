#include "Motion.h"

void initMotion() {
  pinMode(PIR_PIN, INPUT);
}

bool isMotionDetected() {
 bool motion = digitalRead(PIR_PIN); 
 
 if (motion ==HIGH){
      digitalWrite(ALARM_BUZZER, HIGH);
  } else {
    digitalWrite(ALARM_BUZZER, LOW);
  }
    Serial.print("MOTION: ");
  Serial.print(motion);
  return motion;

 
}
