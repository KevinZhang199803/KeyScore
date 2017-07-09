#define trigPin1 13
#define echoPin1 12
#define trigPin2 8
#define echoPin2 7
#define trigPin3 4
#define echoPin3 2
#define bluetooth A0
#include <stdlib.h>
#include <math.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);//define the virtual rx tx

boolean a = true;
long temp = 0;

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
  int result1, result2, result3, result_Arduino, result, i;
  float duration, distance;
  
  if (mySerial.available()){
    result_Arduino = mySerial.read();
  }
  //Serial.println(result_Arduino);
  
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
  //Serial.println(result1);
     
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
    result3= 1;
   }
  //Serial.println(result2);
  
  /* 
  digitalWrite(trigPin4, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin4, HIGH);
  //delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin4, LOW);
  duration = pulseIn(echoPin4, HIGH);
  distance = (duration/2) / 29.1;
  
   For the distance, when 10.10 or more cm means to be not pressed
   when 9.50 or less cm means to be pressed.
   
   if (distance > 9.5) {
    result4 = 0;
   }else{
    result4 = 1;
   }
   */
  
 long temp = result3*100000 + result2 * 10000 + result1 * 1000 + result_Arduino;
  Serial.println(temp);
  Serial.write(bluetooth);
  delay(1);
}
