cmake_minimum_required(VERSION 3.22)
project(cmakeproject)
set(SRC_FILES 
    main.cpp 
    src/calc.cpp)
message(STATUS "SRC File has &{SRC_FILES}")   
message("path is  &{CMAKE_SOURCE_DIR}")    
if(EXISTS &{CMAKE_SOURCE_DIR}/main.cpp)
    message("file exists")
else()
message(FATAL_ERROR"file not exists")
endif()

add_executable(cmakebinary main.cpp src/calc.cpp)
target_include_directories(cmakebinary PUPLIC include/)