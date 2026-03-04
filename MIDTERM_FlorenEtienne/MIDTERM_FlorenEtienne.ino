/*
  ___________________________________
 |                                   |
 | Snow (Blinking Light) Show System |
 |___________________________________|

Using 1 Button to toggle on and off the System

Using 1 Green LED for indicating "Open"
Using 1 Red LED for indicating "Close"

Using 3 White LEDs for the Mid-term's patterns

- LED 1 Pulse
- LED 2 Jolt
- LED 3 Blink

Each 

Using 1 Pot to change LEDs order (maybe?) or change its speed using millis()
*Remember to analogWrite()

Using the Touchpoint to increase pattern-LEDs brightness by mapping the brightness range
*Remember to analogWrite() 

*/

int wLedPin = 1;
int wLedPin2 = 2;
int wLedPin3 = 42;
int switchTime = 100;

int buttonPin = 6;
int rLedPin = 4;
int gLedPin = 5;

void setup() {
  pinMode(wLedPin, OUTPUT); // use digitalWrite()
  pinMode(wLedPin2, OUTPUT); // use digitalWrite()
  pinMode(wLedPin3, OUTPUT); // use digitalWrite()

  pinMode(rLedPin, OUTPUT); // use digitalWrite()
  pinMode(gLedPin, OUTPUT); // use digitalWrite()

  pinMode(buttonPin, INPUT_PULLUP); // use digitalRead()
}

void loop() {

  // pattern 1
  for(int i = 0; i < 10; i++) {
    digitalWrite(wLedPin, HIGH);
    millis(switchTime);
    digitalWrite(wLedPin, LOW);
    millis(switchTime);
    if (i > 5) {
      break;
    }
  }

  // pattern 2
  for(int i = 0; i < 10; i++) {
    digitalWrite(wLedPin, HIGH);
    millis(switchTime);
    digitalWrite(wLedPin, LOW);
    millis(switchTime);
    if (i > 5) {
      break;
    }
  }

  // pattern 3
  for(int i = 0; i < 10; i++) {
    digitalWrite(wLedPin, HIGH);
    millis(switchTime);
    digitalWrite(wLedPin, LOW);
    millis(switchTime);
    if (i > 5) {
      break;
    }
  }
}
