#include "DHT.h"
#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);
int soil_moisture = 0;
float humidity = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  soil_moisture = analogRead(A0);
  
  Serial.println(humidity, 2);
  Serial.println(soil_moisture, DEC);
  delay(1000);
}
