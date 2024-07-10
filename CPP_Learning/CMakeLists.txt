
cmake_minimum_required(VERSION 3.10)

project(cpp_course)

set(CMAKE_CXX_STANDARD 11)  # Example: Set C++ standard


add_executable(main main.cpp)
add_executable(ProjectOne           Practical_Considerations_with_Cpp_Data_Types.cpp )
add_executable(ProjectTwo           Automatic_Type_Deduction.cpp)
add_executable(ProjectThree         RLValue.cpp)
add_executable(ProjectFour          Decltype.cpp)


add_executable(ProjectFive          Pointer.cpp)
add_executable(ProjectSix           Pointer2.cpp)

add_executable(ProjectSeven         Refrences.cpp)
add_executable(ProjectEight         Refrences2.cpp)


add_executable(ProjectNine          user_types_struct_array.cpp)
add_executable(ProjectTen           user_types_unions.cpp)
add_executable(ProjectEleven        user_types_enum.cpp)









