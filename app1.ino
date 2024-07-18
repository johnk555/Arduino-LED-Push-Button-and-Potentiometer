#define LED_PIN 11
#define BUTTON_PIN 9
#define POTENTIOMETER_PIN A1

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == LOW){
    int potentiometerValue = analogRead(POTENTIOMETER_PIN);
    int brightness = map(potentiometerValue, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness);
  }
}
