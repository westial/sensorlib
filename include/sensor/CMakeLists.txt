set(HEADER_FILES
        Sensor.h
        FunctionalSensor.h
        Percentage.h
        BasicRangeCalculator.h
        RangeCalculator.h)

set(SOURCE_FILES
        FunctionalSensor.cpp
        Percentage.cpp
        BasicRangeCalculator.cpp
        )

add_library(sensor STATIC ${HEADER_FILES} ${SOURCE_FILES})