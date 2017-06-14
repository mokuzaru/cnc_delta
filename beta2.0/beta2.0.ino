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
const int pasos = 1600;
int Delaypasos = 2000;
void setup() {
  Serial.begin(9600);
  for(int x = 2; x <  8; x++){
    pinMode(x, OUTPUT);
  }
  //valor inicial de angulos
  theta1 = 0;
  theta2 = 0;
  theta3 = 0;
}

void loop() {
  while(Serial.available()>0){
    delay(100);
    int x = Serial.parseInt();
    int y = Serial.parseInt();
    int z1 = Serial.parseInt();
    int z = z1 - 303.95;
    delta_calcInverse(x,y,z);
    Serial.println(theta1);
    Serial.println(theta2);
    Serial.println(theta3);
    PX = theta1 * 5 / 9;
    PY = theta2 * 5 / 9;
    PZ = theta3 * 5 / 9;
    Serial.println(PX);
    Serial.println(PY);
    Serial.println(PZ);
    delay(1000);
    despacito();
  }
}
void despacito(){
  if (PX <0){
  digitalWrite(dirPinX, LOW);
  PX = abs(PX) ;
  Serial.println(PX);
  }else{
    digitalWrite(dirPinX, HIGH);
  }
  if (PY > 0){
    digitalWrite(dirPinY, HIGH);
  }else{
    digitalWrite(dirPinY,LOW);
    PY = abs(PY);
    Serial.println(PY);
  }
  if (PZ <0){
    digitalWrite(dirPinZ, LOW);
    PZ = abs(PZ);
    Serial.println(PZ);
  }else{
    digitalWrite(dirPinZ, HIGH);
  }
  for (int M = 0; M < 11 ; M++){
  for(int k = 0;k < PX; k++){
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinX,LOW);
    delayMicroseconds(Delaypasos); 
  }
  }
  for(int k = 0;k < PY; k++){
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinY,LOW);
    delayMicroseconds(Delaypasos); 
  }
  for(int k = 0;k < PZ; k++){
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Delaypasos);
    digitalWrite(stepPinZ,LOW);
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
