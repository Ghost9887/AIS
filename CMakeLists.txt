cmake_minimum_required(VERSION 3.14)

project(ais)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/orbital/orbital.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
