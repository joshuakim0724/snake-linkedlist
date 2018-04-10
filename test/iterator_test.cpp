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

TEST_CASE("Testing * Operator and test traversal with iterator") {
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
    std::vector<int> vector1 = {1, 2, 3};
    std::vector<int> vector2 = {4, 5, 6};

    LinkedList<int> list1 = LinkedList<int>(vector1);
    LinkedList<int> list2 = LinkedList<int>(vector2);


    LinkedList<int>::Iterator first_element = list1.begin();
    LinkedList<int>::Iterator last_element = list1.end();

    REQUIRE((first_element != last_element));

    LinkedList<int>::Iterator same_element_as_first = list1.begin();

    REQUIRE(!(first_element != same_element_as_first));
}

TEST_CASE("Testing begin()") {
    std::vector<string> vector1 = {"hello", "hi", "lol"};

    LinkedList<string> list1 = LinkedList<string>(vector1);

    LinkedList<string>::Iterator first_element = list1.begin();
    LinkedList<string>::Iterator same_element = list1.begin();

    REQUIRE(!(first_element != same_element));
}

TEST_CASE("Testing end()") {
    std::vector<string> vector1 = {"hello", "hi", "lmao"};

    LinkedList<string> list1 = LinkedList<string>(vector1);

    LinkedList<string>::Iterator last_element = list1.end();
    LinkedList<string>::Iterator same_element = list1.end();

    REQUIRE(!(last_element != same_element));
}