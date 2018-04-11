//
// Created by Joshua Kim on 4/2/18.
//

#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"
#include "../src/ref_ll.h"
#include "../src/snakebody.h"

using namespace snakelinkedlist;
using std::string;

// We will be testing .size() method while testing other methods concurrently
TEST_CASE("push front 1 Value") {
    LinkedList<SnakeBodySegment> linkedList = LinkedList<SnakeBodySegment>();

    REQUIRE(linkedList.empty());

    SnakeBodySegment snakebody(5);
    linkedList.push_front(snakebody);

    REQUIRE(linkedList.size() == 1);

    std::ostringstream stream;
    stream << linkedList;

    string snake_values = "5";
    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Push Front 3 Values") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

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

TEST_CASE("push back 1 Value") {
    LinkedList<SnakeBodySegment> linkedList = LinkedList<SnakeBodySegment>();

    REQUIRE(linkedList.empty());

    SnakeBodySegment snakebody(5);
    linkedList.push_back(snakebody);

    REQUIRE(linkedList.size() == 1);

    std::ostringstream stream;
    stream << linkedList;

    string snake_values = "5";
    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Push back 3 Values") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);
}

TEST_CASE("Pop Front") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);

    test_list.pop_front();

    std::ostringstream new_stream;
    new_stream << test_list;
    string new_values = "4, 3";

    REQUIRE(new_stream.str() == new_values);
    REQUIRE(test_list.size() == 2);
}

TEST_CASE("Pop back") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);

    test_list.pop_back();

    std::ostringstream new_stream;
    new_stream << test_list;
    string new_values = "2, 4";

    REQUIRE(new_stream.str() == new_values);
    REQUIRE(test_list.size() == 2);

    test_list.pop_back();

    REQUIRE(test_list.size() == 1);

    test_list.pop_back();

    REQUIRE(test_list.empty());
}

TEST_CASE("Pop Null LinkedList") {
    LinkedList<string> list;
    list.pop_back();
    list.pop_front();
}

TEST_CASE("Remove 0 Nth") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);

    test_list.RemoveNth(0);

    std::ostringstream new_stream;
    new_stream << test_list;
    string new_values = "4, 3";

    REQUIRE(new_stream.str() == new_values);
}

TEST_CASE("Remove 1 Nth") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);

    test_list.RemoveNth(1);

    std::ostringstream new_stream;
    new_stream << test_list;
    string new_values = "2, 3";

    REQUIRE(new_stream.str() == new_values);
}

TEST_CASE("Remove Impossible Nth") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    test_list.RemoveNth(0);

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    std::ostringstream stream;
    stream << test_list;
    string snake_values = "2, 4, 3";

    REQUIRE(stream.str() == snake_values);

    test_list.RemoveNth(4);
}

TEST_CASE("Clear LinkedList") {
    LinkedList<SnakeBodySegment> test_list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);
    SnakeBodySegment snakebody3(3);

    test_list.push_back(snakebody1);
    test_list.push_back(snakebody2);
    test_list.push_back(snakebody3);

    REQUIRE(test_list.size() == 3);

    test_list.clear();

    REQUIRE(test_list.empty());
}