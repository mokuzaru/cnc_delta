#include <DeltaRobInverseKin.h>
double x;
double y;
double z;
int variable;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(x);
  Serial.print(y);
  Serial.print(z);
  if(Serial.available()>0){
    x = Serial.parseInt(); 
    y = Serial.parseInt();
    z = Serial.parseInt();
  }

}
