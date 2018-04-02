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
        for (auto value : values) {
            push_back(value);
        }
    }

    // Copy constructor
    // Make two LinkedList and make sure values are different
    LinkedList::LinkedList(const LinkedList &source) {
        if (source.head_) {
            head_ = new ListNode(*source.head_);
        } else {
            head_ = nullptr;
        }
    }

    // Move Constructor
    //
    LinkedList::LinkedList(LinkedList &&source) noexcept {
        head_ = source.head_;
        source.head_ = nullptr;
    }

    // Destructor
    // Memeory leak testing
    LinkedList::~LinkedList() {
        delete head_;
    }

    // Copy assignment operator
    //
    LinkedList &LinkedList::operator=(const LinkedList &source) {
        if (this == &source) {
            return *this;
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
            return *this;
        }

        delete head_;
        head_ = source.head_;
        source.head_ = nullptr;

        return *this;
    }

    //--------------------------------------------Modifiers Methods-----------------------------------------------------

    void LinkedList::push_front(SnakeBodySegment value) {
        ListNode *new_node = new ListNode(value);
        new_node->next_ = head_;
        head_ = new_node;
    }

    void LinkedList::push_back(SnakeBodySegment value) {
        ListNode *current_node = head_;

        if (current_node == nullptr) {
            push_front(value);
            return;
        }

        ListNode *tail_node = new ListNode(value);

        while (current_node->next_) {
            current_node = current_node->next_;
        }
        current_node->next_ = tail_node;
    }

    //----------------------------------------------Accessors-----------------------------------------------------------

    SnakeBodySegment LinkedList::front() const {
        return head_->data_;
    }

    SnakeBodySegment LinkedList::back() const {
        return SnakeBodySegment();
    }

    int LinkedList::size() const {
        return 0;
    }

    std::vector<SnakeBodySegment> LinkedList::GetVector() const {
        std::vector<SnakeBodySegment> *snake_value = new std::vector<SnakeBodySegment>();

        if (head_ == nullptr) {
            return *snake_value;
        }

        ListNode *current_node = head_;
        SnakeBodySegment current_value;

        while (current_node) {
            current_value = current_node->data_;
            current_node = current_node->next_;

            snake_value->push_back(current_value);
        }

        return *snake_value;
    }

    bool LinkedList::empty() const {
        return false;
    }

    std::ostream &snakelinkedlist::operator<<(std::ostream &os, const LinkedList &list) {
//        ListNode first_node = *list.head_;
//        SnakeBodySegment first_value = first_node.data_;

        os << list.head_->data_;

        return os;
    }

    bool LinkedList::operator==(const LinkedList &rhs) const {
        if (rhs.head_ == nullptr) {
            return true;
        }

        ListNode *current_node = rhs.head_;
        SnakeBodySegment compare_value = current_node->data_;
        current_node = current_node->next_;

        while (current_node) {
            if (current_node->data_ != compare_value) {
                return false;
            }
            current_node = current_node->next_;
        }
        return true;
    }

    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
        std::vector<SnakeBodySegment> snake_value1 = lhs.GetVector();
        std::vector<SnakeBodySegment> snake_value2 = lhs.GetVector();


        if (snake_value1 == snake_value2) {
            return false;
        }
        return true;
    }
} // namespace snakelinkedlist
