#include <Servo.h>
#define DEGREE 100

// servo objects to control moving bag structure
Servo myservo5;
Servo myservo6;

// hide and reveal panels
boolean btnTouch = false;

// touch sensor reading
int sensor;

void setup() {
  Serial.begin(9600);

  // attaches the servo on pins
  myservo5.attach(5); 
  myservo6.attach(6);
}

void loop() {
  sensor = analogRead(A1);
  Serial.println(sensor);
  delay(500);

  // touch sensors ativated
  if(sensor > 900) {
    btnTouch = !btnTouch;

    if(btnTouch) { // show panels
      Serial.println("Button True");
      
      // servo reveals panels moving 100 degrees
      for (int pos = 0; pos <= DEGREE; pos += 1) {
        myservo5.write(pos); // clockwise
        myservo6.write(180-pos); // counter-clockwise
        delay(10); // control speed of servo
      }
    } else { // hide panels
      Serial.println("Button False");
      
      // servo hides panels moving 100 degrees
      for (int pos = DEGREE; pos >= 0; pos -= 1) {
        myservo5.write(pos); // counter-clockwise 
        myservo6.write(180-pos); // clockwise
        delay(10); // control speed of servo
      }
    }
  }
}
