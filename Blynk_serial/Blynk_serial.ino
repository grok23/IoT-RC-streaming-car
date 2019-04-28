#include <Blynk.h>
#include <WiFi.h>
#include <BlynkSimpleYun.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1b0a4b5373644eb5b812400696d326dc";

// enter the Wifi details in here. 
char ssid[] = "eir48596114-2.4G";
char pass[] = "turg2w5x";


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, "blynk-cloud.com", 80);
  //Blynk.begin(auth, (192,168,1,5), 8080);
}// v6 is the virtual pin number.
BLYNK_WRITE (V6) 
{
  Serial.println(param.asStr());
}

void loop()
{
  Blynk.run();
}
