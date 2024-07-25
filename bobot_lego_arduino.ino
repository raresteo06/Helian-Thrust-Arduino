#include <Servo.h>
#include <DHT.h>


#define DHTPIN 7
#define DHTTYPE DHT11

int servoPin = 9;
Servo Servo1;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  Servo1.attach(servoPin);
}

void loop() {
  delay(1000);
  int umiditate_pamant = analogRead(A5);
  Serial.print("Umiditate pamant: ");
  Serial.print(umiditate_pamant);
  Serial.print(" ");
  int value = analogRead(A3);
  Serial.print("Valoare ploaie: ");
  Serial.print(value);
  Serial.print(" ");
  if(value < 300){
    digitalWrite(4, HIGH);
    Serial.print("Ploua tare, retragere ");
  }
  else{
    digitalWrite(4, LOW);
  }
  float umiditate = dht.readHumidity();
  float tempC = dht.readTemperature();
  Serial.print("Umiditate(%): ");
  Serial.print(umiditate);
  Serial.print(" ");
  Serial.print("Temperatura(C):");
  Serial.print(tempC);
  Serial.print(" ");
  int mq_value = analogRead(A0);
  Serial.print("Calitatea aerului: ");
  Serial.println(mq_value);
  Serial.print(" ");
  if(tempC<30 && tempC>20 && umiditate<80 && umiditate>5 && mq_value<600)
    Servo1.write(180);
  else
    Servo1.write(90);
  if(value<400){
    Servo1.write(0);
  }
}
