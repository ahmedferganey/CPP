
cmake_minimum_required(VERSION 3.10)

project(cpp_20_course)
set(CMAKE_CXX_STANDARD 20) # Example: Set C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_definitions(-std=c++20)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(${CMAKE_SOURCE_DIR})

## # Create target for each .cc file
#     FILE(GLOB sources *.cc)
#     foreach(source ${sources})
#       get_filename_component(target ${source} NAME_WE)
#       add_executable(${target} ${target}.cc)
#     endforeach()

add_executable(ProjectTwentyTwo            catchup.cpp)
add_executable(ProjectTwentyThree          exception.cpp)
add_executable(ProjectTwentyFour           try_assertion.cpp)


add_executable(ProjectTwentyFive           vector.cpp)
add_executable(ProjectTwentySex            vectorp2.cpp)
add_executable(ProjectTwentySeven          vectorp3.cpp)
add_executable(ProjectTwentyEight          vectorp4.cpp)


#add_executable(ProjectTwentySex             namespaces.cpp)
#add_executable(ProjectTwentySeven           try_assertion.cpp)
#add_executable(ProjectTwentyEight           try_assertion.cpp)
#add_executable(ProjectTwentyNine            try_assertion.cpp)
#add_executable(ProjectThirty                try_assertion.cpp)
#add_executable(ProjectThirtyOne             try_assertion.cpp)
#add_executable(ProjectThirtyTwo             try_assertion.cpp)
#add_executable(ProjectThirtyThree           try_assertion.cpp)
#add_executable(ProjectThirtyFour            try_assertion.cpp)






