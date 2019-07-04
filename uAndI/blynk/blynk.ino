/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc

 *************************************************************
  This example shows how to use Arduino with HC-06/HC-05
  Bluetooth 2.0 Serial Port Profile (SPP) module
  to connect your project to Blynk.

  Note: This only works on Android! iOS does not support SPP :(
        You may need to pair the module with your smartphone
        via Bluetooth settings. Default pairing password is 1234

  NOTE: Bluetooth support is in beta!

 *************************************************************/

#define BLYNK_USE_DIRECT_CONNECT

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(0, 1); // RX, TX

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleSerialBLE.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9569db4b23cb4b1298c74ed38181bc2c"; // uno

// back vibration motors
const int vib9 = 9;
const int vib10 = 10;
// shoulder vibration motors
const int vib5 = 5;
const int vib6 = 6;

// BACK
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  
  pinMode(vib5, OUTPUT);
  pinMode(vib6, OUTPUT);
  
  analogWrite(vib5, pinValue);
  analogWrite(vib6, pinValue);
}

// SHOULDER
BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  
  pinMode(vib9, OUTPUT);
  pinMode(vib10, OUTPUT);
  
  analogWrite(vib9, pinValue);
  analogWrite(vib10, pinValue);
}

void setup() {
  // Debug console
  DebugSerial.begin(9600);

  DebugSerial.println("Waiting for connections...");

  // Blynk will work through Serial
  // 9600 is for HC-06. For HC-05 default speed is 38400
  // Do not read or write this serial manually in your sketch
  Serial.begin(38400);
  Blynk.begin(DebugSerial, auth);

}

void loop() {
  Blynk.run();
}
