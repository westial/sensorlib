/**
 * Feature:
 * Sensor outputs reading
 *
 * All tests are based onto the next specifications
 *
 * Given:
 * A sensor output value as MOCK_CURRENT_READING
 * A lowest value for sensor as READING_LOWEST and highest value as READING_HIGHEST
 *
 * When:
 * I ask the sensor for one of its outputs
 *
 */

#include <Sensor.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gmock-global/gmock-global.h"
#include "BasicRangeCalculator.h"
#include "FunctionalSensor.h"
#include "RangeCalculator.h"
#include "mock/mockcontrolpanelfunctions.cc"

using ::testing::Return;

/**
 * Scenario:
 * Get the reading percentage value.
 *
 * Then:
 * Sensor outputs the expected value.
 */
TEST(SensorCaptureTestSuite, Percentage) {
  RangeCalculator *calculator = new BasicRangeCalculator(new Percentage());
  calculator->setRange(0, 500);

  Sensor *potentiometer = new FunctionalSensor(
      readPotentiometer,
      123,
      calculator
  );

  EXPECT_GLOBAL_CALL(
      readPotentiometer,
      readPotentiometer(123))
      .Times(1)
      .WillOnce(Return(250));

  potentiometer->capture();

  EXPECT_EQ(50, potentiometer->percent());
}

/**
 * Scenario:
 * Get the reading absolute value
 *
 * Then:
 * Sensor outputs the expected value.
 */
TEST(SensorCaptureTestSuite, Absolute) {
  RangeCalculator *calculator = new BasicRangeCalculator(new Percentage());
  calculator->setRange(10, 125);

  Sensor *potentiometer = new FunctionalSensor(
      readPotentiometer,
      123,
      calculator
  );

  EXPECT_GLOBAL_CALL(
      readPotentiometer,
      readPotentiometer(123))
      .Times(1)
      .WillOnce(Return(99));

  potentiometer->capture();

  EXPECT_EQ(99, potentiometer->absolute());
}

/**
 * Scenario:
 * Get the reading relative value
 *
 * Then:
 * Sensor outputs the expected value.
 */
TEST(SensorCaptureTestSuite, Relative) {
  RangeCalculator *calculator = new BasicRangeCalculator(new Percentage());
  calculator->setRange(88, 456);

  Sensor *potentiometer = new FunctionalSensor(
      readPotentiometer,
      123,
      calculator
  );

  EXPECT_GLOBAL_CALL(
      readPotentiometer,
      readPotentiometer(123))
      .Times(1)
      .WillOnce(Return(100));

  potentiometer->capture();

  EXPECT_EQ(12, potentiometer->relative());
}