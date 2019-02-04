#Timothy Davis 

cmake_minimum_required(VERSION 2.8) #min version of CMake

project(arduino_mpu6050) #Project's name

add_executable(arduino_mpu6050 main.c serial_read.c)


