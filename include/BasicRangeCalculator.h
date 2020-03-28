#ifndef POTENTIOMETER_LIB__BASICRANGECALCULATOR_H_
#define POTENTIOMETER_LIB__BASICRANGECALCULATOR_H_

#include "RangeCalculator.h"
#include "Percentage.h"

class BasicRangeCalculator : public RangeCalculator {
 private:
  long minimum{};
  long maximum{};
  Percentage *percentage;

 public:

  explicit BasicRangeCalculator(Percentage *percentage);

  void setRange(long minimum, long maximum) override;

  unsigned short percent(long value) override;

  long absolute(long value) override;

  long relative(long value) override;
};

#endif //POTENTIOMETER_LIB__BASICRANGECALCULATOR_H_
