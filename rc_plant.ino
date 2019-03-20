#include "DHT.h"
#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float a = dht.readHumidity();
  Serial.println(a, 2);
  delay(1000);
}
