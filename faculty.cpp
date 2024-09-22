#include"faculty.h"

Faculty::Faculty() : User() {}
Faculty::Faculty(string name, int id, string email) : User(name, id, email) {}

void Faculty::printFacultyDetails() {
    cout << "Faculty Name: " << name << endl;
}