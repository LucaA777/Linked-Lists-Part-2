#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
 public:
  Student(const char nName[20], int nID);
  ~Student();

  char* getName();
  int getID();

 private:
  char* name;
  int ID;
};

#endif
