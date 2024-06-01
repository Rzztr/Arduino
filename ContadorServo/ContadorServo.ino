#include <Servo.h>
Servo ServoUno;
Servo ServoDos;
Servo ServoTres;
int pot0 = 0;
int val0;
int pot1 = 1;
int val1;
int pot2 = 2;
int val2;
void setup()
{
ServoUno.attach(9);
ServoDos.attach(10);
ServoTres.attach(11);
}

void loop()
{
val0 = map(analogRead(pot0), 0 ,1023, 0, 180);
ServoUno.write(val0);
Serial.write("moviendo hacia: " + val0);
delay(15);

val1 = map(analogRead(pot1), 0 ,1023, 0, 180);
ServoDos.write(val1);
delay(15);

val2 = map(analogRead(pot2), 0 ,1023, 0, 180);
ServoTres.write(val2);
delay(15);

}