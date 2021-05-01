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
int relay = 8;
int relay2 = 9;


void setup()
{
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2,LOW);
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
    if (readdataBelt=="224"){
      Serial.println("Fall detection");
      digitalWrite(relay,HIGH);
      delay(200);
      digitalWrite(relay,LOW);}
      else{
        Serial.print("push button");
        digitalWrite(relay2,HIGH);
        delay(200);
        digitalWrite(relay2,LOW);}
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
