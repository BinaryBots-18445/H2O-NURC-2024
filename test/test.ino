#include<Servo.h>
Servo camServo;
int x_val;
int y_val;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  x_val = analogRead(A0);
  y_val = analogRead(A1);
  // Serial.print(x_val);
  // Serial.print(",");
  // Serial.println(y_val);
  Serial.println(map(x_val,0,1024,0,180));
  camServo.write(map(x_val, 0, 1024, 0, 180));
}