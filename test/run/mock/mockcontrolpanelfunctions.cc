#ifndef POTENTIOMETER_LIB__MOCK_CONTROLPANELFUNCTIONS_H_
#define POTENTIOMETER_LIB__MOCK_CONTROLPANELFUNCTIONS_H_

#include <gmock/gmock.h>
#include "gmock-global/gmock-global.h"

MOCK_GLOBAL_FUNC1(readPotentiometer, long(const long));

#endif //POTENTIOMETER_LIB__MOCK_CONTROLPANELFUNCTIONS_H_