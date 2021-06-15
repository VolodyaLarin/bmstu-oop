cmake_minimum_required(VERSION 3.19)
project(oop2)

add_executable(app ./src/base.cpp ./src/main.cpp)
target_include_directories(app PUBLIC ./)
