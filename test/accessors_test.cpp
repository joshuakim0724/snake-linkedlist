//
// Created by Joshua Kim on 4/3/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;
using std::string;

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

    list.push_back(snakebody2);
    REQUIRE(list.front() == snakebody1);
}

TEST_CASE("Testing back Base Case") {
    LinkedList list = LinkedList();
    SnakeBodySegment snake;

    REQUIRE(list.back() == snake);
}

TEST_CASE("Testing back") {
    LinkedList list = LinkedList();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);

    list.push_back(snakebody1);
    REQUIRE(list.back() == snakebody1);

    list.push_back(snakebody2);
    std::ostringstream stream;
    stream << list;
    string snake_values = "2, 4";

    REQUIRE(stream.str() == snake_values);

    REQUIRE(list.back() == snakebody2);
}

TEST_CASE("Testing Size()") {
    LinkedList list = LinkedList();

    REQUIRE(list.size() == 0);

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);

    list.push_back(snakebody1);

    REQUIRE(list.size() == 1);

    list.push_back(snakebody2);

    REQUIRE(list.size() == 2);

    list.pop_back();

    REQUIRE(list.size() == 1);
}

TEST_CASE("Testing GetVector Base case") {
    LinkedList list = LinkedList();
    std::vector<SnakeBodySegment> snake_value;

    REQUIRE(list.GetVector() == snake_value);
}

TEST_CASE("Testing GetVector") {
    LinkedList list = LinkedList();
    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    list.push_back(snakebody1);
    list.push_back(snakebody2);
    list.push_back(snakebody3);

    std::vector<SnakeBodySegment> snake_value;

    snake_value.push_back(snakebody1);
    snake_value.push_back(snakebody2);
    snake_value.push_back(snakebody3);

    REQUIRE(list.GetVector() == snake_value);

    REQUIRE(list.GetVector().size() == 3);
}