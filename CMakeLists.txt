cmake_minimum_required(VERSION 3.16)
project(LEDDotMatrix)
add_subdirectory(tests)

include_directories(${PROJECT_SOURCE_DIR}/inc)
set(CMAKE_CXX_STANDARD 17)

add_executable(LEDDotMatrix_run main.cpp)