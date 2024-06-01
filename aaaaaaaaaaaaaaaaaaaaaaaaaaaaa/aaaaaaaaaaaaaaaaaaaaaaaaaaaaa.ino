



#include <Servo.h>
int angulo=0;
Servo servo1;
Servo servo2;


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  servo1.attach(5);
  servo2.attach(6);
}

void loop() {
  servo1.write(angulo);
  servo2.write(angulo);

  if (digitalRead(2)==HIGH){
    angulo=180;
    servo1.write(angulo);
  }
  if(digitalRead(3)==HIGH){
    angulo=90;
    servo2.write(angulo);
  }
}
