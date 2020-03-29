//
// Created by jaume on 3/28/20.
//

#ifndef SENSOR_MAIN_INCLUDE_RANGECALCULATOR_H_
#define SENSOR_MAIN_INCLUDE_RANGECALCULATOR_H_

class RangeCalculator {
 public:
  virtual ~RangeCalculator() = default;
  virtual void setRange(long minimum, long maximum) = 0;
  virtual unsigned short percent(long value) = 0;
  virtual long absolute(long value) = 0;
  virtual long relative(long value) = 0;
};

#endif //SENSOR_MAIN_INCLUDE_RANGECALCULATOR_H_
