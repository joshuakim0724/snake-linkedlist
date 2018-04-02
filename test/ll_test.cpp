//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;

TEST_CASE("Copy Constructor") {
    LinkedList linkedList = LinkedList();
    LinkedList linkedList2 = LinkedList(linkedList);

    REQUIRE(linkedList == linkedList2);
}