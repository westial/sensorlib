/**
 * This class captures a value from a delegated member and can provide 3
 * different outputs according a supported minimum/maximum value range.
 *
 * A sensor can output 3 different values of every reading:
 *
 *  * Absolute: the original value.
 *  * Relative: If the minimum reading value of the reader would be 0.
 *  * Percent: Calculates the percentage with the minimum and maximum reading values.
 *
 *  Example:
 *
 *  ```
 *  sensor->capture();
 *  long absolute = sensor->absolute();
 *  ```
 */

#ifndef POTENTIOMETER_LIB__CONTROLPANEL_H_
#define POTENTIOMETER_LIB__CONTROLPANEL_H_

#define MAX_TITLE_LENGTH 32

class Sensor {
 public:
  virtual void capture() = 0;
  virtual unsigned short percent() = 0;
  virtual long absolute() = 0;
  virtual long relative() = 0;
  virtual long getId() = 0;
  virtual char *getTitle() = 0;
  virtual ~Sensor() = default;
};

#endif //POTENTIOMETER_LIB__CONTROLPANEL_H_
