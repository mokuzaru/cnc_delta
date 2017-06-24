//Pines de salida a drivers
const int stepPinX = 2;
const int dirPinX  = 3;
const int stepPinY = 4;
const int dirPinY  = 5;
const int stepPinZ = 6;
const int dirPinZ  = 7;
const int valvula = 8;
const int pasos = 1600; // por cada paso equivale a 0.225 grados, por estar configurado a 1/8 "M2"
int Delaypasos = 5000;//Velocidad de los motores
const int z = 25;
void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando");
  Serial.println("Espera un momento");
  for (int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }
  Serial.println("probando motores");
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  digitalWrite(dirPinZ, HIGH);
  for (int i = 0; i < 100; i++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX,LOW);
    digitalWrite(stepPinY,LOW);
    digitalWrite(stepPinZ,LOW);
    delayMicroseconds(Delaypasos);
  }
  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);
  digitalWrite(dirPinZ, LOW);
  for (int i = 0; i < 60; i++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX,LOW);
    digitalWrite(stepPinY,LOW);
    digitalWrite(stepPinZ,LOW);
    delayMicroseconds(Delaypasos);
  }
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  digitalWrite(dirPinZ, HIGH);
  for (int i = 0; i < 100; i++){
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX,LOW);
    digitalWrite(stepPinY,LOW);
    digitalWrite(stepPinZ,LOW);
    delayMicroseconds(Delaypasos);
  }
  Serial.println("LISTO!");
}

void loop() {
  if(Serial.available() > 0){
    if (Serial.read() == 'y'){
      //mov a x=120 y=0 z=0
      digitalWrite(dirPinX,HIGH);
      digitalWrite(dirPinY,LOW);
      digitalWrite(dirPinZ,HIGH);
      for(int i = 0; i < 35; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 36; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinZ, LOW);
        delayMicroseconds(Delaypasos);
      }
      for(int i = 0; i < 97; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinZ , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinZ , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(500);
      //sube y baja
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      //Mov para regresar al inicio
      digitalWrite(dirPinX,LOW);
      digitalWrite(dirPinY,HIGH);
      digitalWrite(dirPinZ,LOW);
      for(int i = 0; i < 35; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 36; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinZ, LOW);
        delayMicroseconds(Delaypasos);
      }
      for(int i = 0; i < 97; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinZ , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinZ , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(1000);
      //mov a x = -120 y = 0 Z = 0
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < 35; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 36; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        delayMicroseconds(Delaypasos);
      }
      for(int i = 0; i < 97; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinY , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinY , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(500);
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      //regresar a inicio
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < 35; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 36; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        delayMicroseconds(Delaypasos);
      }
      for(int i = 0; i < 97; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinY , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinY , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(1000);
      //Mover a x = 110 y = 0 z = 0
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < 2; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for(int i = 0; i < 159; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinX , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(500);
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      //regresar a inicio
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < 2; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for(int i = 0; i < 159; i++){ // Solo el motor con mayor numero de pasos
        digitalWrite(stepPinX , HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX , LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(1000);
      //mover a x = -110 y = 0 z = 0
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < 52; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 61; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
        delayMicroseconds(Delaypasos);
      }
      delay(500);
      digitalWrite(dirPinX, LOW);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, HIGH);
      digitalWrite(dirPinZ, HIGH);
      for(int i = 0; i < z; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      delay(500);
      //regresar a inicio
      digitalWrite(dirPinX, HIGH);
      digitalWrite(dirPinY, LOW);
      digitalWrite(dirPinZ, LOW);
      for(int i = 0; i < 52; i++){
        digitalWrite(stepPinX, HIGH);
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinX, LOW);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
      }
      for (int i = 0;i < 61; i++){ //solo 2 motores a numero medio de pasos
        digitalWrite(stepPinY, HIGH);
        digitalWrite(stepPinZ, HIGH);
        delayMicroseconds(Delaypasos);
        digitalWrite(stepPinY, LOW);
        digitalWrite(stepPinZ, LOW);
        delayMicroseconds(Delaypasos);
      }
      Serial.println("Otra vez? :3");
  }
 }
}

