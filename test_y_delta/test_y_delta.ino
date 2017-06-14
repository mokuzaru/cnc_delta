const int dirPin = 7;
const int stepPin = 6;
const int pasos = 200;
int Delaypasos;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);  

}

void loop() {
  digitalWrite(dirPin, HIGH);
  Delaypasos = 10000;
  for( int x = 0; x < 20; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(3000);

  digitalWrite(dirPin, LOW);
  Delaypasos = 10000;

  for (int x = 0;x < 20; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(5000);
  }
