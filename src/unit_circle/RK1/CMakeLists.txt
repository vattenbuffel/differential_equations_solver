cmake_minimum_required(VERSION 3.10)
project(CircleRK1)

add_executable(main ../../output.cpp ../../RK.cpp ../../RK1.cpp CircleRK1.cpp main.cpp)
