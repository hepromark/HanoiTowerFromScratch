cmake_minimum_required(VERSION 3.25)
project(hanoi_tower_recursion)

set(CMAKE_CXX_STANDARD 17)

add_executable(hanoi_tower_recursion
        test.cpp
        HanoiTower.cpp
        HanoiTower.h)
