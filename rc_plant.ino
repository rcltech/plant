#include "DHT.h"
#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);

// soil moisture sensor
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // air humidity sensor
  float a = dht.readHumidity();
  Serial.println(a, 2);

  // soil moisture calibration
  val = anologRead(A0);
  Serial.println(val);



  delay(1000);
}
