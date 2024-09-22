
#include"facultyArray.h"



FacultyArray::FacultyArray(int capacity) : capacity(capacity), size(0) {
    faculties = new Faculty[capacity];
}

FacultyArray::~FacultyArray() {
    delete[] faculties;
}

void FacultyArray::addFaculty(Faculty faculty) {
    for (int i = 0; i < size; i++) {
        if (faculty.getId() == faculties[i].getId()) {
            cout << "Faculty already exists!" << endl;
            return;
        }
    }

    if (size < capacity) {
        faculties[size++] = faculty;
    }
    else {
        cout << "Array is full. Cannot add more faculty members." << endl;
    }
}

bool FacultyArray::searchFacultyById(int id) {
    for (int i = 0; i < size; i++) {
        if (faculties[i].getId() == id) {
            return true;
        }
    }
    return false;
}

void FacultyArray::deleteFacultyById(int id) {
    for (int i = 0; i < size; i++) {
        if (faculties[i].getId() == id) {
            for (int j = i; j < size - 1; ++j) {
                faculties[j] = faculties[j + 1];
            }
            --size;
            return;
        }
    }
}

void FacultyArray::updateFacultyById(int id, Faculty faculty) {
    for (int i = 0; i < size; i++) {
        if (faculties[i].getId() == id) {
            faculties[i] = faculty;
            return;
        }
    }
}

void FacultyArray::printAllFaculties() {
    for (int i = 0; i < size; i++) {
        faculties[i].printFacultyDetails();
        cout << "----------------------------------------------" << endl;
    }
}