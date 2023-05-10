#define FORCE_SENSOR_PIN A0 // the FSR and 10K pulldown are connected to A0
#include <WiFi.h>
#include <Wire.h>
String mensaje;
const char* ssid = "FAMILIA GARNICA 2.4G";
const char* password =  "garnica1908cuellar";
int pin = 34;

WiFiServer wifiServer(5005);

WiFiClient client;

void setup() {
  Serial.begin(115200);
 
  delay(100);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
}

void loop() {


  if (client.connected()) {
      int analogReading = analogRead(pin);
      Serial.print("Force sensor reading = ");
      Serial.println(analogReading); // print the raw analog reading
      client.print(String(analogReading));
      delay(100);
      //}
  }
  else 
  {
    
    client = wifiServer.available();
    //client.stop();
    //Serial.println("Client connected");
   // c = 0;
   delay(100);
   }


  delay(100);
}
