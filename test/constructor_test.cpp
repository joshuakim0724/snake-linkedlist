//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;

TEST_CASE("Null Copy Constructor") {
    LinkedList linkedList = LinkedList();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    linkedList.push_back(snakebody1);
    linkedList.push_back(snakebody2);
    linkedList.push_back(snakebody3);

    LinkedList linkedList2 = LinkedList(linkedList);

    linkedList.pop_back();

    REQUIRE(linkedList.size() == 2);
    REQUIRE(linkedList2.size() == 3);
}

TEST_CASE("Copy Constructor With Values") {
    LinkedList linkedList = LinkedList();
    LinkedList linkedList2 = LinkedList(linkedList);

    REQUIRE(linkedList == linkedList2);
}