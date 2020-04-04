/**
 * Example sketch using the sensorlib Arduino implementation.
 */
#include <Arduino.h>
#include <sensorlib.h>

#define MIN_SENSOR_VALUE    0
#define MAX_SENSOR_VALUE    138   // Sampled with 5K potentiometer.
#define DEFAULT_DURATION    100
#define WRITE_PIN_SENSOR_1  2
#define READ_PIN_SENSOR_1   A2

Sensor *potentiometer;

/**
 * Write signal and return the reading from the sensor.
 * @param duration between writing and reading.
 * @param writePin which pin to write on.
 * @param readPin which pin to read from.
 * @return the returned reading value from sensor.
 */
int capture(int duration, int writePin, int readPin) {
  int value;
  digitalWrite(writePin, HIGH);
  delay(duration);
  value = analogRead(readPin);
  digitalWrite(writePin, LOW);
  return value;
}

/**
 * Override the captureFn function required to pass as first parameter of the
 * sensor factory createSensor(...)
 * @param potentiometerId sensor identifier.
 * @return long value returned by the sensor within its minimum and maximum
 * capacity.
 */
long captureFn(const long potentiometerId) {
  return capture(DEFAULT_DURATION, WRITE_PIN_SENSOR_1, READ_PIN_SENSOR_1);
}

// -----------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  // Define potentiometer sensor with ID as #1
  potentiometer = createSensor(captureFn, MIN_SENSOR_VALUE, MAX_SENSOR_VALUE, 1);
}

void loop() {
  // Do the stuff
  Serial.println("Capturing potentiometer with ID as #1");
  potentiometer->capture();
  Serial.print("Absolute value = ");
  Serial.println(potentiometer->absolute());
  Serial.print("Relative value = ");
  Serial.println(potentiometer->relative());
  Serial.print("Percentage value according its minimum as ");
  Serial.print(MIN_SENSOR_VALUE);
  Serial.print(" and maximum as ");
  Serial.print(MAX_SENSOR_VALUE);
  Serial.print(" = ");
  Serial.print(potentiometer->percent());
  Serial.println("%");

  delay(1000);
}