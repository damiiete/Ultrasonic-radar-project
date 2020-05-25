#include<Servo.h>

int trigPin=2;
int echoPin=3;
int Red_led = 10;
int Amber_led = 11;
long duration;
int distance;
Servo servo;

void setup()
{
  //initialising functions of pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Red_led, OUTPUT);
  pinMode(Amber_led, OUTPUT);
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{
  for(int i=0;i<=180;i++)
  {
    servo.write(i);
    delay(50);
    distance=calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for(int i=180;i>0;i--)
  {
    servo.write(i);
    delay(50);
    distance=calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
  
  //obstacle detection
  if (distance <= 40) //obstacle detected
  {
    digitalWrite(Red_led, HIGH);
    digitalWrite(Amber_led, LOW);
  }
  else //no obstacle
   {
     digitalWrite(Red_led, LOW);
     digitalWrite(Amber_led, HIGH);
  }
  return distance;
}  
