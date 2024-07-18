#define LED_PIN 11
#define BUTTON_PIN 9
#define POTENTIOMETER_PIN A1

// Read button’s state – with debounce
unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;
byte lastButtonState = HIGH;
bool LEDOn = true;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = timeNow;
      lastButtonState = buttonState;
      if (buttonState == HIGH) { // button has been released
        LEDOn = ! LEDOn;
      }
    }
  }
  
  if (LEDOn) {
    int potentiometerValue = analogRead(POTENTIOMETER_PIN);
    int brightness = map(potentiometerValue, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness); 
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
