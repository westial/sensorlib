#include "BasicRangeCalculator.h"

BasicRangeCalculator::BasicRangeCalculator(Percentage *percentage)
    : percentage(percentage) {}

unsigned short BasicRangeCalculator::percent(long value) {
  return percentage->calculate(minimum, maximum, value);
}

long BasicRangeCalculator::absolute(long value) {
  return value;
}

long BasicRangeCalculator::relative(long value) {
  return 0 - minimum + value;
}
void BasicRangeCalculator::setRange(long minimum_, long maximum_) {
  this->minimum = minimum_;
  this->maximum = maximum_;
}
