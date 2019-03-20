#include "DHT.h"
#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);
int soil_moisture = 0;
float humidity = 0.0;

// soil moisture sensor
// set constant values for dry and wet at 500 and 300 respectively

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
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
