const int stepPinX  = 2;
const int dirPinX   = 3;
const int stepPinY  = 4;
const int dirPinY   = 5;
const int stepPinZ  = 6;
const int dirPinZ   = 7;
//const int pasos = 200;
const int pasos = 1600;
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
  Delaypasos = 2000;
  for( int x = 0; x < 200; x++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }
  /*
  for( int x = 0; x < 15; x++){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(Delaypasos);
  }
  for( int x = 0; x < 15; x++){
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }*/
  delay(2000);

  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);
  digitalWrite(dirPinZ, LOW );
  //Delaypasos = 5000;

  for (int x = 0;x < 200; x++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }/*
  for (int x = 0;x < 15; x++){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(Delaypasos);
  }
  for (int x = 0;x < 15; x++){
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Delaypasos);
  }*/
  delay(2000);
  }
