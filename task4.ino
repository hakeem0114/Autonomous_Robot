#include <Stepper.h>

int stepsPerRevolution = 2048;
int motSpeed = 8;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int speedPin = 5;
int dir1 = 6;
int dir2 = 7;
int mSpeed = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  
  myStepper.setSpeed(motSpeed);

  analogWrite(mSpeed, 0);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Forward();
  delay(3000);
  Right();
  delay(1000);

  Forward();
  delay(3000);
  Right();
  delay(1000);

  Forward();
  delay(3000);
  Right();
  delay(1000);

  Forward();
  delay(1000);
  Stop();
  delay(5000);
  

}

void Forward () {
digitalWrite(6, HIGH);
digitalWrite(7,LOW);
}

void Right () {
analogWrite(mSpeed, 150);
digitalWrite(6, HIGH);
digitalWrite(7,LOW);
myStepper.step(255);
}

void Left () {
analogWrite(mSpeed, 150);
digitalWrite(6, HIGH);
digitalWrite(7,LOW);
myStepper.step(-255);
}

void Stop () {
analogWrite(mSpeed, 0);
}
