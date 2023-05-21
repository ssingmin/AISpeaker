#include<SoftwareSerial.h>
 
const int rxPin = 4;//2
const int txPin = 5;//3

char data[2]={0,0};
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
  delay(1);
    if(Serial.available() > 0) { 
      for (int i=0;i<2;i++) { 
        while (Serial.available() == 0) {} 
        data[i] = Serial.read(); 
      }

      Toamp.print("COM+V");
      Toamp.print(data[0]);                     // 그 값을 출력                // wait for a second
      Toamp.print(data[1]); 
      toogle ^= 1; 
      digitalWrite(LED_BUILTIN, toogle);  // turn the LED on (HIGH is the voltage level)
    }
  digitalWrite(LED_BUILTIN, toogle);  // turn the LED on (HIGH is the voltage level)
}

