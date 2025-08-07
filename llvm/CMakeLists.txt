cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME SimpleLLVM)
project(${PROJECT_NAME})

set(HEADER_FILES
    ./include/llvm/Config/llvm-config.h
    ./include/llvm-c/DataTypes.h
    ./include/llvm-c/Deprecated.h
    ./include/llvm-c/Error.h
    ./include/llvm-c/ExternC.h
    ./include/llvm-c/Types.h
    ./include/llvm-c/Visibility.h
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ./main.cpp)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${HEADER_FILES} main.cpp
)
