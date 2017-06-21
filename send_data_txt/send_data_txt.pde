/*
* ReceiveMultipleFildsBinaryToFile_P
*
* portIndex must be set to the porst conneted to the Arduino
* based on RecieveMultipleFieldsBinary, this version saves data tod file
* Press any key to stop logging and save the file
*/

import processing.serial.*;
import java.util.*;
import java.text.*;

PrintWriter output;
DateFormat fnameFormat = new SimpleDateFormat("dd-MM-yy");
DateFormat timeFormat= new SimpleDateFormat("hh:mm:ss");
String fileName;

Serial myPort;   // create object from serial class
short portIndex = 0;  //select the com port, 0 is the first port
char HEADER = 'H';

void setup()
{
  size(200,200);
  // Open whatever serial port is connected to Arduino
  String portName = Serial.list()[portIndex];
  println(Serial.list());
  println(" Connecting to -> " + Serial.list()[portIndex]);
  myPort = new Serial(this, portName, 9600);
  Date now = new Date();
  fileName = fnameFormat.format(now);
  output = createWriter(fileName + ".txt"); // save the file in the sketch folder
}

void draw()
{
  int val;
  String time;
  if (myPort.available() >=15) // wait for the entire message to arrive
  {
    if (myPort.read() >= HEADER) //is this the header
    {
      String timeString = fnameFormat.format(new Date ());
      print(timeString);
      output.print(timeString);
      // header found
      // print the six analog values
        val = readArduinoInt();
        print("  ");
        println(val);
        output.print("  ");
        output.println(val);
    }
  }
}

void keyPressed() {
  output.flush(); // writes the remaining data to the file 
  output.close(); // Finishes the file
  exit(); // Stops the program
}

int readArduinoInt() // return the integer value from bytes received on the serial port (in low, high order)
{
  int val;   // Data receied rom the serial port  
  val = myPort.read ();  // read the least significant byte
  //val = myPort.read () * 256 + val; // add the most significant byte
  return val;  
}