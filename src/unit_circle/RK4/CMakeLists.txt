cmake_minimum_required(VERSION 3.10)
project(CircleRK4)


add_executable(main ../../output.cpp ../../RK.cpp ../../RK4.cpp CircleRK4.cpp main.cpp)
