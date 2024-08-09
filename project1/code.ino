#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

int ledBarGraph[] = {3,4,5,6,7,8,9,10,11,12}; 
#define RGBLEDRED 13 //unlucky sicnce i have the 10 pin ledbargraph i can't use all the rgb led pins so i'll meke it go full red when is too hot

DHT sensor(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("Debug console:");
  sensor.begin();

  for(int i = 0; i<10; i++){
    pinMode(ledBarGraph[i],OUTPUT);
    digitalWrite(ledBarGraph[i],HIGH);
  }

  pinMode(RGBLEDRED,OUTPUT);
  digitalWrite(RGBLEDRED,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float h = sensor.readHumidity();
  float t = sensor.readTemperature();
  for(int i = 0; i<10; i++){
    digitalWrite(ledBarGraph[i],LOW);
  }
  for(int i = 0 ; i<(int)h/10; i++){
    digitalWrite(ledBarGraph[i],HIGH);
  }

  
  digitalWrite(RGBLEDRED,LOW);
  if(t>28){ //above 28°C is considered hot (i would put yellow from 26-28 green from 20-26 blue-green from 15 to 20 and blue under)
    digitalWrite(RGBLEDRED,HIGH);
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
}
