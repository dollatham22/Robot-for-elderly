#include <SoftwareSerial.h>

SoftwareSerial BTSerialWristban(10, 11); // RX | TX

String readdataWristban;

char mystr[5] = "100"; //String data
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

  BTSerialWristban.begin(38400);


  
}

void loop()
{ 
        while (BTSerialWristban.available()) {
        c = BTSerialWristban.read();
        readdataWristban += c;}
        
if (readdataWristban.length() > 0) {
        //Serial.println(readdataWristban);
        //Serial.println('Wristban Detection.1');
        Serial.write(mystr,5);
        readdataWristban = "";
        }




        

}
