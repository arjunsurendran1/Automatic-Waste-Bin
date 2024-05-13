#include <Servo.h>

int trigPin = 8;      // trig pin of HC-SR04

int echoPin = 12;     // Echo pin of HC-SR04


long duration, distance;
Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position


void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);         // set trig pin as output

  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}


void loop() {


  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);   

  digitalWrite(trigPin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance
    Serial.println("distance1");

  Serial.println(distance);

  delay(10);

if (distance<=10){
      myservo.write(180);              

  }
else{
        myservo.write(0);              

  }
}
