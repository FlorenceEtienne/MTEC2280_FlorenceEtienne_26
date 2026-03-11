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

//checking sounds and white lights
const int numReads = 16;
int reading[numReads];
int count = 0;

const int piezoPin = 41;

bool intro = 0;
int octave = 2;

const int wLedPin = 1;
const int wLedPin2 = 2;
const int wLedPin3 = 42;

//checking on and off system
const int buttonPin = 6;
int buttonState = 0;
int lastButtonState = 0;
int toggle = 0;
int fallToggle = 0;

const int rLedPin = 4;
const int gLedPin = 5;

void setup() {
  pinMode(wLedPin, OUTPUT); // use digitalWrite()
  pinMode(wLedPin2, OUTPUT); // use digitalWrite()
  pinMode(wLedPin3, OUTPUT); // use digitalWrite()

  pinMode(rLedPin, OUTPUT); // use digitalWrite()
  pinMode(gLedPin, OUTPUT); // use digitalWrite()

  pinMode(buttonPin, INPUT_PULLUP); // use digitalRead()

  analogReadResolution(11);

  Serial.begin(115200);
}

void loop() {
  reading[count] = analogRead(potPin);  //store current ADC read in array at index of count
  count++;

  if (adcRead < 1023) //if adcRead is between 0-1023
  {
    digitalWrite(wLedPin, HIGH);
  }
  else if (adcRead > 1023 && adcRead < 2049) //if adcRead is between 1023-2049
  {
    digitalWrite(wLedPin, LOW);
    digitalWrite(wLedPin2, HIGH);
  }
  else if (adcRead > 2049 && adcRead < 3072) //if adcRead is between 2049-3072
  {
    digitalWrite(wLedPin2, LOW);
    digitalWrite(wLedPin3, HIGH);
  }
  else if (adcRead > 3072)  //if adcRead is between 3072-4095
  {
    digitalWrite(wLedPin3, LOW);
    digitalWrite(wLedPin, HIGH);
  }

  Serial.printf("ADC = %i \t LED 1 = %i \t LED 2 = %i \t LED 3 = %i \n", adcRead, wLedPin, wLedPin2, wLedPin3);
  // TestingPins();
}

void TestingPins() {
  buttonState = !digitalRead(buttonPin);

  if (buttonState)
  {
    //main melody
    tone(piezoPin, 90 * octave, 500);
    tone(piezoPin, 100 * octave, 500);
    tone(piezoPin, 110 * octave, 500);

    tone(piezoPin, 110 * octave, 500);
    tone(piezoPin, 220 * octave, 1000);
    tone(piezoPin, 110 * octave, 200);
    tone(piezoPin, 440 * octave, 1000);
    tone(piezoPin, 660 * octave, 200);
    tone(piezoPin, 220 * octave, 200);

    tone(piezoPin, 110 * octave, 500);
    tone(piezoPin, 100 * octave, 500);
    tone(piezoPin, 90 * octave, 500);
    digitalWrite(gLedPin, HIGH);
    digitalWrite(rLedPin, LOW);
  }

  if (!buttonState)
  {
    noTone(piezoPin);
    digitalWrite(gLedPin, LOW);
    digitalWrite(rLedPin, HIGH);
  }

  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);

  // LOW lets LOW amount voltage through while HIGH gets resisted

  // digitalWrite(rLedPin, LOW);
  // digitalWrite(gLedPin, LOW);

  // // pattern 1
  // for(int i = 0; i < 10; i++) {
  //   if (i > 5) {
  //     break;
  //   }

  //   delay(500);
  //   digitalWrite(wLedPin, HIGH);
  //   delay(500);
  //   digitalWrite(wLedPin, LOW);
  // }

  // // pattern 2
  // for(int i = 0; i < 10; i++) {
  //   if (i > 5) {
  //     break;
  //   }

  //   delay(500);
  //   digitalWrite(wLedPin2, HIGH);
  //   delay(500);
  //   digitalWrite(wLedPin2, LOW);
  // }

  // // pattern 3
  // for(int i = 0; i < 10; i++) {
  //   if (i > 5) {
  //     break;
  //   }

  //   delay(500);
  //   digitalWrite(wLedPin3, HIGH);
  //   delay(500);
  //   digitalWrite(wLedPin3, LOW);
  // }
}
