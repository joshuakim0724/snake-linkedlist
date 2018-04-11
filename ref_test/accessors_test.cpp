//
// Created by Joshua Kim on 4/3/18.
//

#define CATCH_CONFIG_MAIN
#include "../ref_test/catch.hpp"
#include "../src/ref_ll.h"
#include "../src/snakebody.h"
using namespace snakelinkedlist;
using std::string;

TEST_CASE("Testing front Base Case") {
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();
    SnakeBodySegment snake;

    REQUIRE(list.front() == snake);
}

TEST_CASE("Testing front") {
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();

    SnakeBodySegment snakebody1(2);
    SnakeBodySegment snakebody2(4);

    list.push_back(snakebody1);
    REQUIRE(list.front() == snakebody1);

    list.push_back(snakebody2);
    REQUIRE(list.front() == snakebody1);
}

TEST_CASE("Testing back Base Case") {
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();
    SnakeBodySegment snake;

    REQUIRE(list.back() == snake);
}

TEST_CASE("Testing back") {
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();

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
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();

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
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();
    std::vector<SnakeBodySegment> snake_value;

    REQUIRE(list.GetVector() == snake_value);
}

TEST_CASE("Testing GetVector") {
    LinkedList<SnakeBodySegment> list = LinkedList<SnakeBodySegment>();
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

TEST_CASE("Testing isEmpty") {
    LinkedList<SnakeBodySegment> list;

    REQUIRE(list.empty());
}

TEST_CASE("Testing empty is false") {
    LinkedList<SnakeBodySegment> list;
    list.push_back(1);

    REQUIRE(!list.empty());
}

TEST_CASE("Testing empty (adding and then removing values)") {
    LinkedList<SnakeBodySegment> list;

    REQUIRE(list.empty());

    list.push_back(1);

    REQUIRE(!list.empty());

    list.pop_back();

    REQUIRE(list.empty());
}
TEST_CASE("Testing << operator basecase") {
    LinkedList<int> list;

    std::ostringstream stream;
    stream << list;
    string link_value = "";

    REQUIRE(stream.str() == link_value);
}

TEST_CASE("Testing << operator") {
    LinkedList<int> list;

    list.push_back(2);
    list.push_back(3);

    std::ostringstream stream;
    stream << list;
    string link_value = "2, 3";

    REQUIRE(stream.str() == link_value);

    list.push_back(5);
    list.push_back(4);

    std::ostringstream new_stream;
    new_stream << list;

    string list_value = "2, 3, 5, 4";

    REQUIRE(new_stream.str() == list_value);
}

TEST_CASE("Testing == operator base case") {
    LinkedList<int> list1;
    LinkedList<int> list2;

    REQUIRE(list1 == list2);
}

TEST_CASE("Testing == operator") {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(5);

    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(5);

    REQUIRE(list1 == list2);
}

TEST_CASE("Testing == failure") {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.push_back(4);

    REQUIRE(!(list1 == list2));

    list1.push_back(1);

    list2.push_back(4);
    list2.push_back(2);

    REQUIRE(!(list1 == list2));
}

TEST_CASE("Testing != operator base case") {
    LinkedList<string> list1;
    LinkedList<string> list2;

    REQUIRE(!(list1 != list2));
}

TEST_CASE("Testing != operator") {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(5);

    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(5);

    REQUIRE(!(list1 != list2));
}

TEST_CASE("Testing !=") {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.push_back(4);

    REQUIRE(!(list1 == list2));

    list1.push_back(5);

    list2.push_back(4);
    list2.push_back(2);
    REQUIRE(list1 != list2);
}