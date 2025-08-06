add_subdirectory(llvm)

if(NOT "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    configure_file(module.modulemap.build module.modulemap COPYONLY)
endif(NOT "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
