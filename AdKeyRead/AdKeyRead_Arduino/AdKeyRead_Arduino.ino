#define trigPin1 13
#define echoPin1 12
#define trigPin2 11
#define echoPin2 10
#define trigPin3 9
#define echoPin3 8
#include <stdlib.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//define the virtual rx tx

boolean a = true;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  while(!Serial){
  }
  mySerial.begin(9600);
}

void loop() {
  int result1, result2, result3, result4, result5, result;
  float duration, distance;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  //delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  /*
   For the distance, when 10.10 or more cm means to be not pressed
   when 9.50 or less cm means to be pressed. 
   */
   if (distance < 13.4) {
    result1 = 0;
   }else{
    result1 = 1;
   }
   
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  //delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;
  /*
   For the distance, when 10.10 or more cm means to be not pressed
   when 9.50 or less cm means to be pressed.
   */
   if (distance < 13.4) {
    result2 = 0;
   }else{
    result2 = 1;
   }
  //Serial.println(result2);

  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  //delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  distance = (duration/2) / 29.1;
  /*
   For the distance, when 10.10 or more cm means to be not pressed
   when 9.50 or less cm means to be pressed.
   */
   if (distance < 13.4) {
    result3 = 0;
   }else{
    result3 = 1;
   }

  result = result3 * 100 + result2 * 10 + result1;
  Serial.println(result);
  mySerial.write(result);
  delay(1);
}
