 int redPins[4] = {2, 5, 8, 11};
 int yellowPins[4] = {3, 6, 9, 12};
 int greenPins[4] = {4, 7, 10, 13};

int greenTime = 6000; // 6 segundos para verde
int yellowTime = 3000; // 3 segundos para amarillo

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(greenPins[i], HIGH);
    digitalWrite(redPins[i], LOW);
    
    for (int j = 0; j < 4; j++) {
      if (j != i) {
        digitalWrite(redPins[j], HIGH);
        digitalWrite(yellowPins[j], LOW);
        digitalWrite(greenPins[j], LOW);
      }
    }
    
    delay(greenTime);
    
    digitalWrite(greenPins[i], LOW);
    digitalWrite(yellowPins[i], HIGH);
    delay(yellowTime);
    
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(redPins[i], HIGH);
  }
}