#include "Ultrasonic.h"
//#include "Gaz.h"
#include "Heater.h"
#include "Door.h"
#include "Motion.h" 
#include <Bonezegei_DHT11.h>                  
#define PIN_MODE_HOME_MORNING A1
#define PIN_MODE_HOME_NIGHT A2
#define PIN_MODE_OUT_HOME 13
#define BLYNK_TEMPLATE_ID "PUT_TEMPLATE_ID_HERE"
#define BLYNK_TEMPLATE_NAME "Smart Home Alert"
#define BLYNK_AUTH_TOKEN "PUT_AUTH_TOKEN_HERE"
#define ALERT_PIN 2   // GPIO2 في ESP-01
bool lastAlertState = false;
unsigned long lastNotificationTime = 0;
unsigned long notificationCooldown = 30000; // 30 seconds
extern Bonezegei_DHT11 dht;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(Parking_Buzzer, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIN_MODE_HOME_MORNING, INPUT_PULLUP);
  pinMode(PIN_MODE_HOME_NIGHT, INPUT_PULLUP);
  pinMode(PIN_MODE_OUT_HOME, INPUT_PULLUP);
  pinMode(FAN_PIN,OUTPUT);
  initDoor();
  initMotion();
  //digitalWrite(FAN_PIN ,HIGH);
  initMotion();
}
enum SystemMode {
  AtHome_Morning =0,
  AtHome_NIGHT,
  OutOfHome
};
SystemMode mode = AtHome_Morning;
void loop() {
  bool motion =0;
  float distance=0;
  bool door;

  int HOME_MORNING=digitalRead(PIN_MODE_HOME_MORNING);
  int NIGHT =digitalRead(PIN_MODE_HOME_NIGHT);
  int OUT_HOME =digitalRead(PIN_MODE_OUT_HOME);
  
  if (HOME_MORNING){
    mode = AtHome_Morning;
   // Serial.println("Mode: Morning");
    delay(10);
  }
  else if (NIGHT) {
    mode = AtHome_NIGHT;
    Serial.println("Mode: Night");
    delay(10);

  }
  else if(OUT_HOME){
    mode = OutOfHome;
   // Serial.println("Mode: Out of Home");
    delay(10);
  }
  else
  {
    /*do no thing*/
  }

     Ultrasonic_fun();
      heater();
     isMotionDetected();
     isDoorOpen();       



}
