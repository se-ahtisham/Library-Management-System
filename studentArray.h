#pragma once
#include"Student.h"

class StudentArray {
private:
    int capacity;
    int size;
    Student* students;

public:
    StudentArray(int capacity);
    ~StudentArray();

    void addStudent( Student student);
    bool searchStudentById(int id);
    void deleteStudentById(int id);
    void updateStudentById(int id, Student student);
    void printAllStudents();
};