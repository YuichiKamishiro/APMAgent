cmake_minimum_required(VERSION 3.5...3.10)
project(apmagent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED src/Agent.cpp src/CpuUsage.cpp)