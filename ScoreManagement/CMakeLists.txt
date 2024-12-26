cmake_minimum_required(VERSION 3.29)
project(.)

set(CMAKE_CXX_STANDARD 20)

add_executable(ScoreManagement main.cpp
        list.cpp
        query.h
        list.h
        query.cpp
        print.cpp
        print.h)
