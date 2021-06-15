cmake_minimum_required(VERSION 3.19)
project(lab_04_lib)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        lib.cpp
        publisher_subscriber/event.h
        publisher_subscriber/i_publisher.h
        publisher_subscriber/i_subscriber.h
        publisher_subscriber/publisher.cpp
        publisher_subscriber/publisher.h
        publisher_subscriber/subscriber.cpp
        publisher_subscriber/subscriber.h
        publisher_subscriber/i_subscriber.cpp doors/doors.cpp doors/doors.h timer/timer.cpp timer/timer.h cabin/cabin.cpp cabin/cabin.h controller/controller.cpp controller/controller.h panel/panel.cpp panel/panel.h panel/floor_button.cpp panel/floor_button.h lift/lift.cpp lift/lift.h publisher_subscriber/event.cpp)
add_library(lib ${SOURCES})