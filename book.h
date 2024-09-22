#pragma once
#include "document.h"

class Book : public Document {
protected:
    int pages;

public:
    Book();
    Book(string name, string author, int yearofp, int librarycode, int isbn, bool status, int pages);

    void setpages(int pages1);
    int getpages();


   
    void prinbookinfo();    // Status false and true
};
