#include <LiquidCrystal.h>
#include <dht.h>

double ver = 2.0;
int dtime = 3000;

dht DHT;

const int DHT11_PIN = 8;
const int ls_pin = A0;
const int ledPin = 13;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int temp = 0;
int hum = 0;
int light = 0;



int readTemp(int DHTPIN){
  int tempC;
  int tempF;
  int chk = DHT.read11(DHTPIN);
  tempC = DHT.temperature;
  tempF = (tempC * 9/5) + 32;
  return tempF;
}

int readHum(int DHTPIN){
  return DHT.humidity;
}

int readLight(int sensor_pin){
  int sensorValue = analogRead(sensor_pin);
  return sensorValue;
}

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Welcome!");
  lcd.setCursor(0,1);
  lcd.print("Weather V");
  lcd.setCursor(9, 1);
  lcd.print(ver);
  delay(dtime);
}

void loop()
{
  temp = readTemp(DHT11_PIN);
  hum = readHum(DHT11_PIN);
  light = readLight(ls_pin);

  lcd.clear();
  lcd.print("Temp = ");
  lcd.print(temp);
  delay(dtime);
  lcd.clear();
  lcd.print("humidity = ");
  lcd.print(hum);
  delay(dtime);
  lcd.clear();
  lcd.print("light = ");
  lcd.print(light);
  delay(dtime);
}
