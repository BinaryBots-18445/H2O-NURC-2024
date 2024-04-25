#include<Servo.h>
#include<DS18B20.h>
Servo camServo;
DS18B20 temp(3);
int x_val;
int y_val;
float prev_temp;
void setup() {
  Serial.begin(115200);
  camServo.attach(2);
}

void loop() {
  x_val = analogRead(A0);
  y_val = analogRead(A1);
  // Serial.print(x_val);
  // Serial.print(",");
  // Serial.println(y_val);
  //Serial.println(map(x_val,0,1024,0,180));
  camServo.write(map(x_val, 0, 1024, 0, 180));
  // if (analogRead(A1) < 400) {
  //   digitalWrite(3, 1023);
  // } else {
  //   digitalWrite(3, 0);
  // }
  while (temp.selectNext()) {
    if (abs(prev_temp-temp.getTempC()) < 0.1) {
      Serial.print("WE HAVE OURSELVES A STABLE TEMPERATURE!! ");
        

    } else {
      Serial.print("This temperature is not stable... 🫨 ");
      prev_temp = temp.getTempC();
    }
    Serial.print("C: ");
    Serial.print(temp.getTempC());
    Serial.print(" F: ");
    Serial.println(temp.getTempF()); 
  }

}