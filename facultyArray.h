#pragma once
#include"faculty.h"


class FacultyArray {
private:
    int capacity;
    int size;
    Faculty* faculties;

public:
    FacultyArray(int capacity);
    ~FacultyArray();

    void addFaculty( Faculty faculty);
    bool searchFacultyById(int id);
    void deleteFacultyById(int id);
    void updateFacultyById(int id,Faculty faculty);
    void printAllFaculties();
};
