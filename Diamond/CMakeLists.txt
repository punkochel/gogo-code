cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)
project(Diamond VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp)
