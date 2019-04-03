#define trigPin1 10
#define echoPin1 9

#define trigPin2 6
#define echoPin2 5

#define buzzPin 2
#define redLED 11

int count = 0;
void setup() {

  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

}

void loop() {

  long duration1, distance1,duration2, distance2;

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;



  if (distance1 < 10) { // This is where the LED On/Off happens
   // digitalWrite(greenLED, HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(redLED,LOW);
   
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    
    count++;
    Serial.print("Here in Loop ONE and count is ");
    Serial.println(count);
    delay(500);
  } else {
  }
  if (distance2 < 10) { // This is where the LED On/Off happens
   // digitalWrite(greenLED, HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(redLED,LOW);
   
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    
    count++;
    Serial.print("Here in loop TWO and count is ");
    Serial.println(count);
    delay(500);
  } else {
  }

  delay(50);
}


