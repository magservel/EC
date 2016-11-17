cmake_minimum_required(VERSION 3.6)
project(EC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgmpxx -lgmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")



set(SOURCE_FILES main.cpp )
        #Point.cpp Point.h Curve.cpp Curve.h)
add_executable(EC ${SOURCE_FILES})
target_link_libraries(EC gmp)