//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../ref_test/catch.hpp"
#include "../src/ref_ll.h"
#include "../src/snakebody.h"
using namespace snakelinkedlist;
using std::string;

std::ostringstream stream;

TEST_CASE("Testing Base Constructor") {
    LinkedList<string> list = LinkedList<string>();

    REQUIRE(list.empty());
}

TEST_CASE("Testing Constructor Using Vector") {
    std::vector<SnakeBodySegment> snake_vector;
    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(3);
    SnakeBodySegment snakebody3(4);
    snake_vector.push_back(snakebody1);
    snake_vector.push_back(snakebody2);
    snake_vector.push_back(snakebody3);


    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>(snake_vector);

    REQUIRE(list.size() == 3);

    stream << list;
    string snake_values = "2, 3, 4";

    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Testing Copy Constructor is Deep Copy") {
    std::vector<int> vector1 = {1,2,3};

    LinkedList<int> linkedList = LinkedList<int>(vector1);

    LinkedList<int> linkedList2(linkedList);

    linkedList.push_back(3);

    REQUIRE(linkedList.size() == 4);
    REQUIRE(linkedList2.size() == 3);

    linkedList = linkedList2;

    REQUIRE(linkedList.size() == 3);
}

TEST_CASE("Testing Copy Constructor is Deep Copy #2") {
    LinkedList<SnakeBodySegment> linkedList = LinkedList<SnakeBodySegment>();
    LinkedList<SnakeBodySegment> linkedList2 = LinkedList<SnakeBodySegment>(linkedList);

    SnakeBodySegment snakebody1(2);

    linkedList.push_back(snakebody1);

    REQUIRE(linkedList.size() == 1);
    REQUIRE(linkedList2.empty());
}

TEST_CASE("Move Constructor Base Case") {
    LinkedList<int> list;
    LinkedList<int> test_data(*(new LinkedList<int>()));

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

    LinkedList<SnakeBodySegment> dataList(data);

    LinkedList<SnakeBodySegment> test_data(std::move(dataList));

    stream.str(string());
    stream << test_data;

    REQUIRE(dataList.empty());
    REQUIRE(stream.str() == "1, 2, 3");
}