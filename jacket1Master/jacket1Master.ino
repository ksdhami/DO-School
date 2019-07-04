/*
 * Uses HC-05 bluetooth module as master
 */
#define STRENGTH 100

const int vPin5 = 5;
const int vPin6 = 6;

// start and stop vibrations
boolean btnDebug = false;

void setup() {
  Serial.begin(9600);

  // set motors as output
  pinMode(vPin5, OUTPUT);
  pinMode(vPin6, OUTPUT);
}

void loop() {
  int sensor = analogRead(A1);
  Serial.println(sensor);
  delay(500);

  // touch sensor activated
  if (sensor > 1000) {
    btnDebug = !btnDebug;
    
    if (btnDebug) { // send data to turn vibration motors on
      Serial.write(1);
      Serial.println("comm 1 sent");
      delay(1000);

      // turn own motors on
      analogWrite(vPin5, STRENGTH);
      analogWrite(vPin6, STRENGTH);
    } else { // send data to turn vibration motors off
      Serial.write(0);
      Serial.println("comm 0 sent");
      delay(1000);

      // turn own motors off
      analogWrite(vPin5, 1);
      analogWrite(vPin6, 1);
    }
  }
}
