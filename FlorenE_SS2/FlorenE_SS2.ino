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
bool toggle = 1;
bool offToggle = 0;

// constant integer variable assign for control leds' pins

const int ledPin = 42; // for green (on)
const int ledPin2 = 41; // for red (off)

// constant integer variable assign for the second button pin. used as a push button.

const int buttonPin2 = 4; 

bool button2State = 0;
bool lastButton2State = 0;
bool toggle2 = 1;
bool offToggle2 = 0;

int counter = 0;
int maxCount = 5;

const int ledPin3 = 5; // White
const int ledPin4 = 6; // Green
const int ledPin5 = 40; // Blue
const int ledPin6 = 39; // Red

int ms;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);

  pinMode(buttonPin2, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {
  buttonState = !digitalRead(buttonPin); // does NOT read the input button pin with voltage first 
  delay(20);
  bool button2State = !digitalRead(buttonPin2);
  delay(20);

  // Rising Edge

  // detects the PRESS of a button;
  if (buttonState && !lastButtonState) { // if the button went from LOW to HIGH...

    toggle = !toggle; // used flipped the bool using NOT logic

    if (button2State && !lastButton2State) {
      toggle2 = !toggle2;
      counter++;
    }

    if (counter == 0) {
      checkLEDs();
    }

    if (counter == 1) {
      allBlinkLEDs();
    }

    if (counter == 2) {
      doneCheckedLEDs();
    }

    if (counter == 3) {
      siren1();
    }

    if (counter == 4) {
      siren2();
    }

    if (counter == 5) {
      floral();
    }

    if (counter > maxCount) {
      counter = 0;
      offToggle2 = !offToggle2;
    }
  }

  // Falling Edge

  // detects the RELEASE of a button;
  if (!buttonState && lastButtonState) {
    offToggle = !offToggle;
  } 

  lastButtonState = buttonState;
  lastButton2State = button2State;

  // Toggle parameters for the LEDs' pins
  digitalWrite(ledPin, toggle);
  digitalWrite(ledPin2, offToggle);

  digitalWrite(ledPin3, toggle2);
  digitalWrite(ledPin3, offToggle2);
  digitalWrite(ledPin4, toggle2);
  digitalWrite(ledPin4, offToggle2);
  digitalWrite(ledPin5, toggle2);
  digitalWrite(ledPin5, offToggle2);
  digitalWrite(ledPin6, toggle2);
  digitalWrite(ledPin6, offToggle2);

  // Show in serial monitor
  Serial.printf("Button = %i ; Toggle = %i ; Falling = %i \n", buttonState, toggle, offToggle);
  Serial.println();
  Serial.printf("Button (2) = %i ; Counter = %i \n", button2State, counter);
}

void checkLEDs() {
  ms += 250;

  for (int i = 1; i <= 5; i++) {
    if (i == 4) {
      break;
    }

    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin5, HIGH);
    delay(ms);
    digitalWrite(ledPin6, HIGH);

    delay(ms);
    digitalWrite(ledPin3, LOW);
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms);
    digitalWrite(ledPin5, LOW);
    delay(ms);
    digitalWrite(ledPin6, LOW);
  }
}

void allBlinkLEDs() {
  ms += 250;

  for (int i = 1; i <= 5; i++) {
    if (i == 4) {
      break;
    }

    delay(ms);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    delay(ms);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
  }
}

void doneCheckedLEDs() {
  ms += 250;
  
  for (int i = 1; i <= 10; i++) {
    if (i == 4) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    delay(ms+250);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
  }
}

// ambulence
void siren1() {
  ms = 100;
  
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin6, HIGH);
    delay(ms);
    digitalWrite(ledPin6, LOW);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin3, LOW);
  }
}

// police
void siren2() {
  ms = 100;
  
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin6, HIGH);
    delay(ms);
    digitalWrite(ledPin6, LOW);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin3, LOW);
    delay(ms);
    digitalWrite(ledPin5, HIGH);
    delay(ms);
    digitalWrite(ledPin5, LOW);
  }
}

void floral() {
  ms = 500;

  for (int i = 1; i <= 10; i++) {
    if (i == 4) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    delay(ms);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
  }
}