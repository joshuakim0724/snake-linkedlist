//
// Created by Joshua Kim on 4/3/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;

TEST_CASE("Testing front Base Case") {
    LinkedList list = LinkedList();
    SnakeBodySegment snake;

    REQUIRE(list.front() == snake);
}

TEST_CASE("Testing front") {
    LinkedList list = LinkedList();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);

    list.push_back(snakebody1);
    REQUIRE(list.front() == snakebody1);

    list.push_front(snakebody2);
    REQUIRE(list.front() == snakebody2);

}