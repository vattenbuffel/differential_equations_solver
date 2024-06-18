cmake_minimum_required(VERSION 3.10)
project(NewtonRK4)


add_executable(main ../../output.cpp ../../RK.cpp ../../RK4.cpp NewtonRK4.cpp main.cpp)
