cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)
project(gogo-apps LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Hello)
add_subdirectory(Diamond)
add_subdirectory(Window)
add_subdirectory(MySQL)
