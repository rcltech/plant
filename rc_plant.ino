#include "DHT.h"
#define MYDHT DHT11
#define DHTPIN 11

DHT dht = DHT(DHTPIN,MYDHT);
int soil_moisture = 0;
float humidity = 0.0;

// soil moisture sensor
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
<<<<<<< HEAD
  humidity = dht.readHumidity();
  soil_moisture = analogRead(A0);
  
  Serial.println(humidity, 2);
  Serial.println(soil_moisture, DEC);
=======
  // air humidity sensor
  float a = dht.readHumidity();
  Serial.println(a, 2);

  // soil moisture calibration
  val = anologRead(A0);
  Serial.println(val);



>>>>>>> e680e7aecf54d98f659302e2598dbc1125552265
  delay(1000);
}
