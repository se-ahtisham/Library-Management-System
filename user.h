#pragma once
#include "Document.h"

class User {
protected:
    string name;
    int id;
    string email;

public:
    User();
    User(string name, int id, string email);

    string getName();
    int getId();
    string getEmail();

    void setName(string name);
    void setId(int id);
    void setEmail(string email);
};