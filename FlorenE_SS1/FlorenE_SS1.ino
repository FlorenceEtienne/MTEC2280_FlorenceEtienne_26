const int ledPin = 4; // white
const int ledPin2 = 5; // green
const int ledPin3 = 2; // red
const int ledPin4 = 42; // blue

const int ledPin5 = 6; // green
const int ledPin6 = 41; // red

int ms; // time used checking LEDs and four-patterned LEDs
int switchTime = 100; // time used checking the switch pattern with a short time

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);

  Serial.begin(115200);
  usedPins();
}

// Indicating what pins are being used

void usedPins() {
  Serial.println();
  Serial.println("These are for checking four-patterned LEDs");
  Serial.print("Pin ");
  Serial.println(ledPin);
  Serial.print("Pin ");
  Serial.println(ledPin2);
  Serial.print("Pin ");
  Serial.println(ledPin3);
  Serial.print("Pin ");
  Serial.println(ledPin4);

  Serial.println("These are for checking switch LEDs");
  Serial.print("Pin ");
  Serial.println(ledPin);
  Serial.print("Pin ");
  Serial.println(ledPin2);
}

void loop() {
  checkLEDs();
  sirens();
  floral();
  switchLED();
}

void checkLEDs() {
  ms += 250;
  for (int i = 1; i <= 5; i++) {
    if (i == 4) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin, HIGH);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin4, HIGH);

    delay(ms);
    digitalWrite(ledPin, LOW);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin3, LOW);
    delay(ms);
    digitalWrite(ledPin4, LOW);

    delay(ms);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  for (int i = 1; i <= 5; i++) {
    if (i == 4) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    delay(ms+250);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
  }
}

void sirens() {
  ms = 100;

  // ambulence
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin3, LOW);
    delay(ms);
    digitalWrite(ledPin, HIGH);
    delay(ms);
    digitalWrite(ledPin, LOW);
  }

  // police
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms);
    digitalWrite(ledPin3, LOW);
    delay(ms);
    digitalWrite(ledPin, HIGH);
    delay(ms);
    digitalWrite(ledPin, LOW);
    delay(ms);
    digitalWrite(ledPin4, HIGH);
    delay(ms);
    digitalWrite(ledPin4, LOW);
  }
}

void floral() {
  ms = 500;

  for (int i = 1; i <= 10; i++) {
    if (i == 4) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
  }
}

void switchLED() {

  switchTime ++;
  delay(switchTime);
  Serial.println(switchTime);
    
  if (switchTime >= 100) {
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, LOW);
  }

  if (switchTime >= 103) {
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, HIGH);
  }

  if (switchTime >= 105) {
    switchTime = 100;
  }
}

