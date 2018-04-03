cmake_minimum_required(VERSION 3.5)
project(snake-linked-list)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Main src/ll.cpp src/snakebody.cpp )

add_executable(constructor_test "test/constructor_test.cpp" src/ll.cpp src/snakebody.cpp)

add_executable(modifers_test "test/modifiers_test.cpp" src/ll.cpp src/snakebody.cpp)