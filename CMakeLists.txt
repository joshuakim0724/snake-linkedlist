cmake_minimum_required(VERSION 3.5)
project(snake-linked-list)

set(CMAKE_CXX_STANDARD 14)

add_executable(iterator_test "test/iterator_test.cpp" src/ref_ll.h src/snakebody.cpp src/snakebody.h)

add_executable(constructor_test "test/constructor_test.cpp" src/ll.cpp src/snakebody.cpp)

add_executable(modifers_test "test/modifiers_test.cpp" src/ll.cpp src/snakebody.cpp)

add_executable(accessors_test "test/accessors_test.cpp" src/ll.cpp src/snakebody.cpp)

#below is for ref test

add_executable(ref_iterator_test "ref_test/iterator_test.cpp" src/ref_ll.h src/snakebody.cpp src/snakebody.h)

add_executable(ref_constructor_test "ref_test/constructor_test.cpp" src/ref_ll.h src/snakebody.cpp)

add_executable(ref_modifers_test "ref_test/modifiers_test.cpp" src/ref_ll.h src/snakebody.cpp)

add_executable(ref_accessors_test "ref_test/accessors_test.cpp" src/ref_ll.h src/snakebody.cpp)

