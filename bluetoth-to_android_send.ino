#include <SoftwareSerial.h>

const int trig_pin = 9;
const int echo_pin = 8;

long duration;
int distance;

SoftwareSerial bt(10,11); //TX,RX


void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  bt.begin(9600);
  Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  String msg;

  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);

  //sending an ultrasonic wave for 10 microseconds;
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  //calculating duration between transmitted and received wave;
  duration = pulseIn(echo_pin,HIGH);

  //formula to get distance;
  distance= duration*0.034/2;
 

  msg = String(distance);
  msg.trim();
  Serial.println(msg);
  if(msg!=""){
    bt.println(msg);
  }
  delay(1000);
}
