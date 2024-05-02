#include<Servo.h>
#include<string.h>
#include<DS18B20.h>
Servo camServo;
String myString;
unsigned long startMillis;
unsigned long currentMillis;
unsigned long loopMillis;
DS18B20 temp(3);
int x_val;
int y_val;
float tempC;
float tempF;
float prev_temp;
void setup() {
  Serial.begin(9600);
  camServo.attach(2);
  startMillis = millis();
}

void loop() {
  currentMillis = millis();
  x_val = analogRead(A0);
  y_val = analogRead(A1);
  tempC = temp.getTempC();
  camServo.write(map(x_val, 0, 1024, 0, 180));
  
  if (abs(prev_temp-tempC) < 0.1) {
    digitalWrite(4, 1023);
  } else {
    digitalWrite(4, 0);
    prev_temp = tempC;
  }
    
  myString = String("C: " + String(tempC)+ " F: " + String((tempC*1.8)+32));

  Serial.println(myString);   

  
  Serial.println(((currentMillis-startMillis)-loopMillis)/1000.0);
  loopMillis = currentMillis-startMillis;
}