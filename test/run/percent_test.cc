/**
 * Feature:
 * Percentage calculation tests
 *
 * Given:
 * A minimum and maximum values
 *
 * When:
 * I ask for percentage value of a NUMBER
 *
 * Then:
 * The percentage service returns the expected RESULT.
 */
#include <Percentage.h>
#include "gtest/gtest.h"

void ExecutePercentTest(
    const long minimum,
    const long maximum,
    const long value,
    const long expected) {

  auto *percentage = new Percentage();

  EXPECT_EQ(expected, percentage->calculate(minimum, maximum, value));
}

/**
 * Scenario:
 * Calculate the percent for the given very basic range and value.
 */
TEST(SensorTestSuite, BasicValues) {
  ExecutePercentTest(0, 100, 30, 30);
}

/**
 * Scenario:
 * Calculate the percent for the given negative range and negative value.
 */
TEST(SensorTestSuite, NegativeValues) {
  ExecutePercentTest(-910, -10, -460, 50);
}

/**
 * Scenario:
 * Calculate the percent for the given positive/negative mixed ranges and values.
 */
TEST(SensorTestSuite, MixedValues) {
  ExecutePercentTest(-99, 901, 501, 60);
  ExecutePercentTest(-10000, 30005, 12345, 55);
}

/**
 * Scenario:
 * Calculate the percent for the given lower highest than lowest value.
 */
TEST(SensorTestSuite, InvertedRange) {
  ExecutePercentTest(100, 0, 30, 70);
}
