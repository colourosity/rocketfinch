const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  displayState();
}

void sendData(int number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, number);
  digitalWrite(latchPin, HIGH);
}

byte ledState[] = {1,2,4,8,16,32,64,128};

void displayState() {
  for (int i = 0; i < 128; i++) {
    byte data = B00000000;
    for (int a = 0; a < 8; a++) {
      if (ledState[a] > i)
         bitWrite(data, a, 1);
    }
    sendData(data);
  }
}
