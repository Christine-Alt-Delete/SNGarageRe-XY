/**
 * USS.h - Library used for using the Ultrasonic Sensor with the Arduino.
 * Library created for the private use of the G.D.I from S.N., Group 18, ENEL 400
 * Created by: Clark Harrison Dy
 * Last updated: February 21, 2020
 */


#ifndef USS_h
#define USS_h

#include "Arduino.h"
#include "USS.h"
class USS
{
  private:
    int trigPin;
    int echoPin;

  public:
    USS(int trigPin, int echoPin);
    double measureDistanceCM(bool printDist);
    double measureDistanceMM(bool printDist);
    void printDouble(double val, unsigned int precision);
};

USS::USS(int trigPin, int echoPin)
{
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
}


double USS::measureDistanceCM(bool printDist)
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  double duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  double dist = duration*0.034/2;

  if(printDist)
    printDouble(dist,100);
  return dist;
}

double USS::measureDistanceMM(bool printDist)
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  double duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  double dist = duration*0.34/2;

  if(printDist)
    printDouble(dist,100);
  return dist;
}

//Code from https://forum.arduino.cc/index.php?topic=44216.0
void USS::printDouble( double val, unsigned int precision)
{

   Serial.print(int(val));  //prints the int part
   Serial.print("."); // print the decimal point
   unsigned int frac;
   if(val >= 0)
     frac = (val - int(val)) * precision;
   else
      frac = (int(val)- val ) * precision;
   int frac1 = frac;
   while( frac1 /= 10 )
       precision /= 10;
   precision /= 10;
   while(  precision /= 10)
       Serial.print("0");

   Serial.println(frac,DEC) ;
}


#endif
