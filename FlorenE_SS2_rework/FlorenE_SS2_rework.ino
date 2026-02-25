/*
When the first button is pressed, the red turns into a green light to start pattern routine.
If you toggle on the second button, each pattern loops to the next pattern after a certain 
amount of counts happen.
*/

// switches between control leds when button is pushed

const int buttonPin = 1; // push buttons

bool buttonState = 0;

const int ledPin = 42; // Green (on)
const int ledPin2 = 41; // Red (off) 

// toggles different led's patterns

const int buttonPin2 = 4; // Toggle Button

bool button2state = 0;
bool lastButton2state = 0;

bool toggle = 0;
bool fallToggle = 0;

const int ledPin3 = 5; // White
const int ledPin4 = 6; // Green
const int ledPin5 = 40; // Blue
const int ledPin6 = 39; // Red

int pat1ms = 250;
int pat2ms = 500;
int pat3ms = 100;
int pat4ms = 100;
int pat5ms = 500;

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
  buttonState = !digitalRead(buttonPin);
  delay(20);

  button2state = !digitalRead(buttonPin2);

  if (buttonState) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);

    if (button2state && !lastButton2state) {
      toggle = !toggle;
      digitalWrite(ledPin3, toggle);
      digitalWrite(ledPin4, toggle);
      digitalWrite(ledPin5, toggle);
      digitalWrite(ledPin6, toggle);

      // Pattern 1
      for (int i = 1; i <= 5; i++) {
        if (i == 4) {
          break;
        }

        delay(pat1ms);
        digitalWrite(ledPin3, HIGH);
        delay(pat1ms);
        digitalWrite(ledPin4, HIGH);
        delay(pat1ms);
        digitalWrite(ledPin5, HIGH);
        delay(pat1ms);
        digitalWrite(ledPin6, HIGH);

        delay(pat1ms);
        digitalWrite(ledPin3, LOW);
        delay(pat1ms);
        digitalWrite(ledPin4, LOW);
        delay(pat1ms);
        digitalWrite(ledPin5, LOW);
        delay(pat1ms);
        digitalWrite(ledPin6, LOW);
      }

      // Pattern 2
      for (int i = 1; i <= 5; i++) {
        if (i == 4) {
          break;
        }

        delay(pat2ms);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        delay(pat2ms);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
      }

      // Pattern 3
      for (int i = 1; i <= 10; i++) {
        if (i == 4) {
          break;
        }
        delay(pat3ms);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        delay(pat3ms);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
      }

      // Pattern 4
      for (int i = 1; i <= 10; i++) {
        if (i == 8) {
          break;
        }
        delay(pat4ms);
        digitalWrite(ledPin6, HIGH);
        delay(pat4ms);
        digitalWrite(ledPin6, LOW);
        delay(pat4ms);
        digitalWrite(ledPin3, HIGH);
        delay(pat4ms);
        digitalWrite(ledPin3, LOW);
      }

      // Pattern 5
      for (int i = 1; i <= 10; i++) {
        if (i == 4) {
          break;
        }
        delay(pat5ms);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin6, LOW);
        delay(pat5ms);
        digitalWrite(ledPin4, HIGH);
        delay(pat5ms);
        digitalWrite(ledPin4, LOW);
        delay(pat5ms);
        digitalWrite(ledPin4, HIGH);
        delay(pat5ms);
        digitalWrite(ledPin4, LOW);
        delay(pat5ms);
        digitalWrite(ledPin4, HIGH);
        delay(pat5ms);
        digitalWrite(ledPin4, LOW);
        delay(pat5ms);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
      }
    }

    if(!button2state && lastButton2state) {
      fallToggle = !fallToggle;
      digitalWrite(ledPin3, fallToggle);
      digitalWrite(ledPin4, fallToggle);
      digitalWrite(ledPin5, fallToggle);
      digitalWrite(ledPin6, fallToggle);
    }

    lastButton2state = button2state;
  }

  if (!buttonState) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
  }

  Serial.printf("Button 1 = %i ; Button 2 = %i \n", buttonState , button2state);
}
