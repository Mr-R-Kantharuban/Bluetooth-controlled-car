#include <SoftwareSerial.h>
#define TX 2
#define RX 3
int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=6;//Left reverse 

int Bt_data=0;
int Arduino_data=0;
SoftwareSerial BTscreen(RX, TX);// RX, TX for Bluetooth
void setup() {
BTscreen.begin(9600); // For Bluetooth
Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor
pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT);
}
void loop()
{
  
  
  if(BTscreen.available()>0)
  {
    String Bt_data=BTscreen.readString();
    int b=(Bt_data.toInt());
    Serial.println((b));
  }
  if (b==1)
  {
    digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW);
  }
  else if (b==2)
  {
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH);
  }
  else if (b==3)
  {
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, HIGH); 
    
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, LOW); 
  }
  else if(b==4)
  {
    digitalWrite(PWMA, 450); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, HIGH); 
  }
  
}
