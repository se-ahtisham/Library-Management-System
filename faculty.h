#pragma once

#include"user.h"



class Faculty : public User {
public:
    Faculty();
    Faculty(string name, int id, string email);

    void printFacultyDetails();
};