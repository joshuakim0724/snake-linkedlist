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
    LinkedList::LinkedList(const LinkedList &source) {
        if (source.head_) {
            ListNode *current_node = source.head_;
            head_ = new ListNode(current_node->data_);
            current_node = current_node->next_;

            while (current_node) {
                this->push_back(current_node->data_);
                current_node = current_node->next_;
            }
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
        clear();
    }

    // Copy assignment operator
    LinkedList &LinkedList::operator=(const LinkedList &source) {
        if (this == &source) {
            return *this;
        }

        delete head_;
        head_ = nullptr;
        if (source.head_) {
            ListNode *current_node = source.head_;
            head_ = new ListNode(current_node->data_);
            current_node = current_node->next_;

            while (current_node) {
                this->push_back(current_node->data_);
                current_node = current_node->next_;
            }
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
        ListNode *current_node = source.head_;
        ListNode *next_node;

        while (current_node) {
            next_node = current_node->next_;

            current_node = nullptr;
            delete current_node;

            current_node = next_node;
        }

        return *this;
    }

    //--------------------------------------------Modifiers Methods-----------------------------------------------------

    /*
     * This function will add a new element to the linked list at the front of the list.
     * @param value is the value which to push to the front of the list
     */
    void LinkedList::push_front(SnakeBodySegment value) {
        auto *new_node = new ListNode(value);
        new_node->next_ = head_;
        head_ = new_node;
    }

    /**
     *This function will add a new element to the linked list at the back of the list.
     * @param value is the value which will push to the end of the list
     */
    void LinkedList::push_back(SnakeBodySegment value) {
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
    }

    /**
     * This will remove the front element from the linked list and delete the allocated data.
     * If the list is empty it will do nothing.
     */
    void LinkedList::pop_front() {

        // List is empty
        if (head_ == nullptr) {
            return;
        }

        ListNode *temp = head_;
        head_ = head_->next_;
        delete temp;
    }

    /**
     * This will remove the back element from the linked list and delete the allocated data.
     * If the list is empty it will do nothing.
     */
    void LinkedList::pop_back() {

        // List is empty
        if (head_ == nullptr) {
            return;
        }

        // Base case if list is size 1
        if (size() == 1) {
            head_ = nullptr;
            delete head_;
            return;
        }

        ListNode *remove_node = head_;

        while (remove_node->next_ && remove_node->next_->next_) {
            remove_node = remove_node->next_;
        }

        remove_node->next_ = nullptr;
        delete remove_node->next_;
    }

    /**
     * Remove the Nth element from the list deleting the allocated data.
     * If the list does not contain a Nth element this function will do nothing.
     * @param n is the element number
     */
    void LinkedList::RemoveNth(int n) {

        // Checks to see if linked list is null or N is an invalid number
        if (head_ == nullptr || n > size() - 1) {
            std::cout << "Could not remove Nth index" << std::endl;
            return;
        }

        // Base case
        if (n == 0) {
            pop_front();
            return;
        }

        int index = 0;
        ListNode *remove_node = head_;
        ListNode *head_connector;

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
    }

    /**
     *  Delete all data in the linked list returning the list to the same state as the default constructor.
     */
    void LinkedList::clear() {
        int length = size();

        while (length > 0) {
            pop_back();
            length = length - 1;
        }
    }

    //----------------------------------------------Accessors-----------------------------------------------------------

    /**
     * Return a copy of the SnakeBodySegment element sorted in the first node of the list.
     * @return the SnakeBodySegment of the head value
     */
    SnakeBodySegment LinkedList::front() const {

        // If LinkedList doesn't exist, return SnakeBodySegment base case
        if (size() == 0) {
            return {};
        }
        return head_->data_;
    }

    /**
     * Return a copy of the SnakeBodySegment element sorted in the last node of the list.
     * @return the SnakeBodySegment of the tail value
     */
    SnakeBodySegment LinkedList::back() const {

        // If LinkedList doesn't exist, return SnakeBodySegment base case
        if (size() == 0) {
            return {};
        }

        ListNode *current_node = head_;

        // Gets the last node
        while (current_node->next_) {
            current_node = current_node->next_;
        }
        return current_node->data_;
    }

    /**
     * Return the number of elements in the list.
     * @return the number of LinkedNodes
     */
    int LinkedList::size() const {
        int size = 0;
        ListNode *current_node = head_;

        while (current_node) {
            size++;
            current_node = current_node->next_;
        }
        delete current_node;
        return size;
    }

    /**
     * @return - a vector that contains all the elements in the list
     */
    std::vector<SnakeBodySegment> LinkedList::GetVector() const {
        std::vector<SnakeBodySegment> *snake_value = new std::vector<SnakeBodySegment>();

        // If LinkedList doesn't exist return empty vector;
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

        delete current_node;

        return *snake_value;
    }

    /**
     * @return true is list is empty otherwise false
     */
    bool LinkedList::empty() const {
        return size() == 0;
    }

    /**
     * This should print the SnakeBodySegment elements stored in the list
     * using the « operator from the SnakeBodySegment class to print the list.
     */
    std::ostream &snakelinkedlist::operator<<(std::ostream &os, const LinkedList &list) {
        ListNode *current_node = list.head_;

        while (current_node) {
            os << current_node->data_;
            current_node = current_node->next_;

            // If it's not the last node print out ', '
            if (current_node) {
                os << ", ";
            }
        }
        return os;
    }

    /**
     * This function will compare the list
     * element by element returning true if they are all equal otherwise it will return false
     */
    bool LinkedList::operator==(const LinkedList &rhs) const {

        // If both lists are nullptr
        if (this->head_ == nullptr && rhs.head_ == nullptr) {
            return true;
        }

        // If lists have different sizes
        if (this->size() != rhs.size()) {
            return false;
        }

        ListNode *this_runner = this->head_;
        ListNode *other_runner = rhs.head_;

        while (this_runner) {

            //If the SnakeData is ever not the same, return false
            if (this_runner->data_ != other_runner->data_) {
                return false;
            }
            this_runner = this_runner->next_;
            other_runner = other_runner->next_;
        }
        return true;
    }

    /**
     * This function will compare the list element by element
     * returning false if they are all equal otherwise it will return true.
     */
    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
        std::vector<SnakeBodySegment> snake_value1 = lhs.GetVector();
        std::vector<SnakeBodySegment> snake_value2 = rhs.GetVector();

        return !(snake_value1 == snake_value2);
    }

    // Accidentally made it so it checked if all the elements in a LinkedList were the same
//    bool LinkedList::operator==(const LinkedList &rhs) const {
//        if (rhs.head_ == nullptr) {
//            return true;
//        }
//
//        ListNode *current_node = rhs.head_;
//        SnakeBodySegment compare_value = current_node->data_;
//        current_node = current_node->next_;
//
//        while (current_node) {
//            if (current_node->data_ != compare_value) {
//                return false;
//            }
//            current_node = current_node->next_;
//        }
//
//        return true;
//    }
} // namespace snakelinkedlist
