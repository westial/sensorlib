cmake_minimum_required(VERSION 3.16)
project(sensorlib)

set(CMAKE_CXX_STANDARD 14)

add_executable(sensorlib_main main.cpp)

include_directories(src/sensor)
add_subdirectory(src/sensor)

# Testing

enable_testing()
add_subdirectory(test)
target_link_libraries(
        unit_test_files
        gtest
        gmock
        gtest_main
        sensor
)