const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

void setup() {
  //set up pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  clearLeds();
  //lights up LEDs going up the board
  for (int j = 7; j > 0; j--){
   //clear the LED before specified
   registerWrite(j+1, LOW);
   //light up LED
   registerWrite(j, HIGH);
   delay(70);
  };
  //as before, but with LEDs lighting up going down the board
  for (int j = 0; j < 7; j++){
    registerWrite(j-1, LOW);
   registerWrite(j, HIGH);
   delay(70);
  };
}

//function to define the sending off data
//to avoid writing these steps repeatedly
void sendData(int number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, number);
  digitalWrite(latchPin, HIGH);
}

//assigning a state to a specific LED pin (high or low)
void registerWrite(int whichPin, int whichState) {
  byte bitsToSend = 0;
  bitWrite(bitsToSend, whichPin, whichState);
  sendData(bitsToSend);


}
//clears the LED board
void clearLeds() {
  sendData(0);
}