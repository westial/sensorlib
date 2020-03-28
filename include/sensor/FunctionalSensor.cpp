#include "FunctionalSensor.h"

FunctionalSensor::FunctionalSensor(
    long (*readInputFunc)(const long),
    long id,
    RangeCalculator *calculator) {
  this->readInputFunc = readInputFunc;
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
  this->value = readInputFunc(id);
}
FunctionalSensor::~FunctionalSensor() {
  delete calculator;
}
