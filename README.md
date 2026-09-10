# IoT-Based Smart Home Safety & Security System

Team project — **ECEN241, Computer Systems Engineering, Nile University** (submitted May 2026)

Team: Farah Al Aidy, Habiba El Bakly, **Zeiad Aly**

## Overview

An Arduino Uno-based smart home safety and security system that combines multiple sensors with a Wi-Fi module to monitor a home in real time and respond automatically to security and environmental events. Alerts are raised locally through a piezo buzzer and remotely through push notifications on the Blynk IoT platform.

## System Components

| Component | Model | Role |
|---|---|---|
| Microcontroller | Arduino Uno (ATmega328P) | Central control unit |
| Motion Sensor | PIR HC-SR501 | Detects movement, triggers alarm |
| Ultrasonic Sensor | HC-SR04 | Detects nearby objects/intruders |
| Door Sensor | MC-36 Magnetic Reed Switch | Detects unauthorized door opening |
| Temp./Humidity Sensor | DHT11 | Monitors climate, drives cooling fan |
| Wi-Fi Module | ESP8266 ESP-01 | Sends push notifications via Blynk |
| Buzzer | 3–24V Piezo | Local audible alarm |
| Fan | 5V DC Motor | Automatic cooling above threshold |

## How It Works

- **Motion / Door / Proximity:** the PIR sensor, the magnetic door reed switch, and the HC-SR04 ultrasonic sensor are polled continuously. Any of the three triggers the piezo buzzer alarm and a Blynk push notification within 1-4 seconds.
- **Temperature:** the DHT11 sensor is sampled regularly; once the reading exceeds a configurable threshold (35°C in testing), the system automatically switches on a cooling fan and turns it off once the temperature drops back down.
- **Modes:** the system supports three operating modes selected via input pins — At Home (Morning), At Home (Night), and Out of Home — so behaviour can be adapted to the household's routine.
- **Remote alerts:** an ESP8266 ESP-01 module relays every event to the Blynk IoT platform, so the homeowner gets a smartphone notification even when away.

## My Contribution (Zeiad Aly)

Working within the 3-person team, I implemented the sensor-driving firmware modules: the ultrasonic distance sensor (`Ultrasonic.cpp/.h`), the door reed-switch logic (`Door.cpp/.h`), the PIR motion detection logic (`Motion.cpp/.h`), the temperature-controlled fan/heater logic (`Heater.cpp/.h`), and the buzzer decision logic combining door, access and proximity states (`Buzzer.cpp/.h`), alongside the main mode-switching loop in `IOT.ino`.

## Results

- PIR sensor: reliable detection up to ~5 m, buzzer response under 200 ms.
- Door sensor: door-open to alarm response under 50 ms, Blynk alert within 2 s.
- Ultrasonic sensor: accurate to ±1 cm up to 100 cm, alert triggered under the 50 cm threshold.
- DHT11 + fan: correctly activated the cooling fan within one 2-second sampling cycle above 35°C.
- Full system ran 2+ continuous hours in final testing with no hardware failures.

## Tools & Technologies

Arduino Uno, C/C++ (Arduino IDE), PIR HC-SR501, HC-SR04 Ultrasonic Sensor, MC-36 Magnetic Reed Switch, DHT11, ESP8266 ESP-01, Blynk IoT Platform

## Future Improvements

- Gas/smoke sensor (MQ-2/MQ-5) for fire detection
- RFID-based access control (RC522) for authorized entry logging
- Camera module for visual verification
- Migration from ESP8266 ESP-01 to ESP32
- Cloud data logging and historical analytics

---
[Connect on LinkedIn](https://www.linkedin.com/in/zeiad-aly/) · [More projects](https://github.com/zeiadaly)
