/*
Dylan Waters
Last updated 1/6/2025

Name : Linked Lists 1

Description : Node implementation to support linked lists for students.
*/
#include "Node.h"

// Default constructor
Node::Node() {
    this->next = nullptr;
    student = nullptr;
}

// Constructor that takes student pointer
Node::Node(Student* student) {
    this->student = student;
    this->next = nullptr;
}

// Linked list set next pointer
void Node::setNext(Node* next) {
    this->next = next;
}

// Linked list get next pointer
Node* Node::getNext() {
    return this->next;
}

// Print node contents which calls student print
void Node::print() {
    if (this->student != nullptr) {
        this->student->print();
    } else {
        cout << "Empty node" << endl;
    }
}
