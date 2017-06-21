

void setup() { 
 
// Turn the Serial Protocol ON
 Serial.begin(9600);
}

void loop() {
 byte byteRead;

 /* check if data has been sent from the computer: */
 if (Serial.available()) {
 
 /* read the most recent byte */
 byteRead = Serial.read();
 //You have to subtract '0' from the read Byte to convert from text to a number.
 byteRead=byteRead-'0';
 
 //Turn off all LEDs if the byte Read = 0
 if(byteRead==0){
 //Turn off all LEDS
 Serial.println("pos inicial");
 }
 
 //Envia la coordenada.
 if(byteRead>0){
  Serial.println(byteRead);
 }
 }
 }
