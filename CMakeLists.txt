cmake_minimum_required(VERSION 3.25)
project(CS1570_Final)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC *.cpp *.h)

add_executable(CS1570_Final
        ${SRC})
