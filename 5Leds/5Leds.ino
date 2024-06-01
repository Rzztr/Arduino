void setup(){
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  for(int i=4; i<=13; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  int switchState1=digitalRead(2);
  int switchState2=digitalRead(3);
  
  if(switchState1==HIGH){
    for(int j=3; j<=8; j++){
      digitalWrite(j,HIGH);
      delay(100);
      digitalWrite(j,LOW);
      delay(50);
    }
  }
  if(switchState2==HIGH){
    for(int j=9; j<=13; j++){
      digitalWrite(j,HIGH);
      delay(100);
      digitalWrite(j,LOW);
      delay(50);
    }
  }
}