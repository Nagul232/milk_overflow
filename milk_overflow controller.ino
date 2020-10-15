#include <Servo.h>
const int trigpin=6;
const int echopin=10;
long duration;
int distance;
Servo servo1;
void setup() 
{
  pinMode(6,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
  servo1.attach(9);
  servo1.write(0); 
}
void loop()
{
 digitalWrite(trigpin, LOW);
delayMicroseconds(2);
 digitalWrite(trigpin, HIGH);
delayMicroseconds(2);
 digitalWrite(trigpin, LOW);
delayMicroseconds(10);
 duration=pulseIn(echopin, HIGH);
 distance=duration*0.034/2;
 Serial.println(distance);
 delay(500);
 if(distance<=8)
 {
  Serial.println("Servo on");
  servo1.write(90);
 }
}
