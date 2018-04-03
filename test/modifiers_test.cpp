//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;
using std::string;

// We will be testing .size() method while testing other methods concurrently
TEST_CASE("push front 1 Value") {
    LinkedList linkedList = LinkedList();

    REQUIRE(linkedList.size() == 0);

    SnakeBodySegment snakebody(5);
    linkedList.push_front(snakebody);

    REQUIRE(linkedList.size() == 1);

    std::ostringstream stream;
    stream << linkedList;

    string snake_values = "5";
    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Push Front 3 Values") {
    LinkedList test_list = LinkedList();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_front(snakebody1);
    test_list.push_front(snakebody2);
    test_list.push_front(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "3, 4, 2";

    REQUIRE(stream.str() == snake_values);
}