/*
 * Uses HC-06 bluetooth module as slave
 */
 
#define STRENGTH 100

const int vPin5 = 5;
const int vPin6 = 6;

// serial input state
int state;

void setup() {
  Serial.begin(9600);

  // set motors as output
  pinMode(vPin5, OUTPUT);
  pinMode(vPin6, OUTPUT);
}

void loop() {
  if (Serial.available()) { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.println(state);
  } else {
    Serial.println("No comm");
    delay(1000);
  }

  if (state == 1) { // turn vibration motors on
    analogWrite(vPin5, STRENGTH);
    analogWrite(vPin6, STRENGTH);
  } else if (state == 0) { // turn vibration motors off
    analogWrite(vPin5, 0);
    analogWrite(vPin6, 0);
  }
}
