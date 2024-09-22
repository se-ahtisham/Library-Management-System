
#include"adminArray.h"


AdminArray::AdminArray(int capacity) : capacity(capacity), size(0) {
    admins = new Admin[capacity];
}

AdminArray::~AdminArray() {
    delete[] admins;
}

void AdminArray::addAdmin(Admin admin) {
    for (int i = 0; i < size; i++) {
        if (admin.getId() == admins[i].getId()) {
            cout << "Admin already exists!" << endl;
            return;
        }
    }

    if (size < capacity) {
        admins[size++] = admin;
    }
    else {
        cout << "Array is full. Cannot add more admins." << endl;
    }
}

bool AdminArray::searchAdminById(int id) {
    if (size == 0)
    {
        cout << "Empty" << endl;
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (admins[i].getId() == id) {
            return true;
        }
    }
    return false;
}

void AdminArray::deleteAdminById(int id) {
    if (size == 0)
    {
        cout << "Empty" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        if (admins[i].getId() == id) {
            for (int j = i; j < size - 1; j++) {
                admins[j] = admins[j + 1];
            }
            --size;
            cout << "Deleted Successful" << endl;
            return;
        }
    }
}

void AdminArray::updateAdminById(int id, Admin admin) {
    if (size == 0)
    {
        cout << "Empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        if (admins[i].getId() == id) {
            admins[i] = admin;
            cout << "Updated Successful" << endl;
            return;
        }
    }
}

void AdminArray::printAllAdmins() {
    if (size == 0)
    {
        cout << "Empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        admins[i].printAdminDetails();
        cout << "----------------------------------------------" << endl;
    }
}
