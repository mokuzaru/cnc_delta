int valvula = 8;
void setup() {
  Serial.begin(9600);
  pinMode(valvula, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    char estado = Serial.read();
     switch(estado){
      case 'o':
        digitalWrite(valvula, HIGH);
       break;
       case 'c':
        digitalWrite(valvula, LOW);
        break;
     }
  }
}
