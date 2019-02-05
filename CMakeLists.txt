cmake_minimum_required(VERSION 2.8) #min version of CMake

project(a_mpu6050) #Project's name

set(CMAKE_CXX_FLAGS "-Wall -pedantic -std=c++14") #need them flags

set(BOOST_ROOT /opt/boost)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.40.0 REQUIRED COMPONENTS system regex)

include_directories(include) #include files

include_directories(${Boost_INCLUDE_DIR})

file(GLOB SOURCES "source/*.cpp") #source files

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_executable(arduino_mpu6050 ${SOURCES})

target_link_libraries(arduino_mpu6050 ${Boost_LIBRARIES})

add_subdirectory(source)