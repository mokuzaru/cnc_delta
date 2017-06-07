const int stepPinX  = 2;
const int dirPinX   = 3;
const int stepPinY  = 6;
const int dirPinY   = 7;
const int stepPinZ   = 9;
const int dirPinZ    = 8;
const int pasos = 200;
int Delaypasos;

void setup() {
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinZ, OUTPUT);
  pinMode(stepPinZ, OUTPUT);  

}

void loop() {
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  digitalWrite(dirPinZ, HIGH);
  Delaypasos = 10000;
  for( int x = 0; x < 15; x++){
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(Delaypasos);
  }
  for( int x = 0; x < 25; x++){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(Delaypasos);
  }
  for( int x = 0; x < 25; x++){
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(2000);

  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);
  digitalWrite(dirPinZ, LOW);
  Delaypasos = 10000;

  for (int x = 0;x < 40; x++){
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(Delaypasos);
  }
  for (int x = 0;x < 25; x++){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(Delaypasos);
  }
  for (int x = 0;x < 25; x++){
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(2000);
  }
