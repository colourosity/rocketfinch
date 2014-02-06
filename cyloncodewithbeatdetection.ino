#include <FrequencyTimer2.h>

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

byte ledState[] = {0,0,0,0,0,0,0,0};
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
   Serial.begin(9600);
   Serial.print("hello");
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);

   //blinkAll_2Bytes(3,500); 
 }

void loop() {
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    
    if (ledState[0] == 0)
      allOn();
    else
      allOff();

  }

  //blinkAll_2Bytes(3,500);
  //lights up LEDs going up the board
  /*for (int j = 7; j > 0; j--){
   //clear the LED before specified
   ledState[j+1] = 0;
   //light up LED
   ledState[j] = 128;
   sendData(j);
   delay(70);
  };
  //as before, but with LEDs lighting up going down the board
  for (int j = 0; j < 7; j++){
    ledState[j-1] = 0;
    ledState[j] = 128;
    sendData(j);
   delay(70);
  };*/
}

void allOff() {
  sendData(0);
  ledState[0] = 0;
//  for (int i = 0; i < 8; i++){
//    ledState[i] = 0;
//  }
}
void allOn() {
  sendData(255);
  ledState[0] = 1;
//  for (int i = 0; i < 8; i++){
//    ledState[i] = 128;
//  }
}

void sendData(int number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, number);
  digitalWrite(latchPin, HIGH);
}
 
void display() {
  //Serial.write("display");
  for (int i = 0; i < 128; i++) {
    //Serial.write("for");
    byte data = B00000000;
    for (int a = 0; a < 8; a++) {
      if (ledState[a] > i) bitWrite(data, a, 1);
    }
    sendData(data);
  }
} 

/*void blinkAll_2Bytes(int n, int d) {
  //send
  //delay(200);
  for (int x = 0; x < n; x++) {
    allOn();
    delay(d);
    allOff();
    delay(d);
  }
}*/
  
