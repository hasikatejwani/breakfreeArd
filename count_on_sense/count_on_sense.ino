//buzz
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
int count = 0;



//LED
#include "SevSeg.h"
SevSeg sevseg;


void setup() {

  Serial.begin(9600);


  // buzz:
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzing

}

void loop() {
  bool flg = buzz();

}


bool buzz() {

  int duration, distance;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration / 2) / 29.1;
  
    Serial.println(distance+"cm");

   //if distance less than 0.5 meter and more than 0 (0 or less means over range)
  if (distance <= 8 && distance >= 0) {
    // Buzz
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);

    count = count + 1; //increasing the value of the count
    Serial.println(count);
    delay(1000); //delay in printing the count to avoid multiple number entries
    if (count > 9) {
      count = 0;
    } //reset the count to 0 for starting the game

    return true;

  } else {
    // Don't buzz
    digitalWrite(buzzPin, LOW);
    return false;
  }
  delay(60);

}
