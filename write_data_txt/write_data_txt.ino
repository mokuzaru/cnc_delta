/* 
* SendBinaryFields
* Sends digital and analog pin values as binary data
* File: ThermistorTemperature.pde -- look up for it in the web
*/
int Thermo = 0;
const char HEADER = 'H';  // a single character header to indicate the start of the message

void setup(){
  Serial.begin(9600);
  pinMode(Thermo, INPUT);  // set pins 2 through 13 to inputs
  digitalWrite(Thermo,HIGH); // turn on pulls-ups
}
void loop ()
{
  Serial.write(HEADER); // send the header put the pin values of hte pins into an integer
  
  int values = 0;
  int bit = 0;
  int Vo; // Integer value of voltage reading
  float R = 9870.0; // Fixed resistance in the voltage divider
  float logRt,Rt,T;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  
  Vo = analogRead(Thermo);
  Rt = R*( 1023.0 / (float)Vo - 1.0 );
  logRt = log(Rt);
  T = ( 1.0 / (c1 + c2*logRt + c3*logRt*logRt*logRt ) ) - 273.15;

  values = T;
  Serial.write(values);// sent the integer
 
 delay(3000); // send every x seconds
 }﻿
