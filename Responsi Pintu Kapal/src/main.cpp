#include <Arduino.h>

int Lorange = D6;
int Lhijau = D5;
int trigPin = D1;
int echoPin = D0;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.print(" cm\n");
  // put your main code here, to run repeatedly:
   if (distance <= 10)
  {
    digitalWrite(Lhijau, HIGH);
    digitalWrite(Lorange, LOW);
  }
  else
  {
     digitalWrite(Lhijau, LOW);
    digitalWrite(Lorange, HIGH);
  }

  delay(1000);
}
