#include "Timer.h"
Timer t;

int ping = 7;
long duration;
long proximityReading;


void motion_sensor(); // function header
void read_sensor(); // function header

void setup() {
Serial.begin(9600);
t.every(300, motion_sensor);
t.every(100, read_sensor);
}


void loop() {
t.update();
} 
void read_sensor(){
int line_sensor = analogRead(A0);
Serial.println(line_sensor);
}
void motion_sensor() { 
  
  pinMode(ping,OUTPUT);
  digitalWrite(ping,LOW);
  delayMicroseconds (2);
  digitalWrite(ping,HIGH);
  delayMicroseconds (5);
  digitalWrite(ping,LOW);
  digitalWrite(ping,LOW);
  pinMode(ping,INPUT);
  duration = pulseIn(ping,HIGH);
  proximityReading = duration/58.138;
if(proximityReading <400){
    //Serial.println(proximityReading);
  }
}
