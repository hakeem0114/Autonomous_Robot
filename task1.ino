#include <Stepper.h>

int stepsPerRevolution = 2048;
int motSpeed = 7;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int speedPin = 5;
int dir1 = 6;
int dir2 = 7;
int mSpeed = 200;

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  myStepper.setSpeed(motSpeed);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  //go forward
  if (mapX > 450 && mapY < 50)
  {
  
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW);
  delay(500);
  }
   
    //go backwards
    if (mapX < -450 && mapY < 50)
  {
  analogWrite(speedPin, 255);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH);
  delay(500);
  }

      //turn left
    if ( 50 > mapX && mapY > 450)
  {
  myStepper.step(-250);
  delay(500);
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW);
  delay(500);
  }
      //turn right
      if ( 50 > mapX && -50 > mapY && mapY < -350)
  {
  myStepper.step(250);
  delay(500);
  analogWrite(speedPin, 255);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW); 
  
  }

  //stop
  if (50 > mapX && mapY < 50)
  {  
    analogWrite(speedPin, 0);
    digitalWrite(6, LOW);
    digitalWrite(7,LOW);
    delay(500);

  }
  
}
