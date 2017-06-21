const int stepPinX =2;
const int dirPinX = 3;
const int stepPinY = 4;
const int dirPinY = 5;
const int stepPinZ = 6;
const int dirPinZ = 7;
const int valvula = 8;
const int pasos = 200;
int Delaypasos;

void setup() {
  for (int x = 0;x < 8; x++){
    pinMode(x, OUTPUT);
  }
}

void loop() {
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  digitalWrite(dirPinZ, HIGH);
  Delaypasos = 2000;
  for( int x = 0; x < 45; x++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(2000);

  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);
  digitalWrite(dirPinZ, LOW);

  for (int x = 0;x < 25; x++){
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(Delaypasos);
  }
  digitalWrite(valvula, HIGH);
  delay(4000);
  digitalWrite(valvula,LOW);
}
