
#include"studentArray.h"

StudentArray::StudentArray(int capacity) : capacity(capacity), size(0) {
    students = new Student[capacity];
}

StudentArray::~StudentArray() {
    delete[] students;
}

void StudentArray::addStudent(Student student) {
    for (int i = 0; i < size; i++) {
        if (student.getId() == students[i].getId()) {
            cout << "Student already exists!" << endl;
            return;
        }
    }

    if (size < capacity) {
        students[size++] = student;
    }
    else {
        cout << "Array is full. Cannot add more students." << endl;
    }
}

bool StudentArray::searchStudentById(int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].getId() == id) {
            return true;
        }
    }
    return false;
}

void StudentArray::deleteStudentById(int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].getId() == id) {
            for (int j = i; j < size - 1; ++j) {
                students[j] = students[j + 1];
            }
            --size;
            return;
        }
    }
}

void StudentArray::updateStudentById(int id,Student student) {
    for (int i = 0; i < size; i++) {
        if (students[i].getId() == id) {
            students[i] = student;
            return;
        }
    }
}

void StudentArray::printAllStudents() {
    for (int i = 0; i < size; i++) {
        students[i].printStudentDetails();
        cout << "----------------------------------------------" << endl;
    }
}