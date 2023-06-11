#include<SoftwareSerial.h>

#define SPEAKERID '0'
#define RX_BUFLEN 4
const int rxPin = 4;//2
const int txPin = 5;//3

char data[RX_BUFLEN]={0,0,0,0};
char send_data[RX_BUFLEN]={0,0,0,0};
char toogle = 0;
SoftwareSerial Toamp(rxPin, txPin);
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Toamp.begin(9600);

}

// the loop function runs over and over again forever
void loop() {
  //toogle ^= 1; 
  delay(10);
    if(Serial.available() > 0) { 
      for (int i=0;i<RX_BUFLEN;i++) { 
        while (Serial.available() == 0) {} 
        data[i] = Serial.read();
        
      }
    }
    for(int i=0;i<RX_BUFLEN;i++)
    {
      if(data[i]=='s'){
        send_data[0]=data[i%4];i++;
        send_data[1]=data[i%4];i++;
        send_data[2]=data[i%4];i++;
        send_data[3]=data[i%4];
        break;
      }
    }
      
      if((send_data[0]=='s')&&(send_data[1]==SPEAKERID)){
        //if(send_data[1]==SPEAKERID){
        Toamp.print("COM+V");
        Toamp.print(send_data[2]);                     // 그 값을 출력                // wait for a second
        Toamp.print(send_data[3]); 
        toogle ^= 1; 
      }
  digitalWrite(LED_BUILTIN, toogle);  // turn the LED on (HIGH is the voltage level)
}
