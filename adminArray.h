#pragma once
#include"admin.h"
class AdminArray {
private:
    int capacity;
    int size;
    Admin* admins;

public:
    AdminArray(int capacity);
    ~AdminArray();

    void addAdmin(Admin admin);
    bool searchAdminById(int id);
    void deleteAdminById(int id);
    void updateAdminById(int id, Admin admin);
    void printAllAdmins();
};
