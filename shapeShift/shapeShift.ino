#include <Servo.h>
#include "DHT.h"

/* TEMP SENSOR */
#define DHTPIN 2 // input digital pin 2
#define DHTTYPE DHT11
#define TEMPSET 27.00
DHT dht(DHTPIN, DHTTYPE);

// servo objects to control sleeves
Servo serv1; // fl
Servo serv2; // bl
Servo serv3; // fr
Servo serv4; // br

// open or close sleeves
boolean btnDebug = true;

// debug messages
boolean debugMsgs = false;

void setup() {
  Serial.begin(9600);

  // attaches the servo on pins
  serv1.attach(5);
  serv2.attach(6);
  serv3.attach(10);
  serv4.attach(11);

  // t+h sensor starts
  dht.begin();
}

void loop() {
  int sensor = analogRead(A1);
  Serial.println(sensor);
  delay(500);

  /* TOUCH SENSOR */
  // touch sensor activates
  if (sensor > 1000) {
    btnDebug = !btnDebug;
    
    if (btnDebug) { // open sleeves
      Serial.println("Button On");
      
      for (int pos = 0; pos <= 180; pos += 1) {
        serv1.write(pos);
        serv2.write(180 - pos);
        serv3.write(180 - pos);
        serv4.write(pos);
        delay(10);
      }
    } else {
      Serial.println("Button Off");
      for (int pos = 180; pos >= 0; pos -= 1) {
        serv1.write(pos);
        serv2.write(180 - pos);
        serv3.write(180 - pos);
        serv4.write(pos);
        delay(10);
      }
    }
  }


  /* TEMP SENSOR */
  //  float h = dht.readHumidity(); // read humidity
  //  float t = dht.readTemperature();  // read temp
  //
  //  if (isnan(h) || isnan(t)) { // error handling
  //    Serial.println("Failed to read from DHT sensor!");
  //    return;
  //  }
  //
  //  float hic = dht.computeHeatIndex(t, h, false);  // heat index in celcius
  //
  //  if (debugMsgs) {
  //    Serial.print("Humidity: ");
  //    Serial.print(h);
  //    Serial.print(" %\t");
  //    Serial.print("Temperatur: ");
  //    Serial.print(t);
  //    Serial.print(" *C ");
  //    Serial.print("Heat index: ");
  //    Serial.print(hic);
  //    Serial.println(" *C ");
  //  }
  //
  //  if(hic > TEMPSET) {
  //    Serial.println("high temp - apart");
  //
  //    for (int pos = 0; pos <= 180; pos += 1) { 
  //      serv1.write(pos);                 
  //      serv2.write(180 - pos);
  //      serv3.write(180 - pos);
  //      serv4.write(pos);
  //      delay(10);
  //    }
  //  } else {
  //    Serial.println("low temp - together");
  //
  //    for (int pos = 0; pos <= 180; pos += 1) { 
  //      serv1.write(pos);                 
  //      serv2.write(180 - pos);
  //      serv3.write(180 - pos);
  //      serv4.write(pos);
  //      delay(10);
  //    }
  //  }
}
