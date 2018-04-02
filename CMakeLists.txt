cmake_minimum_required(VERSION 3.5)
project(snake-linked-list)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Main src/ll.cpp src/snakebody.cpp )

add_executable(Test test/ll_test.cpp  src/ll.cpp src/snakebody.cpp)