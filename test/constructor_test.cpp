//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ll.h"
using namespace snakelinkedlist;
using std::string;

std::ostringstream stream;

TEST_CASE("Testing Base Constructor") {
    LinkedList list = LinkedList();

    REQUIRE(list.empty());
}

TEST_CASE("Testing Constructor Using Array") {
    std::vector<SnakeBodySegment> snake_vector;
    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(3);
    SnakeBodySegment snakebody3(4);
    snake_vector.push_back(snakebody1);
    snake_vector.push_back(snakebody2);
    snake_vector.push_back(snakebody3);

    LinkedList list = LinkedList(snake_vector);

    REQUIRE(list.size() == 3);

    std::ostringstream stream;
    stream << list;
    string snake_values = "2, 3, 4";

    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Testing Copy Constructor is Deep Copy") {
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

TEST_CASE("Testing Copy Constructor is Deep Copy #2") {
    LinkedList linkedList = LinkedList();
    LinkedList linkedList2 = LinkedList(linkedList);

    SnakeBodySegment snakebody1(2);

    linkedList.push_back(snakebody1);

    REQUIRE(linkedList.size() == 1);
    REQUIRE(linkedList2.size() == 0);
}

TEST_CASE("Move Constructor Base Case") {
    LinkedList list;
    LinkedList test_data(*(new LinkedList()));

    REQUIRE(list == test_data);
}

TEST_CASE("Move Constructor") {
    std::vector<SnakeBodySegment> data;

    SnakeBodySegment snakebody1(1);
    SnakeBodySegment snakebody2(2);
    SnakeBodySegment snakebody3(3);

    data.push_back(snakebody1);
    data.push_back(snakebody2);
    data.push_back(snakebody3);

    LinkedList dataList(data);

    LinkedList test_data(std::move(dataList));

    stream << test_data;

    REQUIRE(dataList.size() == 0);
    REQUIRE(stream.str() == "1, 2, 3");
}