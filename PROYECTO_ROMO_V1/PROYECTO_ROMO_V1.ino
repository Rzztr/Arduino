uff #include <BluetoothSerial.h>
#include <ESP32Servo.h>
const char *pin = "1234"; // Nomas si necesitas conectarte sin la app

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

Servo servo1;
Servo servo2;
int angulo=0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  servo1.attach(18);
  servo2.attach(19);
}
void loop() {
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.write(receivedChar); // Mostrar en el puerto serie para debug
    switch (receivedChar) {
      case 'a':
        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        break;
      case 'b':
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4, LOW);
        break;
      case 'c':
        digitalWrite(5, HIGH);
        delay(200);
        digitalWrite(5, LOW);
        break;
      case 'd':
        servo1.write(90); // Angulo para servo1
        delay(200);
        break;
      case 'e':
        servo2.write(135); // Angulo para servo2
        delay(200);
        break;
      default:
        break;
    }
  }

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  delay(20);
}


