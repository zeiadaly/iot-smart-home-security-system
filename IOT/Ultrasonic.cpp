#include "Arduino.h"
#include "Ultrasonic.h"

 float Ultrasonic_fun(){
  long duration;
  float distanceCm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distanceCm = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  if ((distanceCm <= 8) && (distanceCm >0)) {
    digitalWrite(Parking_Buzzer, HIGH);
  } else {
    digitalWrite(Parking_Buzzer, LOW);
  }
  return  distanceCm ;
  
}
