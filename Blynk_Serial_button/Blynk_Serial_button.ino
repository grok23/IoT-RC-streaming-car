#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <Blynk.h>
#define BLYNK_PRINT Serial
#include <Bridge.h>
#include <BlynkSimpleYun.h>

#define BLYNK_PRINT Serial

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
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);
}
BLYNK_WRITE(V20) // V20 is the number of the button pin 
{
  int pinValue = param.asInt();
  Serial.println(pinValue);
}
void loop()
{
  Blynk.run();
}
