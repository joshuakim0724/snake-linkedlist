#include "ll.h"

namespace snakelinkedlist {

    /**
     * Default Constructor;
     */
    LinkedList::LinkedList() {
        head_ = nullptr;
    }

    /**
     * Initalize From Vector
     * @param values
     */
    LinkedList::LinkedList(const std::vector<SnakeBodySegment> &values) {
        for (int i = 0; i < values.size(); i++) {

        }
    }

    // Copy constructor
    LinkedList::LinkedList(const LinkedList &source) {
        if (source.head_) {
            head_ = new ListNode(*source.head_);
        } else {
            head_ = nullptr;
        }

    }

    // Move Constructor
    LinkedList::LinkedList(LinkedList &&source) noexcept {
        head_ = source.head_;
        source.head_ = nullptr;
    }

    // Destructor
    LinkedList::~LinkedList() {
        delete head_;
    }

    // Copy assignment operator
    LinkedList &LinkedList::operator=(const LinkedList &source) {
        if (this == &source) {
            return (LinkedList &) nullptr;
        }

        delete head_;
        head_ = nullptr;
        if (source.head_) {
            head_ = new ListNode(*source.head_);
        }
        return *this;
    }

    // Move assignment operator
    LinkedList &LinkedList::operator=(LinkedList &&source) noexcept {
        if (this == &source) {
            return (LinkedList &) nullptr;
        }

        delete head_;
        head_ = source.head_;
        source.head_ = nullptr;

        return *this;
    }

    //--------------------------------------------Modifiers Methods-----------------------------------------------------

    void LinkedList::push_front(SnakeBodySegment value) {
        head_->next_= head_;
        head_->data_= value;
    }

    void LinkedList::push_back(SnakeBodySegment value) {

    }


} // namespace snakelinkedlist
