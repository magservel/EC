cmake_minimum_required(VERSION 3.6)
project(EC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgmpxx -lgmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES main.cpp Data.cpp Data.h Curves/Point.cpp Curves/Point.h Curves/Curve.cpp Curves/Curve.h DiffreHellman/DH.cpp DiffreHellman/DH.h)
add_executable(EC ${SOURCE_FILES})
target_link_libraries(EC gmp)