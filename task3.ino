#include <Stepper.h>

int stepsPerRevolution = 2048;
int motSpeed = 7;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int speedPin = 5;
int dir1 = 6;
int dir2 = 7;
int mSpeed = 200;

const int trigPin = 4;
const int echoPin = 3 ;
// Variables for the duration and the distance
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  
  myStepper.setSpeed(motSpeed);

  analogWrite(speedPin, 0);

}

void loop() {
  //straight
  distance = calculateDistance();
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW);

  if (distance < 20)
  {
  digitalWrite(7, HIGH);
  myStepper.step(-150);
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW);
  delay(250);
  myStepper.step(150);
  delay(250);
  digitalWrite(7, HIGH);

  myStepper.step(150);
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW);
  delay(500);
  myStepper.step(-150);
  delay(500);

}

}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
