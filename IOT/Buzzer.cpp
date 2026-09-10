#include "Buzzer.h"

void updateBuzzer(bool doorOpen,
                  bool accessGranted,
                  bool gasDanger,
                  bool objectNear,
                  bool wrongCard)
{

  bool intruderDanger = false;
  bool anyDanger = false;

  // Intruder detection
  if (doorOpen == true && accessGranted == false)
  {
    intruderDanger = true;
  }

  // Any danger condition
  if (intruderDanger == true ||
      objectNear == true ||
      wrongCard == true)
  {
    anyDanger = true;
  }
  else
  {
    anyDanger = false;
  }

  // Final buzzer control
  if (anyDanger == true)
  {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
