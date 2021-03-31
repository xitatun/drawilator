#include <Servo.h>

String cCode;

Servo servoA;
Servo servoB;
Servo servoC;

jekaCode polibomu;

void setup() {


servoA.attach(4);
servoB.attach(3);
servoC.attach(1);

}

void loop() {

if (Serial.available()>0){
  cCode = Serial.read();
  set_gCode(cCode);
  }
  normalno();
}
