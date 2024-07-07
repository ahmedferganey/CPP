
cmake_minimum_required(VERSION 3.10)

project(cpp_course)

set(CMAKE_CXX_STANDARD 11)  # Example: Set C++ standard


add_executable(main main.cpp)
add_executable(ProjectOne Practical_Considerations_with_Cpp_Data_Types.cpp )

add_executable(ProjectTwo Automatic_Type_Deduction.cpp)