/*
Dylan Waters
Last updated 1/6/2025

Name : Linked Lists 1

Description : Adding node to support linked lists for students.
*/
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

#ifndef NODE_H
#define NODE_H

// class defintion for Node to support linked lists for students
class Node
{
public:
    // Constructors
    Node();
    Node(Student* student);

    // Destructor
    ~Node() {}

    // methods for adding and getting nodes for linked list
    void setNext(Node* next);
    Node* getNext();

    // Methods to set and get student data associated with node
    Student* getStudent() { return this->student; }
    void  setStudent(Student* student) { this->student = student; }

    // method to print contents of node
    void print();
private:
    // Next pointer for linked list
    Node* next;
    
    Student* student;
};

#endif
