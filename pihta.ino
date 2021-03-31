#include <Servo.h>
#include <angle_v3.h>

String cCode;

Servo servoA;
Servo servoB;
Servo servoC;

jekaCode kyoka;

void setup() {

Serial.begin(9600);

servoA.attach(4);
servoB.attach(3);
servoC.attach(1);

}

void loop() {

if (Serial.available()>0){
  cCode = Serial.read();
  kyoka.set_gCode(cCode);
}
  normalno();
}
