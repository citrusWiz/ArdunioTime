#include <dht.h>

dht DHT;

int DHT11_PIN = 8;
int tempC;
int tempF;

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  tempC = DHT.temperature;
  tempF = (tempC * 9/5) + 32;
  Serial.print("Temperature = ");
  Serial.println(tempF);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
