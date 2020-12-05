#ifndef ECE275LIB_CONTAINERS_LIST_H
#define ECE275LIB_CONTAINERS_LIST_H
#include <iostream>

// AUTHOR: Nicolas Blanchard
// COURSE: ECE275
// INSTRUCTOR: Fuhrman
// DATE: 12/03/20
// SUMMARY:
//          This file implements a custom List data structure.
//          The List is implemented as a templated class, constructed
//          of singly linked Nodes (another templated class). For
//          documentation on the member functions, see the class
//          definition below.
//          Because the List class is templated, the List can be used
//          with any data type, including user defined data types.

namespace ECE275Lib::containers {


    /*********************************************/
    //                  LIST                     //
    /*********************************************/

    // Forward declaration of Node class
    template <typename T> class Node;

    template <typename T> class List
    {
    public:
        // Default constructor
        List();
        // Parameterized constructor
        List(unsigned int N);
        // Traverse function
        Node<T>* traverse(unsigned int i);
        // Insert function
        void insert(unsigned int i, T d);
        // Overloaded insert function
        void insert(unsigned int i, List<T>& other);
        // Size function
        unsigned int size();
        // Back function
        Node<T>* back();
        // Front function
        Node<T>* front();
        // Push back function
        void push_back(T in);
        // Access function
        T at(unsigned int i);
        // Remove function
        void remove(unsigned int i);
        // Overloaded remove function
        void remove(unsigned int i, unsigned int e);
        // Assign function
        void assign(unsigned int i, T d);

        // Pointer to head node
        Node<T>* head;

    };

    // No parameters, default constructor for the List class.
    template <typename T>
    List<T>::List() {
        this->head = nullptr;
    }

    // Parameterized constructor for the List class. Will initialize
    // the list with N nodes, where N is an unsigned integer parameter.
    template <typename T>
    List<T>::List(unsigned int N) {
        Node<T>* temp = new Node<T>;
        this->head = temp;
        for (unsigned int i = 0; i < N - 1; i++) {
            temp->next = new Node<T>;
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    // No parameters, will return the length of the list as  an
    // unsigned integer value.
    template <typename T>
    unsigned int List<T>::size() {
        unsigned int length = 0;
        Node<T>* current_node = this->head;
        while (current_node != nullptr) {
            length += 1;
            current_node = current_node->next;
        }
        return length;
    }

    // No parameters, will return a pointer to the head (first)
    // node of the list.
    template <typename T>
    Node<T>* List<T>::front() {
        return this->head;
    }

    // No parameters, will return a pointer to the back (last)
    // node of the list.
    template <typename T>
    Node<T>* List<T>::back() {
        Node<T>* temp = this->head;
        if (temp == nullptr) {
            return temp;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    // Will return a pointer to the List node at index i, where
    // i is an unsigned integer parameter.
    template <typename T>
    Node<T>* List<T>::traverse(unsigned int i) {
        unsigned int index = 0;
        Node<T>* temp = this->head;

        // If the list is empty, return NULL
        if (temp == nullptr) {
            return temp;
        }

        // Otherwise, traverse until we reach the correct index or the end
        while (temp->next != nullptr && index < i) {
            temp = temp->next;
            index += 1;
        }
        return temp;
    }

    // Will insert a new node at index i with data d, where i is an
    // unsigned integer parameter and d is a templated parameter.
    template <typename T>
    void List<T>::insert(unsigned int i, T d) {
        Node<T>* temp = new Node<T>;

        // If we are inserting at the beginning of the list (includes when the list is empty)
        if (i == 0) {
            temp->next = this->head;
            this->head = temp;
        }
        // If we are inserting in the middle of the list (including the end)
        else {
            Node<T>* previous_node = this->traverse(i-1);
            temp->next = previous_node->next;
            previous_node->next = temp;
        }
        temp->data = d;
    }

    // Will add a new node to the end of the List with data in, where
    // in is a templated parameter.
    template <typename T>
    void List<T>::push_back(T in) {
        this->insert(this->size(), in);
        return;
    }

    // Will return the value stored by the List at the i'th index, where
    // i is an unsigned int parameter.
    template <typename T>
    T List<T>::at(unsigned int i) {
        Node<T>* temp = this->traverse(i);
        return temp->data;
    }

    // Will remove the List node at index i, where i is an unsigned
    // integer parameter.
    template <typename T>
    void List<T>::remove(unsigned int i) {

        if (i < 0) {
            std::cout << "Invalid remove operation!" << std::endl;
        }
        else if (this->head == nullptr) {
            // The list is empty; do nothing
            return;
        }
        else if (i == 0) {
            // Delete head node
            Node<T>* current_node = this->head;
            this->head = current_node->next;
            delete current_node;
        }
        else {
            Node<T>* current_node = this->traverse(i);
            Node<T>* previous_node = this->traverse(i - 1);
            previous_node->next = current_node->next;
            delete current_node;
        }
    }

    // Will remove all of the List nodes between i and e, where i and e
    // are both unsigned integer parameters.
    template <typename T>
    void List<T>::remove(unsigned int i, unsigned int e) {
        for (unsigned int j = i; j <= e; j++) {
            this->remove(i);
        }
    }

    // Will insert the list other into this List, beginning at index i,
    // where other is a templated list parameter and i is an unsigned
    // integer parameter.
    template <typename T>
    void List<T>::insert(unsigned int i, List<T>& other) {
        // If inserting at the beginning
        if (i == 0) {
            other.back()->next = this->head;
            this->head = other.front();
        }
        else {
            Node<T>* previous_node = this->traverse(i - 1);
            (other.back())->next = previous_node->next;
            previous_node->next = other.front();
        }
    }

    // Will assign the value of the List at index i to d, where
    // i is an unsigned integer parameter and d is a templated parameter.
    template <typename T>
    void List<T>::assign(unsigned int i, T d) {
        Node<T>* current_node = this->traverse(i);
        current_node->data = d;
    }


    /*********************************************/
    //                  NODE                     //
    /*********************************************/


    template <typename T> class Node
    {
    public:
        // Default constructor
        Node();
        // Data
        T data;
        // Pointer to the next node
        Node<T>* next;
    };

    // Default constructor for the Node class.
    template <typename T>
    Node<T>::Node() {
        this->next = nullptr;
    }

}

#endif
