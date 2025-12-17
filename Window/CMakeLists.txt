project(Window VERSION 0.1.0 LANGUAGES CXX C)

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE UNICODE_)
