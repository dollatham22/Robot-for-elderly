#include <SoftwareSerial.h>

SoftwareSerial BTSerialBelt(10, 11); // RX | TX

String readdataBelt;
char mystr[10];
int c ;
int x = 0 ;
int i = 0 ;
boolean state1 = false;
boolean state2 = false;
int count = 0;


void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  BTSerialBelt.begin(38400);


  
}

void loop()
{ 
      while (BTSerialBelt.available()) {
    delay(10);
    int i = BTSerialBelt.read();
    readdataBelt += i;
  }
  if (readdataBelt.length() > 0) {
    Serial.println(readdataBelt);
    readdataBelt = "";
  }

  Serial.readBytes(mystr,5); //Read the serial data and store in var
  Serial.println(mystr); //Print data on Serial Monitor
  delay(1000);



  


          

        

    

}
