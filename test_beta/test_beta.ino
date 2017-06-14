#include<Wire.h>
#include "DeltaRobInverseKin.h"

const int stepPinX = 2;
const int dirPinX  = 3;
const int stepPinY = 4;
const int dirPinY  = 5;
const int stepPinZ = 6;
const int dirPinZ  = 7;
const int pasos = 200;
int Delaypasos;

DeltaRobInverseKin DRIK(0.180, 0.445, 0.10, 0.026, 0.052, 0.09);
int initFlag = false;
int goalpos = 200.0f;
long unsigned startTime;



void setNewDRIKposArr(){
  bool endTrans = false;
  float floatArr[4];
  int indexCounter = 0;
  String inputString = "";
  DRIK.resetArr();

  while(!endTrans){
    while(indexCounter < 4 && !endTrans){
      
      if(Serial.available() > 0 && !endTrans) {
        byte byteData = Serial.read();
        if (byteData == 'e') {
          Serial.println("got all the data");
          endTrans = true;
        }else if (byteData != '\n') {
          inputString += (char)byteData;
        }else{
          floatArr[indexCounter++] = inputString.toFloat();
          Serial.println(inputString.toFloat());
          inputString = "";
        }
      }
    }
    indexCounter = 0;
    if(!endTrans){
      DRIK.setGoalCoordinates(floatArr[0], floatArr[1], floatArr[2], (int)floatArr[3]);
    }
  }
}

void setup() {
  Serial.begin(19200);
  DRIK.debugFlag = false;
  for(int x = 2; x <  8; x++){
    pinMode(x, OUTPUT);
  }


}

void loop() {
  if(Serial.available()>0){

  }
}
