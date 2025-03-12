cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME llvm)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ./main.cpp)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
)
