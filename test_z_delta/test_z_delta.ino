const int dirPin = 7;
const int stepPin = 6;
const int pasos ;
int Delaypasos;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);  

}

void loop() {
  digitalWrite(dirPin, HIGH);
  Delaypasos = 1000;
  for( int x = 0; x < 75; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(1000);

  digitalWrite(dirPin, LOW);
  Delaypasos = 1000;

  for (int x = 0;x < 75; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delaypasos);
  }
  delay(1000);
  }
