/*
  This is an updated version of the student list project described below that implements
  linked lists over vectors.
  
  This program serves as a database for students. The user may add and remove students, as
  well as see the complete list of students they've entered. Each student has a first and last
  name, as well as an ID number and a GPA (0.0-5.0).

  Author: Luca Ardanaz
  Last Updated: 9/26/2025
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Node* &head);
void printStudents(Node* current, Node* &head);
void removeStudent(Node* &head);
void cinReset();

void insertStudentByID(Node* s, Node* previous, Node* current, Node* &head);
void removeStudentByID(int ID, Node* previous, Node* current, Node* &head);
void printAverageGPA(double sumX, double n, Node* current, Node* &head);

int main() {

  Node* head = NULL;
  vector<Student*> students;
  char input[20];

  //This loop will run until the user enters "QUIT"
  do {
    //ask for user input
    cout << endl << endl << endl << "Enter command (type \"HELP\" for all commands):" << endl; 
    cin.get(input, 20);
    cinReset();
    
    cout << endl;
    
    if (strcmp(input, "HELP") == 0) {
      //show all the valid commands
      cout << "List of commands:" << endl;
      cout << " - ADD: Add a new student to the database." << endl;
      cout << " - PRINT: Prints out all of the students in the database." << endl;
      cout << " - DELETE: Remove a student from the database." << endl;
      cout << " - AVERAGE: Calculates the average GPA of all the students." << endl;
      cout << " - QUIT: Close the program" << endl;
    }
    else if (strcmp(input, "ADD") == 0) {
      //add a student
      addStudent(head);
    }
    else if (strcmp(input, "PRINT") == 0) {
      //show the complete list of students
      printStudents(head, head);
    }
    else if (strcmp(input, "DELETE") == 0) {
      //remove a student
      removeStudent(head);
    }
    else if (strcmp(input, "AVERAGE") == 0) {
      //calculate average GPA
      printAverageGPA(0, 0, head, head);
    }
    
  } while (strcmp(input, "QUIT") != 0);
  
  cout << "Ending program." << endl;
  

  return 0;
}

void addStudent(Node* &head) {

  char* firstName = new char[20];
  char* lastName = new char[20];
  int ID = 0;
  double GPA = 0;
  
  //asks for first name
  cout <<"Adding a new student..." << endl;
  cout << "Enter first name:" << endl;
  cin.get(firstName, 20);
  cin.get();

  //asks for last name
  cout << "Enter last name:" << endl;
  cin.get(lastName, 20);
  cin.get();

  //gets student id and verifies that its valid
  do {
    if (cin.fail()) {
      cinReset();
      
    }
    cout << "Enter student ID:" << endl;
    cin >> ID;
  } while (cin.fail() || ID <= 0);


  //gets student GPA and verifies its valid
  do {
    if (cin.fail()) {
      cinReset();
      
    }
    cout << "Enter GPA:" << endl;
    cin >> GPA;
  } while (cin.fail() || GPA < 0 || GPA > 5.0);

  cinReset();
 
  //adds student to linked list
  Node* node = new Node(new Student(firstName, lastName, ID, GPA));
 
  //figures out where to place the student so that it is in order by ID number
  insertStudentByID(node, NULL, head, head);
  
}

void insertStudentByID(Node* s, Node* previous, Node* current, Node* &head) {
  //if there is no head, make it the new head
  if (head == NULL) {
    head = s;
    return;
  }


  if (s -> getStudent() -> getID() > current -> getStudent() -> getID()) {
    //means the node has to be placed further down the list
    //go to the next element if there is one

    if (current -> getNext() != NULL) {
      insertStudentByID(s, current, current -> getNext(), head);
    }
    else {
      //there is no list left, just add it to the end
      current -> setNext(s);  
    }
  }
  else {
    //means the node has to be placed here

    //if there is no previous, assign it as the new head and bump everything back
    if (previous == NULL) {
      head = s;
      s -> setNext(current);
    }
    //link the previous to it and it to the current
    else {
      previous -> setNext(s);
      s -> setNext(current);
    }
  }
  

  
}

void printStudents(Node* current, Node* &head) {
  //if there aren't any students, tell the user
  if (head == NULL) {
    cout << "There aren't any students yet" << endl;
    return;
  }
  
  if (current == head) {
    //means its the first item of the list
    cout << "List of students:" << endl;
  }

  if (current != NULL) {
    /*
      The confusing looking logic with the modulos fixes the issue where numbers like 4.00 are displayed as 4.
      Essentially it just adds the ".00" to 4 or similarly a "0" to 3.2. That way the precision always shows the same.
    */
    cout << current -> getStudent() -> getFirstName() << " " << current -> getStudent() -> getLastName() << ", " << current -> getStudent() -> getID() << ", ";
    cout << fixed << setprecision(2) << current -> getStudent() -> getGPA() << endl;

    printStudents(current -> getNext(), head);
  }
}

void removeStudent(Node* &head) {

  //if the linked list is empty, tell the user and exit
  if (head == NULL) {
    cout << "There aren't any students yet." << endl;
    return;
  }
  
  //asks for ID and saves it
  //keeps asking till it gets an int
  int id = 0;
  do {
    if (cin.fail()) {
      cinReset();
    }
    cout << "Enter the student ID of the student to remove:" << endl;
    cin >> id;
  } while (cin.fail());

  cinReset();

  removeStudentByID(id, NULL, head, head);
}

void removeStudentByID(int ID, Node* previous, Node* current, Node* &head) {
  //if the list is empty, return
  if (head == NULL) {
    return;
  }

  //checks if the current node matches
  if (current -> getStudent() -> getID() == ID) {
    //head deletion case
    if (current == head) {
      head = current -> getNext();
    }
    
    //tail deletion case
    else if (current -> getNext() == NULL) {
      previous -> setNext(NULL);
    }
    
    //body deletion case
    else {
      previous -> setNext(current -> getNext());
    }

    delete current;
    return;
  }

  //if the node isn't the last one, continue search
  if (current -> getNext() != NULL) {
    removeStudentByID(ID, current, current -> getNext(), head);
  }

  
}

void printAverageGPA(double sumX, double n, Node* current, Node* &head) {
  //if the list is empty, tell the user
  if (head == NULL) {
    cout << "There aren't any students" << endl;
    return;
  }

  //if this is the first node, make sure that sum and n are both reset
  if (current == head) {
    sumX = 0;
    n = 0;
  }

  //add the gpa to sumX and add 1 to n to track the number of students
  sumX += current -> getStudent() -> getGPA();
  n++;

  //checks if this is the last student
  if (current -> getNext() == NULL) {
    //print out the average and finish
    double average = sumX / n;
    cout << average;
    cout << "Average GPA: ";
    cout << fixed << setprecision(2) << average << endl;
  }
  else {
    //go to the next student
    printAverageGPA(sumX, n, current -> getNext(), head);
  }
  
}

//this clears all errors with cin so that cin always works as expected.
void cinReset() {
  cin.clear();
  cin.ignore(10000, '\n');
}
