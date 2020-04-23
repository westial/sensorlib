#ifndef POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_
#define POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_

#include "Sensor.h"
#include "RangeCalculator.h"

class FunctionalSensor : public Sensor {
 private:
  long (*captureFn)(const long);
  long id;
  char title[MAX_TITLE_LENGTH]{};
  RangeCalculator *calculator;
  long value{};

  void setTitle(const char inputTitle[]);

 public:
  FunctionalSensor(
      long (*captureFn)(const long),
      long id,
      const char title[],
      RangeCalculator *calculator);
  long getId() override;
  char *getTitle() override;
  void capture() override;
  unsigned short percent() override;
  long absolute() override;
  long relative() override;

  ~FunctionalSensor() override;
};

#endif // POTENTIOMETER_LIB__FUNCTIONALSENSOR_H_