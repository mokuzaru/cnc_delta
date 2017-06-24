//variables de algoritmos
const float e = 24;
const float f = 86.6;
const float re = 320;
const float rf = 82;
//constantes trigonometricas
const float sqrt3 = sqrt(3.0);
const float pi = 3.141592653;
const float sin120 = sqrt3/2.0;
const float cos120 = -0.5;
const float tan60 = sqrt3;
const float sin30 = 0.5;
const float tan30 = 1/sqrt3;
//variables
float theta1;
float theta2;
float theta3;
//variables pasos
int PX;
int PY;
int PZ;
//Pines de salida a drivers
const int stepPinX = 2;
const int dirPinX  = 3;
const int stepPinY = 4;
const int dirPinY  = 5;
const int stepPinZ = 6;
const int dirPinZ  = 7;
const int valvula = 8;
const int pasos = 1600; // por cada paso equivale a 0.225 grados, por estar configurado a 1/8 "M2"
int Delaypasos = 1000;//Velocidad de los motores
void setup() {
  Serial.begin(9600);
  //while(!Serial){//Espera la conección por puerto serial este activada
  Serial.println("Iniciando");
  Serial.println("Espera un momento");
  for(int x = 2; x <  8; x++){ //Fuerza los puertos como salidas
    pinMode(x, OUTPUT);
  }
  //valor inicial de angulos
  theta1 = 0;
  theta2 = 0;
  theta3 = 0;
  Serial.println("probando motores");
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  digitalWrite(dirPinZ, HIGH);
  for (int i = 0; i < 200; i++){
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
  digitalWrite(stepPinX, HIGH);
  digitalWrite(stepPinY, HIGH);
  digitalWrite(stepPinZ, HIGH);
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
  Serial.println("Puede ingresar coordenadas");
}

void loop() {
  if(Serial.available()>0){ //pregunta si se a ingresado algo en el puerto serial
    float x = Serial.parseFloat();
    float y = Serial.parseFloat();
    float z = Serial.parseFloat();
    z -= 303;
    //if ( x*y*z != 0){ //elimina valores falsos del serial
      Serial.println(x);
      Serial.println(y);
      Serial.println(z);
      delta_calcInverse(x,y,z); // llama al algoritmo para hallar los angulos de motores
      Serial.println(theta1);
      Serial.println(theta2);
      Serial.println(theta2);
      PX = theta1 * 4.45;
      PY = theta2 * 4.45;
      PZ = theta3 * 4.45;
      Serial.println(PX);
      Serial.println(PY);
      Serial.println(PZ);
      if(PX < 0){
        digitalWrite(dirPinX, LOW);
        Serial.println("dirx negado");
      }else{
        digitalWrite(dirPinX, HIGH);
        Serial.println("dirx posi");
      }
      if(PY < 0){
        digitalWrite(dirPinY, LOW);
        Serial.println("diry neg");
      }else{
        digitalWrite(dirPinY, HIGH);
        Serial.println("diry posi");
      }
      if(PZ < 0){
        digitalWrite(dirPinZ, LOW);
        Serial.println("dirz nega");
      }else{
        digitalWrite(dirPinZ, HIGH);
        Serial.println("dirz, posi");
      }
      movMotors();
    
  }
}
void movMotors(){
  //decidir que motor se mueve más y menos para la sincronización
  int P[3] = {PX, PY, PZ};
  int S[3] = {0, 0, 0};
  int A, B;
  int suma = PX + PY + PZ;
  if (suma != 0){ // Si no da ningun paso no tiene sentido seguir
    if(P[0] > P[1] && P[0] > P [2]){
      S[2] = P[0];
      A = stepPinX;
    }else if(P[1] > P[2]){
      S[2] = P[1];
      A = stepPinY;
    }else{
      S[2] = P[2];
      A = stepPinZ;
    }
    if(P[0] < P[1] && P[0] < P[2]){
      S[0] = P[0];
      B = stepPinX;
    }else if(P[1] < P[2]){
      S[0] = P[1];
      B = stepPinY;
    }else{
      S[0] = P[2];
      B = stepPinZ;
    }
    if(P[0] != S[0] && P[0] != S[2]){
      S[1] = P[0];
    }else if(P[1] != S[0] && P[1] != S[2]){
      S[1] = P[1];
    }else{
      S[1] = P[2];
    }
  }
  //Envio de pulso al driver
  for (int i = 0; i < S[0];i++){ //menor numero de pasos
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(stepPinZ, LOW);
  }
  S[1] = S[1] - S[0];
  for (int i = 0;i < S[1]; i++){ //solo 2 motores a numero medio de pasos
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    delayMicroseconds(Delaypasos);
  }
  S[2] = S[2] - S[1];
  for(int i = 0; i < S[2]; i++){ // Solo el motor con mayor numero de pasos
    digitalWrite(A , HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(A, LOW);
    delayMicroseconds(Delaypasos);
  }
}
int delta_calcAngleYZ(float x0, float y0, float z0, float &theta) {
     float y1 = -0.5 * 0.57735 * f;
     y0 -= 0.5 * 0.57735    * e;    
     // z = a + b*y
     float a = (x0*x0 + y0*y0 + z0*z0 +rf*rf - re*re - y1*y1)/(2*z0);
     float b = (y1-y0)/z0;
     // discriminant
     float d = -(a+b*y1)*(a+b*y1)+rf*(b*b*rf+rf); 
     if (d < 0) return -1; 
     float yj = (y1 - a*b - sqrt(d))/(b*b + 1);
     float zj = a + b*yj;
     theta = 180.0*atan(-zj/(y1 - yj))/pi + ((yj>y1)?180.0:0.0);
     return 0;
   }
   
   // inverse kinematics: (x0, y0, z0) -> (theta1, theta2, theta3)
   // returned status: 0=OK, -1=non-existing position
   int delta_calcInverse(float x0, float y0, float z0) {
       theta1 = theta2 = theta3 = 0;
       int status = delta_calcAngleYZ(x0, y0, z0, theta1);
       if (status == 0) status = delta_calcAngleYZ(x0*cos120 + y0*sin120, y0*cos120-x0*sin120, z0, theta2);  // rotate coords to +120 deg
       if (status == 0) status = delta_calcAngleYZ(x0*cos120 - y0*sin120, y0*cos120+x0*sin120, z0, theta3);  // rotate coords to -120 deg
       return status;
   }
