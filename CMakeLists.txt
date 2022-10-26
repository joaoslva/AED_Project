cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project main.cpp ScheduleManagement.cpp CUClass.cpp Request.cpp Slot.cpp Student.cpp)
