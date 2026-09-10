#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

#define BUZZER_PIN 8

void updateBuzzer(bool doorOpen,
                  bool accessGranted,
                  bool gasDanger,
                  bool objectNear,
                  bool wrongCard);

#endif
