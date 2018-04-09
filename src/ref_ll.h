#ifndef LL_H
#define LL_H

#include <iostream>
#include <vector>

namespace snakelinkedlist {

// Template linked list class
template<typename ElementType>
class LinkedList {

    // Internal node for linked list.
    struct ListNode {
        ListNode() : next_(nullptr) {};
        ListNode(ElementType v) : next_(nullptr), data_(v) {};
        ListNode *next_;
        ElementType data_;
    };

    ListNode *head_;
    int size_;
public:
    LinkedList();                                                   // Default constructor
    explicit LinkedList(const std::vector<ElementType> &values);    // Initilize from vector

    // Big 5
    LinkedList(const LinkedList& source);                                           // Copy constructor
    LinkedList(LinkedList&& source) noexcept;                                       // Move constructor
    ~LinkedList();                                                                  // Destructor
    LinkedList<ElementType>& operator=(const LinkedList<ElementType>& source);      // Copy assignment operator
    LinkedList<ElementType>& operator=(LinkedList<ElementType>&& source) noexcept;  // Move assignment operator

    void push_front(ElementType value);         // Push value on front
    void push_back(ElementType value);          // Push value on back
    ElementType front() const;                  // Access the front value
    ElementType back() const;                   // Access the back value
    void pop_front();                           // remove front element
    void pop_back();                            // remove back element
    int size() const;                           // return number of elements
    std::vector<ElementType> GetVector() const; // return a vector of the values
    bool empty() const;                         // check if empty
    void clear();                               // clear the contents
    void RemoveNth(int n);                      // remove the Nth element from the front 0 indexed
    bool operator==(const LinkedList<ElementType> &rhs) const;

    // Iterator
    class Iterator : std::iterator<std::forward_iterator_tag, ElementType> {
        ListNode *current_;
        friend LinkedList<ElementType>;
    public:
        Iterator() : current_(nullptr) {};
        Iterator& operator++();
        ElementType& operator*();
        bool operator!=(const Iterator& other);
    };

    Iterator begin();
    Iterator end();
};

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list);

// needed for template instantiation
#include "ll.cpp"

} // namespace snakelinkedlist
#endif //LL_H