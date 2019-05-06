#include <BlynkSimpleYun.h>
#include <Bridge.h>
#include <Process.h>


// Auth token taken from the blynk app or sent to email address connected to account.
char auth[] = "6407689d99324ac3b82819da69276d14";


//volatile int state = LOW;

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
// pin value and pwm outputs are the varibles used by blynk
int pinValue;
int pwmOutput; // is used with a vertical slider that will allow us to control the amout of power sent to the motors which in turns allows for speed control


void _mForward()
{ 
//all forward at variable speeds
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
digitalWrite(in5, HIGH);
digitalWrite(in6, LOW);
digitalWrite(in7, HIGH);
digitalWrite(in8, LOW);
analogWrite(enA, pwmOutput);
analogWrite(enB, pwmOutput);
analogWrite(enC, pwmOutput);
analogWrite(enD, pwmOutput);
Serial.println("forwards");
}
void _mBack()
{
//all backwards at variable speeds
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in5, LOW);
digitalWrite(in6, HIGH);
digitalWrite(in7, LOW);
digitalWrite(in8, HIGH);
analogWrite(enA, pwmOutput);
analogWrite(enB, pwmOutput);
analogWrite(enC, pwmOutput);
analogWrite(enD, pwmOutput);
Serial.println("backwards");
}
void _mleft()
{
//spin on axis left at variable speeds
digitalWrite(in1, LOW);  //front left motor
digitalWrite(in2, HIGH);
digitalWrite(in5, LOW);  //back left motor
digitalWrite(in6, HIGH);
digitalWrite(in3, HIGH); //front right
digitalWrite(in4, LOW);
digitalWrite(in7, HIGH); //back right
digitalWrite(in8, LOW); 
analogWrite(enA, pwmOutput);
analogWrite(enB, pwmOutput);
analogWrite(enC, pwmOutput);
analogWrite(enD, pwmOutput);
Serial.println("left");
}
void _mright()
{
//spin on axis right at variable speeds
digitalWrite(in1, HIGH); //front left motor
digitalWrite(in2, LOW);
digitalWrite(in5, HIGH); //back left motor
digitalWrite(in6, LOW); 
digitalWrite(in3, LOW);  //front right
digitalWrite(in4, HIGH);  
digitalWrite(in7, LOW);  //back right
digitalWrite(in8, HIGH);  
analogWrite(enA, pwmOutput);
analogWrite(enB, pwmOutput);
analogWrite(enC, pwmOutput);
analogWrite(enD, pwmOutput);
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
/*void stateChange()
{
state = !state;
digitalWrite(LED, state); 
}*/

void setup()
{ 
Blynk.begin(auth); // lets blynk start up
Bridge.begin();
Serial.begin(9600);
while (!Serial);
Process p;
p.runShellCommand("/usr/bin/cam.sh");
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
BLYNK_WRITE(V20) // V20 is the number of the button pin and is the command to go forwards
{
  pinValue = param.asInt();
  
}
BLYNK_WRITE(V21) // V21 is the number of the button pin and is the command for left.
{
  pinValue = param.asInt();
 
}
BLYNK_WRITE(V22) // V22 is the number of the button pin and is the command to stop.
{
  pinValue = param.asInt();
  
}
BLYNK_WRITE(V23) // V23 is the number of the button pin and is the command for right.
{
  pinValue = param.asInt();
  
}
BLYNK_WRITE(V24) // V24 is the number of the button pin and is the command for backwards
{
  pinValue = param.asInt();

}
BLYNK_WRITE(V30) // V30 controls the pwm output which in turn controls the speed of the motors 
{
  pwmOutput = param.asInt();
}

void loop()

{
  Blynk.run();

while(pinValue != 25)
{  
if(pinValue == 1)
{
_mForward();
}
else if(pinValue == 2)
{
_mBack();
}
else if(pinValue == 3)
{
_mleft();
}
else if(pinValue == 4 )
{
_mright();
}
else if(pinValue == 5)
{
_mStop(); 
}
}
}
 



































  
