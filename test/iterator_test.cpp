//
// Created by Joshua Kim on 4/9/18.
//
#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ref_ll.h"
#include "../src/snakebody.h"

using namespace snakelinkedlist;
using std::string;

TEST_CASE("Testing Begin and End") {
    std::vector<SnakeBodySegment> snake_vector;
    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(3);
    SnakeBodySegment snakebody3(4);
    snake_vector.push_back(snakebody1);
    snake_vector.push_back(snakebody2);
    snake_vector.push_back(snakebody3);

    LinkedList<SnakeBodySegment> list1 = LinkedList<SnakeBodySegment>(snake_vector);

    int count = 0;
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        count++;
    }

    REQUIRE(count == list1.size());
}