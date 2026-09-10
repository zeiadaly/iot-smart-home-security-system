#include "Heater.h"
Bonezegei_DHT11 dht(6);

void heater(){
  if (dht.getData()) {                         
    float tempDeg = dht.getTemperature();     
    float tempFar = dht.getTemperature(true);  
    int hum = dht.getHumidity();               
    String str  = "Temperature: ";
           str += tempDeg;
           str += "°C  ";
           str += tempFar;
           str += "°F  Humidity:";
           str += hum;
    Serial.println(str.c_str());
    if (tempFar>77)
    {
      digitalWrite(FAN_PIN , HIGH);
    }
    else {
      digitalWrite(FAN_PIN , LOW);
    }
    
  }
  delay(100);  



}
