#include <SPI.h>
#include <LoRa.h>
#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 7     
#define DHTTYPE DHT11   
const int trigPin = 9;
const int echoPin = 10;
#define irsensor 5

float speedOfSound,duration, distance;

 
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial ss(4, 3);
int hum;
float temp; //Stores temperature value

int delay1() {
  //unsigned int long k;
  int i, j;
  unsigned int count = 0;
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      if (digitalRead(irsensor)) {
        count++;
        while (digitalRead(irsensor));
      }
    }
  }
  return count;
}
 
void setup() {    
  Serial.begin(9600);
  dht.begin();
  ss.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irsensor, INPUT);
  while (!Serial);
  Serial.println("LoRa Sender");
 
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() 
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  speedOfSound = 331.4 + (0.6 * temp) + (0.0124 * hum);
  distance = (duration*speedOfSound)/2;
  unsigned int time = 0, RPM = 0;
  int blades;
  byte gpsData;
  time = delay1();
  LoRa.beginPacket();
  RPM = (time * 12) / blades;
  while (ss.available() > 0){
    // get the byte data from the GPS
    gpsData = ss.read(); 
  }
 
  Serial.println("Sending packet: ");
 
  // send packet
  LoRa.beginPacket();
  LoRa.print("DHT sensor")
  LoRa.print("Humidity: ");
  LoRa.print(hum);
  LoRa.print("%");
  LoRa.print(" Temperature:");
  LoRa.print(temp);
  LoRa.print("C");
  LoRa.print("HCSR04 sensor")
  LoRa.print("Distance: ");
  LoRa.print(distance);
  LoRa.print("IR Sensor")
  LoRa.print(RPM);
  LoRa.print("GPS")
  LoRa.print(gpsData);

  
  
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%");
  Serial.print(" Temperature:");
  Serial.print(temp);
  Serial.println("C");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(RPM);
  Serial.write(gpsData);


 
  LoRa.endPacket();
  delay(1000);
}