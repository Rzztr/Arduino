#include <Servo.h>

const int Trigger = 2; //Pin digital 2 para el Trigger del sensor
const int Echo = 3; //Pin digital 3 para el Echo del sensor
int led = 4;
int angulo=0;
Servo myServo; // Creamos un objeto Servo

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT); //pin como entrada
  pinMode(led, OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  myServo.attach(5); // Adjuntamos el servo al pin 9
  myServo.write(angulo); // Inicializamos el servo en la posición 0 grados
}

void loop() {
  static bool objeto = false;
  static int contador = 0;
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59; //escalamos el tiempo a una distancia en cm

  if (d < 15) {
    if (!objeto) {
      objeto = true;
      digitalWrite(led, HIGH);
      angulo=90;
      myServo.write(angulo); // Movemos el servo a la posición 90 grados
      contador++;
      Serial.println("objeto detectado. numero de objetos: " + String(contador)); 
    }
  } else {
    objeto = false;
    digitalWrite(led, LOW);
    angulo=0;
    myServo.write(angulo); // Volvemos el servo a la posición 0 grados
  }
  delay(100);
}