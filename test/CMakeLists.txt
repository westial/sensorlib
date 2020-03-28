include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(${gmock-global_SOURCE_DIR}/include)

add_subdirectory(lib/googletest)
add_subdirectory(lib/gmock-global-master)

include_directories(run)
include_directories(run/mock)


set(SOURCE_FILES
        run/sensor_capture_test.cc
        run/percent_test.cc
        )

set(MOCK_FILES
        run/mock/mockcontrolpanelfunctions.cc
        )

add_library(mock_files ${MOCK_FILES})

add_executable(unit_test_files ${SOURCE_FILES})

add_test(NAME run_unit_test COMMAND unit_test_files)