#include <Wire.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#define trigPin 26
#define echoPin 27
#define trigPin_1 33
#define echoPin_1 25
#define servoPin 32
#define buzzer 35

long duration;
int distance;
long duration_1;
int distance_1;

Servo myServo; 

int pos = 0;   

void readD() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(20);
  
 
  if (distance < 20) {
    myServo.write(90); 
    digitalWrite(buzzer, HIGH); // Turn the buzzer on
    delay(1000); // hold the servo motor in position and buzzer on for 1 second
    myServo.write(0); // return the servo motor to its original position
    digitalWrite(buzzer, LOW); // Turn the buzzer off
  }
}

void readD_1() {
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  distance_1 = duration_1 * 0.034 / 2;
  Serial.print("Distance_1: ");
  Serial.println(distance_1);
  delay(20);
}

void setup()
{
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myServo.setPeriodHertz(50);    // standard 50 hz servo
	myServo.attach(servoPin, 1000, 2000); // attaches
  Serial.println("Hello");
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin_1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_1, INPUT); // Sets the echoPin as an Input
  
  pinMode(servoPin, OUTPUT); // Set the servo pin as an output
  pinMode(buzzer, OUTPUT); // Set the buzzer pin as an output
  myServo.attach(servoPin); // Attach the servo motor to the pin
}

void loop()
{
  readD();
  readD_1();
  delay(50);
}