cmake_minimum_required(VERSION 3.20)
project(Task_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 main.cpp tests.h tests.cpp SensorParser.cpp SensorParser.h SensorPNITrax.h)
