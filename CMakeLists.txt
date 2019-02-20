cmake_minimum_required(VERSION 3.3)

project(arduino_mpu_6050)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp serial.cpp window.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories("libraries/boost")

add_executable(arduino_mpu_6050 ${SOURCE_FILES})

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(arduino_mpu_6050 ${Boost_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})