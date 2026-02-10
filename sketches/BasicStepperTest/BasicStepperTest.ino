/*
  BasicStepperTest.ino

  Proof-of-concept Arduino sketch:
  - Blinks the onboard LED
  - Toggles DIR and STEP pins
  - No motor required

  Board: Arduino Uno R3

  Need to test with motors, but the code did seem to work.
*/

const int DIR_PIN    = 2;   // Arbitrary digital pin
const int STEP_PIN   = 3;   // Arbitrary digital pin
const int ENABLE_PIN = 4;   // Optional, active LOW on DRV8825

const int LED_PIN = LED_BUILTIN;

void setup()
{
  // Initialize pins
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Disable motor driver (safe default)
  digitalWrite(ENABLE_PIN, HIGH);

  // Initial states
  digitalWrite(DIR_PIN, LOW);
  digitalWrite(STEP_PIN, LOW);

  // Serial for sanity/debug
  Serial.begin(9600);
  Serial.println("BasicStepperTest starting...");
}

void loop()
{
  // Blink LED so we know the sketch is alive
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);

  Serial.println("Toggling DIR, pulsing STEP");

  // Enable driver
  digitalWrite(ENABLE_PIN, LOW);

  // Toggle direction
  digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));

  // Generate 10 fake "steps"
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  // Disable driver again
  digitalWrite(ENABLE_PIN, HIGH);

  delay(2000);
}
