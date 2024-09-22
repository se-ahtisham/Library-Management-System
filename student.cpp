#include"Student.h"


Student::Student(): User() {}
Student::Student(string name, int id, string email) : User(name, id, email) {}

void Student::printStudentDetails() {
    cout << "Student ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Email: " << email << endl;
}