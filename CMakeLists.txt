cmake_minimum_required(VERSION 3.12)
project(aircraft-temp-monitor CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core
    src/sensor.cpp
    src/logger.cpp
    src/alert.cpp
    src/controller.cpp
)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(aircraft-temp-monitor src/main.cpp)
target_link_libraries(aircraft-temp-monitor PRIVATE core)

# Tests
enable_testing()
add_executable(tests tests/test_temp.cpp)
target_link_libraries(tests PRIVATE core)
add_test(NAME unit_tests COMMAND tests)
