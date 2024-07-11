
cmake_minimum_required(VERSION 3.10)

project(cpp_course)
set(CMAKE_CXX_STANDARD 11) # Example: Set C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(${CMAKE_SOURCE_DIR})

## # Create target for each .cc file
#     FILE(GLOB sources *.cc)
#     foreach(source ${sources})
#       get_filename_component(target ${source} NAME_WE)
#       add_executable(${target} ${target}.cc)
#     endforeach()

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


add_executable(ProjectTwelve                RangeFor.cpp)
add_executable(ProjectThirteen              NewDelete.cpp)
add_executable(ProjectFourteen              ManagerObject.cpp)
add_executable(ProjectFiveteen              DeskCalc.cpp)
add_executable(ProjectSixteen               lambdafuncpointer.cpp)
add_executable(ProjectSeventeen             lambda.cpp)







