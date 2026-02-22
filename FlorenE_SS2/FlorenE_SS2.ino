/*
LEDs button control

Button 1 use for indicating a button is off/on. if it is false, turn off; of it is true, turn on.
Red (off) and Green (on)

Button 2 use to switch between patterns.
White (Pin 1), Green (Pin 2), Red (Pin 3), Blue (Pin 4)
*/

// constant integer variable assign for the first button pin. used as a toggle button.

const int buttonPin = 1;

bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool offToggle = 0;

// const int buttonPin2 = 4; constant integer variable assign for the button pin. used as a push button.

// constant variable assign for a leds pin

const int ledPin = 42; // for green (on)
const int ledPin2 = 41; // for red (off)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  // pinMode(buttonPin2, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {
  buttonState = !digitalRead(buttonPin); // does NOT read the input button pin with voltage first 
  delay(20);

  // Rising Edge

  // detects the PRESS of a button;
  if (buttonState && !lastButtonState) { // if the button went from LOW to HIGH...
    toggle = !toggle; // used flipped the bool using NOT logic
  }

  // Falling Edge

  // detects the RELEASE of a button;
  if (!buttonState && lastButtonState) {
    offToggle = !offToggle;
  } 

  lastButtonState = buttonState;

  digitalWrite(ledPin, toggle);
  digitalWrite(ledPin2, offToggle);

  Serial.printf("Button = %i ; Toggle = %i ; Falling = %i \n", buttonState, toggle, offToggle);
}