/*
HC-SR04 Ping distance sensor
VCC to Arduino 5V
GND to Arduino GND
Echo to Arduino pin 13
Trig to Arduino pin 12
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
Modified by Tolson Winters (Aug 27, 2014) for simplified serial monitor reading.
*/

#define trigPin 5
#define echoPin 4

String str;

void setup() {
  Serial.begin (9600);
  Serial1.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 2000 ) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  
    str =String("coming from ESP8266: ")+String("Distance= ")+String(distance);
    Serial1.println(str);
  }
  delay(500);
}
