const int adcPin_1 = 2;
int adcRead_1 = 0;
const int buttonPin_1 = 41;
bool buttonState_1 = 0;

const int adcPin_2 = 1;
int adcRead_2 = 0;
const int buttonPin_2 = 42;
bool buttonState_2 = 0;

int lastTime = 0;
int currentTime = 0;
int timerInterval = 5;

void setup() {
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  analogReadResolution(2);  
  Serial.begin(9600);
}

void loop() {
  adcRead_1 = analogRead(adcPin_1);
  adcRead_2 = analogRead(adcPin_2);

  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  currentTime = millis();

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime;

    Serial.print(adcRead_1);
    Serial.print(',');
    Serial.print(buttonState_1);
    Serial.print(',');

    Serial.print(adcRead_2);
    Serial.print(',');
    Serial.print(buttonState_2);
    Serial.print('\n');
  }
}

