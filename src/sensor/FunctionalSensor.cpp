#include "FunctionalSensor.h"

FunctionalSensor::FunctionalSensor(
    long (*captureFn)(const long),
    long id,
    RangeCalculator *calculator) {
  this->captureFn = captureFn;
  this->id = id;
  this->calculator = calculator;
}
unsigned short FunctionalSensor::percent() {
  return calculator->percent(value);
}
long FunctionalSensor::absolute() {
  return calculator->absolute(value);
}
long FunctionalSensor::relative() {
  return calculator->relative(value);
}
void FunctionalSensor::capture() {
  this->value = captureFn(id);
}
FunctionalSensor::~FunctionalSensor() {
  delete calculator;
}
