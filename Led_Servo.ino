#define red D0
#define green D1
#define blue D2
#define ser D3
#include <Servo.h>
Servo servo;
int deg=0;
void setup() {
  pinMode(red, LOW);
  pinMode(green, LOW);
  pinMode(blue, LOW);
  Serial.begin(9600);
  servo.attach(ser);
  servo.write(0);
  delay(1000);
}

void loop() {
  deg=180;
  servo.write(deg);
  delay(1000);
  if(deg == 180){
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 255);
  }
  deg=0;
  servo.write(deg);
  delay(1000);
  if(deg == 0){
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
}
