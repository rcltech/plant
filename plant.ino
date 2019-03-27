#include "DHT.h"

#include <WiFiEsp.h>
#include <SoftwareSerial.h>

#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);
SoftwareSerial Serial1(6,7); //RX, TX

float humidity = 0.0;
int soil_moisture = 0;
int status = WL_IDLE_STATUS;

// soil moisture sensor
// set constant values for dry and wet at 500 and 300 respectively

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();


  //Serial for ESP8266
  Serial1.begin(9600);
  WiFi.init(&Serial1);  
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect");
    // Connect to WPA/WPA2 network
    status = WiFi.begin("ugoel", "ugoel867");
  }
  Serial.print("Connected");
  printWifiStatus();
}

void loop() {
  // read sensors
  humidity = dht.readHumidity();
  soil_moisture = analogRead(A0);

  // print outputs
  Serial.println(humidity, 2);
  Serial.println(soil_moisture, DEC);

  // write algorithm to process soil moisture data

  // output relative soil moisture as percentage

  delay(1000);
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
