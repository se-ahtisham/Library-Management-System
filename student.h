#pragma once
#include"user.h"

class Student : public User {
public:
    Student();
    Student(string name, int id, string email);

    void printStudentDetails();
};