cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)
project(ChatAsio)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(asio)

add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

target_link_libraries(server asio::asio)
target_link_libraries(client asio::asio)
