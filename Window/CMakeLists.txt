cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)
project(Window VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE UNICODE_)
