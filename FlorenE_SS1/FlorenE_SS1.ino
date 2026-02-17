const int ledPin = 4; // white
const int ledPin2 = 5; // green
const int ledPin3 = 7; // red
const int ledPin4 = 6; // blue

const int ledPin5 = 1; // red
const int ledPin6 = 2; // white
const int ledPin7 = 42; // blue

int ms; // checking leds with half a second delay
// int l_ms = 1000; // to keep leds lit longer 
// int s_ms = 250; // siren patterns with quarter a second delay

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);

  Serial.begin(115200);
  usedPins();
}

// Indicating what pins are being used

void usedPins() {
  Serial.println();
  Serial.println("These are for checking all LEDs");
  Serial.print("Pin ");
  Serial.println(ledPin);
  Serial.print("Pin ");
  Serial.println(ledPin2);
  Serial.print("Pin ");
  Serial.println(ledPin3);
  Serial.print("Pin ");
  Serial.println(ledPin4);
  Serial.println();
  Serial.println("These are for siren patterns");
  Serial.print("Pin ");
  Serial.println(ledPin5);
  Serial.print("Pin ");
  Serial.println(ledPin6);
  Serial.print("Pin ");
  Serial.println(ledPin7);
}

void loop() {
  checkLEDs();
  sirens();
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
}

void sirens() {
  ms = 100;

  // ambulence
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin5, HIGH);
    delay(ms);
    digitalWrite(ledPin5, LOW);
    delay(ms);
    digitalWrite(ledPin6, HIGH);
    delay(ms);
    digitalWrite(ledPin6, LOW);
  }

  // police
  for (int i = 1; i <= 10; i++) {
    if (i == 8) {
      break;
    }
    delay(ms);
    digitalWrite(ledPin5, HIGH);
    delay(ms);
    digitalWrite(ledPin5, LOW);
    delay(ms);
    digitalWrite(ledPin7, HIGH);
    delay(ms);
    digitalWrite(ledPin7, LOW);
  }
}