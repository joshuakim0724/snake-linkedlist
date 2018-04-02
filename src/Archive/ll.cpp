#include "ll.h"

namespace snakelinkedlist {

    LinkedList::LinkedList() {
        head_ = nullptr;
        head_.next_ = nullptr;
        head_.data_ = nullptr;
    }

    LinkedList::LinkedList(const std::vector<SnakeBodySegment> &values) {

    }

    LinkedList::LinkedList(const LinkedList &source) {

    }

    LinkedList::LinkedList(LinkedList &&source) noexcept {

    }

    LinkedList::~LinkedList() {

    }

    LinkedList &LinkedList::operator=(const LinkedList &source) {
        return <#initializer#>;
    }

    LinkedList &LinkedList::operator=(LinkedList &&source) noexcept {
        return <#initializer#>;
    }
} // namespace snakelinkedlist
