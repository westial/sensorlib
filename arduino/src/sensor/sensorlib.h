#ifndef SENSORLIB_ARDUINO_SENSORLIB_H_
#define SENSORLIB_ARDUINO_SENSORLIB_H_

#include <RangeCalculator.h>
#include <BasicRangeCalculator.h>
#include <FunctionalSensor.h>
#include <Percentage.h>

Sensor *createSensor(
    long (*capture)(const long),
    long minSensorValue,
    long maxSensorValue,
    int sensorId
    ) {
  RangeCalculator *calculator;
  Sensor *potentiometer;

  calculator = new BasicRangeCalculator(new Percentage());
  calculator->setRange(minSensorValue, maxSensorValue);

  return new FunctionalSensor(capture, sensorId, calculator);
}

long captureFn(const long sensorId);

#endif //SENSORLIB_ARDUINO_SENSORLIB_H_
