#include "USS.h"

USS ultraSensor(9,10);
int LED = 13;
void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
}

void loop() 
{
  Serial.print("Distance in mm is: ");
  double distMM = ultraSensor.measureDistanceMM(true); //measures( displays distif true)
  if(distMM <= 120)
    digitalWrite(LED,HIGH);
  else
    digitalWrite(LED,LOW);

    
  delay(10);
}
