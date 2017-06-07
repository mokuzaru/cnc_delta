const int dirPin = 3;
const int stepPin = 2;
const int pasos = 200;
int Delaypasos;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);  

}

void loop() {
  digitalWrite(dirPin, HIGH);
  Delaypasos = 10000;
  for( int x = 0; x < 40; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(2000);

  digitalWrite(dirPin, LOW);
  Delaypasos = 10000;

  for (int x = 0;x < 40; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(5000);
  }
