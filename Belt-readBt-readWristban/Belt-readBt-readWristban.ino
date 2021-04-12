#include <SoftwareSerial.h>

SoftwareSerial BTSerialBelt(10, 11); // RX | TX

String readdataBelt;
char mystr[10];
int data;
int c ;
int x = 0 ;
int i = 0 ;
int state1 = 0;
int state2 = 0;
int count = 0;


void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  BTSerialBelt.begin(38400);
}

void loop()
{   data = Serial.readBytes(mystr,5); //Read the serial data and store in var
    Serial.println(data);
    while (BTSerialBelt.available()) {
    delay(10);
    int i = BTSerialBelt.read();
    readdataBelt += i;
  }
  if (readdataBelt.length() > 0) {
    Serial.println(readdataBelt);
    state2 = 1; 
    Serial.println(state2);
    readdataBelt = "";
  }

    if (data == 5){
      state1 = 1;
    }

    
  if (state1 == 1 && state2 == 1){
    Serial.println("Fall Detect");
    state1 = 0;
    state2 = 0;
    }


   

    
 

}
