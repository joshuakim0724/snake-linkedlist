//
// Created by Joshua Kim on 4/9/18.
//
#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ref_ll.h"
#include "../src/snakebody.h"

using namespace snakelinkedlist;
using std::string;

TEST_CASE("Testing Begin and End and the ++ Operator") {
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

TEST_CASE("Testing * Operator") {
    std::vector<SnakeBodySegment> snake_vector;
    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(3);
    SnakeBodySegment snakebody3(4);
    snake_vector.push_back(snakebody1);
    snake_vector.push_back(snakebody2);
    snake_vector.push_back(snakebody3);

    LinkedList<SnakeBodySegment> list1 = LinkedList<SnakeBodySegment>(snake_vector);

    int counter = 0;

    for (auto it = list1.begin(); it != list1.end(); ++it) {
        REQUIRE(*it == snake_vector.at(counter));
        counter++;
    }
}

TEST_CASE("Testing != Operator") {
//    std::vector<SnakeBodySegment> snake_vector;
//    snake_vector.push_back(2);
//    snake_vector.push_back(3);
//    snake_vector.push_back(4);
//
//    std::vector<SnakeBodySegment> snake_vector2;
//    snake_vector2.push_back(4);
//    snake_vector2.push_back(3);
//    snake_vector2.push_back(5);
//
//    LinkedList<SnakeBodySegment> list1 = LinkedList<SnakeBodySegment>(snake_vector);
//    LinkedList<SnakeBodySegment> list2 = LinkedList<SnakeBodySegment>(snake_vector2);
//
//    LinkedList<SnakeBodySegment>::Iterator iterator1 = list1.begin();
//    LinkedList<SnakeBodySegment>::Iterator iterator2 = list2.end();
//
//    REQUIRE(iterator1 != iterator2);
}