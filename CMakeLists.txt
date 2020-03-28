cmake_minimum_required(VERSION 3.16)
project(sensor_main)

set(CMAKE_CXX_STANDARD 14)

add_executable(sensor_main main.cpp)

include_directories(include)
add_subdirectory(include)

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