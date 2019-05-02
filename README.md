# IoT-RC-streaming-car

This repositry contains sketches for the Arduino Yun.

DCMotorWorks is a sketch which allows for 2 DC motors to be controlled via a L298n H bridge 

DC4MotorsWork1a is a sketch which allows for 4 DC motors to be controlled via 2 L298n H bridges 

DC4MotorsWorka is a sketch which allows for 4 DC motors to be controlled via 2 L298n H bridges and fixed the pin outputs 
so that PWM control of speeds worked.

DCMoSerialCntrl is a sketch that gave us our first manual control of direction using the keyboard to control directions 
via the serial monitor

The 2 Blynk serial sketches are a PITA and need to be fixed. Possibly need to set up and run our own Blynk server as they very rarely ever connect properly and never actually return a value from the either the button or the terminal keyboard in the app.


The two latest blynk apps are now working with the issue for the last two is the possiblity of port 80 being blocked on our home connections which is what was blocking the blynk app from connecting.

In addition the layout of the Blynk mobile app has been uploaded in a zipped file.
