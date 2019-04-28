#include <WiFi.h>
#include <Bridge.h>

int LED=13;
volatile int state = LOW;
char getstr;
// Motor A connections Front Left
int enA = 9;
int in1 = 8;
int in2 = 10;
// Motor B connections Front Right
int enB = 13;
int in3 = 11;
int in4 = 12;
// Motor C connections Back Left
int enC = 3;
int in5 = 2;
int in6 = 4;
// Motor D connections Back Right
int enD = 6;
int in7 = 5;
int in8 = 7;

void _mForward()
{ 
//all forward at mid speed
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
digitalWrite(in5, HIGH);
digitalWrite(in6, LOW);
digitalWrite(in7, HIGH);
digitalWrite(in8, LOW);
analogWrite(enA, 150);
analogWrite(enB, 150);
analogWrite(enC, 150);
analogWrite(enD, 150);
Serial.println("forwards");
}
void _mBack()
{
//all backwards at mid speed
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in5, LOW);
digitalWrite(in6, HIGH);
digitalWrite(in7, LOW);
digitalWrite(in8, HIGH);
analogWrite(enA, 150);
analogWrite(enB, 150);
analogWrite(enC, 150);
analogWrite(enD, 150);
Serial.println("backwards");
}
void _mleft()
{
//spin on axis left at crawl speed 
digitalWrite(in1, LOW);  //front left motor
digitalWrite(in2, HIGH);
digitalWrite(in5, LOW);  //back left motor
digitalWrite(in6, HIGH);
digitalWrite(in3, HIGH); //front right
digitalWrite(in4, LOW);
digitalWrite(in7, HIGH); //back right
digitalWrite(in8, LOW); 
analogWrite(enA, 120);
analogWrite(enB, 120);
analogWrite(enC, 120);
analogWrite(enD, 120);
Serial.println("left");
}
void _mright()
{
//spin on axis right at crawl speed 
digitalWrite(in1, HIGH); //front left motor
digitalWrite(in2, LOW);
digitalWrite(in5, HIGH); //back left motor
digitalWrite(in6, LOW); 
digitalWrite(in3, LOW);  //front right
digitalWrite(in4, HIGH);  
digitalWrite(in7, LOW);  //back right
digitalWrite(in8, HIGH);  
analogWrite(enA, 120);
analogWrite(enB, 120);
analogWrite(enC, 120);
analogWrite(enD, 120);
Serial.println("right");
}
void _mStop()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(in5, LOW);
digitalWrite(in6, LOW);
digitalWrite(in7, LOW);
digitalWrite(in8, LOW);
Serial.println("stop");
}
void stateChange()
{
state = !state;
digitalWrite(LED, state); 
}
void setup()
{ 
pinMode(LED, OUTPUT);
Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(in5,OUTPUT);
pinMode(in6,OUTPUT);
pinMode(in7,OUTPUT);
pinMode(in8,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(enC,OUTPUT);
pinMode(enD,OUTPUT);
_mStop();
}

void loop()
{ 
getstr=Serial.read();
if(getstr=='w')
{
_mForward();
delay(10);
}
else if(getstr=='s')
{
_mBack();
delay(10);
}
else if(getstr=='a')
{
_mleft();
delay(10);
}
else if(getstr=='d')
{
_mright();
delay(10);
}
else if(getstr=='1')
{
stateChange();
}
else if(getstr=='q')
{
_mStop(); 
}
}
