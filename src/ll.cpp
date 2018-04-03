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
    // Memeory leak testing
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
            head_ = new ListNode(*source.head_);
        }
        return *this;
//        this->head_ = source.head_;
//        return *this;
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
        auto *new_node = new ListNode(value);
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

    void LinkedList::pop_front() {
        if (head_ == nullptr) {
            return;
        }

        ListNode *temp = head_;
        head_ = head_->next_;
        delete temp;
    }

    void LinkedList::pop_back() {
        if (head_ == nullptr) {
            return;
        }

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

    void LinkedList::RemoveNth(int n) {
        if (head_ == nullptr || n > size() - 1) {
            std::cout << "Could not remove Nth index" << std::endl;
            return;
        }

        if (n == 0) {
            pop_front();
            return;
        }

        int index = 0;
        ListNode *remove_node = head_;
        ListNode *head_connector;

        while (index != n) {
            index++;
            head_connector = remove_node;
            remove_node = remove_node->next_;
        }

        ListNode *tail_connector = remove_node->next_;
        remove_node = nullptr;
        delete remove_node;

        head_connector->next_ = tail_connector;
    }

    void LinkedList::clear() {
        int length = size();

        while (length > 0) {
            pop_back();
            length = length - 1;//size();
        }
    }
    //----------------------------------------------Accessors-----------------------------------------------------------

    SnakeBodySegment LinkedList::front() const {
        if (size() == 0) {
            return {};
        }
        return head_->data_;
    }

    SnakeBodySegment LinkedList::back() const {
        if (size() == 0) {
            return {};
        }

        ListNode *current_node = head_;

        while (current_node->next_) {
            current_node = current_node->next_;
        }
        return current_node->data_;
    }

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

        delete current_node;

        return *snake_value;
    }

    bool LinkedList::empty() const {
        if (size() == 0) {
            return true;
        }
        return false;
    }

    std::ostream &snakelinkedlist::operator<<(std::ostream &os, const LinkedList &list) {
        ListNode *current_node = list.head_;

        while (current_node) {
            os << current_node->data_;
            current_node = current_node->next_;
            if (current_node) {
                os << ", ";
            }
        }

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
