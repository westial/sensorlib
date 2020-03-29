#ifndef POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_
#define POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_

#include "Sensor.h"
#include "RangeCalculator.h"

class FunctionalSensor : public Sensor {
 private:
  long (*captureFn)(const long);
  long id;
  RangeCalculator *calculator;
  long value{};

 public:
  FunctionalSensor(
      long (*captureFn)(const long),
      long id,
      RangeCalculator *calculator);

  void capture() override;
  unsigned short percent() override;
  long absolute() override;
  long relative() override;

  ~FunctionalSensor() override;
};

#endif // POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_