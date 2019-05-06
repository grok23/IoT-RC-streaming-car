# IoT-RC-streaming-car

This repositry contains sketches for the Arduino Yun.

DCMotorWorks is a sketch which allows for 2 DC motors to be controlled via a L298n H bridge 

DC4MotorsWork1a is a sketch which allows for 4 DC motors to be controlled via 2 L298n H bridges 

DC4MotorsWorka is a sketch which allows for 4 DC motors to be controlled via 2 L298n H bridges and fixed the pin outputs 
so that PWM control of speeds worked.

DCMoSerialCntrl is a sketch that gave us our first manual control of direction using the keyboard to control directions 
via the serial monitor

The 2 Blynk serial sketches work, (but you must make sure to enable port forwarding of ports 8441, 8442, and 8443 for them to work properly) . Possibly need to set up and run our own Blynk server as they very rarely ever connect properly and never actually return a value from the either the button or the terminal keyboard in the app (port forwarding solved this).


The two latest blynk apps are now working with the issue for the last two is the possiblity of ports 8441, 8442, and 8443 being blocked on our home connections which is what was blocking the blynk app from connecting.

In addition the layout of the Blynk mobile app has been uploaded in a zipped file.

automated webcam streaming by adding a shellscript to the Yun and then running it from within the control .ino files
to do this use putty and navigate to the /usr/bin/ folder and create a shellscript file with:     touch cam.sh

then use the vim editor to edit in the camera control line:   vi cam.sh 

and add the line     mjpg_streamer -i "input_uvc.so -d /dev/video0 -r 640x480 -f 15" -o "output_http.so -p 8080" & http://brumbrum.local:8080/   

then close and save the file
after that we want to make the file executable so we use:   chmod +x cam.sh

once that has been done it's a matter of editing the existing sketches for control of the vehicle to include the Process.h library and then running the shellscript from the setup section of the sketch