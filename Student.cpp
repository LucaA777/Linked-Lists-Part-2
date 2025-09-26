#include "Student.h"
#include <cstring>

Student::Student(const char nName[20], int nID) {
  name = new char[20];
  strcpy(name, nName);
  ID = nID;
}

Student::~Student() {
  delete name;
}

char* Student::getName() {
  return name;
}

int Student::getID() {
  return ID;
}
