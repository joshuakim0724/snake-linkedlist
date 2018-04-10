#include <utility>
//#include "ll.h"
#include "ref_ll.h"

template<typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : head_(nullptr), tail_(nullptr), size_(0) {
    if (values.empty()) {
        head_ = nullptr;
        return;
    }

    for (auto value : values) {
        push_back(value);
    }
}

// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {
    if (source.head_) {

        size_ = 1;

        // Copying Head
        ListNode *current_node = source.head_;
        head_ = new ListNode(current_node->data_);
        current_node = current_node->next_;

        // Copying rest of nodes
        while (current_node) {
            this->push_back(current_node->data_);
            tail_ = current_node;
            current_node = current_node->next_;
            size_++;
        }
    } else {
        head_ = nullptr;
        tail_ = nullptr;
    }
}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType> &&source) noexcept {
    head_ = source.head_;
    tail_ = source.tail_;
    size_ = 0;

    source.head_ = nullptr;
    source.tail_ = nullptr;
    source.size_ = 0;
}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    clear();
}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType> &LinkedList<ElementType>::operator=(const LinkedList<ElementType> &source) {
    if (this == &source) {
        return *this;
    }

    clear();

    if (source.head_) {
        size_ = 1;

        ListNode *current_node = source.head_;
        head_ = new ListNode(current_node->data_);
        current_node = current_node->next_;

        while (current_node) {
            this->push_back(current_node->data_);
            tail_ = current_node;
            current_node = current_node->next_;
            size_++;
        }
    }
    return *this;
}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType> &LinkedList<ElementType>::operator=(LinkedList<ElementType> &&source) noexcept {
    if (this == &source) {
        return *this;
    }

    delete head_;
    delete tail_;
    size_ = 0;

    head_ = source.head_;
    tail_ = source.tail_;
    size_ = source.size_;

    source.head_ = nullptr;
    source.tail_ = nullptr;
    source.size_ = 0;

    return *this;
}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
    auto *new_node = new ListNode(value);
    new_node->next_ = head_;
    head_ = new_node;

    size_++;
}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    ListNode *current_node = head_;

    if (current_node == nullptr) {
        push_front(value);
        return;
    }

    auto *tail_node = new ListNode(value);

    while (current_node->next_) {
        current_node = current_node->next_;
    }
    current_node->next_ = tail_node;

    tail_ = current_node->next_;

    size_++;
}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const {

    // If head doesn't have a value return base case;
    if (!head_ || size_ == 0) {
        return {};
    }
    return head_->data_;
}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    if (!head_ || size_ == 0) {
        return {};
    }
    ListNode *current_node = head_;
    while (current_node->next_) {
        current_node=current_node->next_;
    }
    return current_node->data_;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {

    // List is empty
    if (head_ == nullptr) {
        return;
    }

    ListNode *temp = head_;
    head_ = head_->next_;
    delete temp;

    size_--;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {

    // List is empty
    if (head_ == nullptr) {
        return;
    }

    // Base case if list is size 1
    if (size_ == 1) {
        head_ = nullptr;
        delete head_;
        size_--;
        return;
    }

    ListNode *remove_node = head_;

    while (remove_node->next_ && remove_node->next_->next_) {
        remove_node = remove_node->next_;
    }

    delete remove_node->next_;
    remove_node->next_ = nullptr;
    size_--;
}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
    return size_;
}

template<typename ElementType>
std::vector<ElementType> LinkedList<ElementType>::GetVector() const {
    auto *snake_value = new std::vector<ElementType>();

    // If LinkedList doesn't exist return empty vector;
    if (head_ == nullptr) {
        return *snake_value;
    }

    ListNode *current_node = head_;
    ElementType current_value;

    while (current_node) {
        current_value = current_node->data_;
        current_node = current_node->next_;

        snake_value->push_back(current_value);
    }

    return *snake_value;
}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
    return size_ == 0 || !head_;
}

template<typename ElementType>
void LinkedList<ElementType>::clear() {
    while (size_ > 0) { // Can also do while (size() > 0) and remove length variables
        pop_back();
    }
}

template<typename ElementType>
std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list) {
    std::vector<ElementType> element_vector = list.GetVector();

    for (int i = 0; i < element_vector.size(); i++) {
        os << element_vector[i];

        // If it's not the last node print out ', '
        if (i != element_vector.size() - 1) {
            os << ", ";
        }
    }
    return os;
}

template<typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {

    // Checks to see if linked list is null or N is an invalid number
    if (head_ == nullptr || n > size_ - 1) {
        std::cout << "Could not remove Nth index" << std::endl;
        return;
    }

    // Base case
    if (n == 0) {
        pop_front();
        return;
    }

    // If trying to remove the tail
    if (n == size_ - 1) {
        pop_back();
        return;
    }

    int index = 0;
    ListNode *remove_node = head_;
    ListNode *head_connector = nullptr;

    // This will get the node before and after the node that is going to get removed (head & tail)
    while (index != n) {
        index++;
        head_connector = remove_node;
        remove_node = remove_node->next_;
    }

    auto tail_connector = remove_node->next_;
    remove_node = nullptr;
    delete remove_node;

    head_connector->next_ = tail_connector;

    while (tail_connector) {
        tail_ = tail_connector;
        tail_connector = tail_connector->next_;
    }
}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

    // If both lists are nullptr
    if (!this->head_ && !rhs.head_) {
        return true;
    }

    // If lists have different sizes
    if (this->size_ != rhs.size_) {
        return false;
    }

    ListNode *this_runner = this->head_;
    ListNode *other_runner = rhs.head_;

    while (this_runner) {

        // If the SnakeData is ever not the same, return false
        if (this_runner->data_ != other_runner->data_) {
            return false;
        }
        this_runner = this_runner->next_;
        other_runner = other_runner->next_;
    }
    return true;
}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {
    return !(lhs == rhs);
}

// Goes through the for loop
template<typename ElementType>
typename LinkedList<ElementType>::Iterator &LinkedList<ElementType>::Iterator::operator++() {
    if (current_) {
        current_ = current_->next_;
    }

    return *this;
}

// Returns data the the things its on
template<typename ElementType>
ElementType &LinkedList<ElementType>::Iterator::operator*() {
    return current_->data_;
}

template<typename ElementType>
bool LinkedList<ElementType>::Iterator::operator!=(const LinkedList<ElementType>::Iterator &other) {
    return (current_ != other.current_);
}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::begin() {
    Iterator start;
    start.current_ = head_;
    return start;

}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::end() {
    Iterator stop;

    stop.current_ = nullptr;

    return stop;
}