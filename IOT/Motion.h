#ifndef MOTION_H
#define MOTION_H
#include <Arduino.h>

#define PIR_PIN 13 
#define ALARM_BUZZER 8
void initMotion();
bool isMotionDetected();

#endif
