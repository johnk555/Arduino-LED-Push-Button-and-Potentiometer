#define LED_PIN 11
#define BUTTON_PIN 3
#define POTENTIOMETER_PIN A1

unsigned long delayBetweenBlink = 500;
unsigned long lastTimeLEDBlinked = 0;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;
byte lastButtonState = HIGH;
bool blinkEnabled = true;
byte LEDState = LOW;
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
        blinkEnabled = !blinkEnabled;
      }
    }
  }
  
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  delayBetweenBlink = map(potentiometerValue, 0, 1024, 0, 2000);
  
  if (blinkEnabled) {
    if (timeNow - lastTimeLEDBlinked > delayBetweenBlink) {
      lastTimeLEDBlinked = timeNow;
      LEDState = (LEDState == HIGH) ? LOW : HIGH;
      digitalWrite(LED_PIN, LEDState);
    }
  }
}
