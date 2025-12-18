project(MySQL VERSION 0.1.0 LANGUAGES CXX C)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE sdk/include/mariadb)

target_link_directories(${PROJECT_NAME} PRIVATE sdk/lib/mariadb)

target_link_libraries(${PROJECT_NAME} PRIVATE libmariadb)
