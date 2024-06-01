#include <ESP32Servo.h>

Servo servo1;
int angulo = 90;
void setup() {
  servo1.attach(5);
}

void loop() {
  servo1.write(angulo);
  delay(100);
  angulo = 135;
  servo1.write(angulo);
}
