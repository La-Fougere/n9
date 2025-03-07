#include <Servo.h>

const int targetPin = 2;
const int servoPin = 3;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(targetPin, OUTPUT);
  digitalWrite(targetPin, LOW);
  
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    String request = Serial.readStringUntil('\n');

    if (request.indexOf("HTTP") != -1) {
      Serial.println("Requête HTTP reçue");
      
      if (request.indexOf("ON") != -1) {
        digitalWrite(targetPin, HIGH); // Activer le pin 2
        Serial.println("Pin 2 mis à HIGH et servomoteur à 150 degrés");
        delay(1000);
        myServo.write(150);
      }
      else if (request.indexOf("OFF") != -1) {
        digitalWrite(targetPin, LOW);
        myServo.write(0);
        Serial.println("Pin 2 mis à LOW et servomoteur à 0 degré");
      }
    }
  }
}
