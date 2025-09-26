#include "Node.h"

Node::Node(Student* nStudent) {
  student = nStudent;
  next = NULL;
}

Node::~Node() {
  cout << "---NODE DESTRUCTOR CALLED" << endl;
  delete student;
  next = NULL;
  cout << "---NODE DESTRUCTOR COMPLETED" << endl;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* nNext) {
  next = nNext;
}

Node* Node::getNext() {
  return next;
}
