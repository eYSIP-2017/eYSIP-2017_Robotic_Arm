#include <DynamixelSerial1.h>

unsigned char instr1[4];    //Array to store 1st four bytes of the instruction sent from PC
unsigned char instr2[40];   //Array to store the remaining bytes of the instruction
unsigned char resp1[4];     //Array to store 1st four bytes of the response sent from Dynamixel
unsigned char resp2[40];    //Array to store the remaining bytes of the response

void setup(){
Dynamixel.begin(1000000,2);  // Initialize the Serial Port 1 at 1Mbps and Control Pin is 2
Serial.begin(9600);          // Initialize Serial Port 0 for communication with PC
delay(1000);
}

void loop(){

  /*Wait till instruction is not received from PC */  
  while(!Serial.available());
  /* Read first 4 bytes of the instruction */
  Serial.readBytes(instr1,4);           
  /* instr[3] (4th byte) of instruction contains the length of the instruction packet.
  Read remaining bytes of instruction.*/
  Serial.readBytes(instr2,instr1[3]);   
  
  /* Make control pin HIGH to transmit the instruction */  
  digitalWrite(2,HIGH);
  /* Send first 4 instruction bytes to dynamixel  */
  Serial1.write(instr1,4);
  /* Send remaining instruction bytes to dynamixel  */
  Serial1.write(instr2,instr1[3]);
  /* Wait for sometime before changing the state of the control pin */
  delayMicroseconds(100);
  /* Make control pin LOW to receive the response from dynamixel */
  digitalWrite(2,LOW);

  /*Wait till response is not received from dynamixel */
  while(!Serial1.available());
  /* Read first 4 bytes of the response */
  Serial1.readBytes(resp1,4);
  /* resp1[3] (4th byte) of response contains the length of the response packet.
  Read remaining bytes of response.*/
  Serial1.readBytes(resp2,resp1[3]);

  /* Send the response back to PC through Serial Port 0 .
   Firat 4 bytes are in resp1[] and remaining bytes are in resp2[] */
  Serial.write(resp1,4);
  Serial.write(resp2,resp1[3]);

}
