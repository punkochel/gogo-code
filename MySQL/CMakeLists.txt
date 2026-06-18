cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)
project(MySQL VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(mariadb-connector-c REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} mariadb-connector-c::mariadb-connector-c)
