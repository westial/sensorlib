#include "FunctionalSensor.h"

FunctionalSensor::FunctionalSensor(
    long (*captureFn)(const long),
    long id,
    const char title_[],
    RangeCalculator *calculator) {
  this->captureFn = captureFn;
  this->id = id;
  this->calculator = calculator;
  setTitle(title_);
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
long FunctionalSensor::getId() {
  return id;
}
char *FunctionalSensor::getTitle() {
  return title;
}
void FunctionalSensor::setTitle(const char *inputTitle) {
  int index = 0;
  while (
      index < MAX_TITLE_LENGTH - 1
      && inputTitle[index] != '\0'
      && (title[index] = inputTitle[index])) {
    ++ index;
  }
  title[index] = '\0';
}
