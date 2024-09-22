#include "book.h"

Book::Book() : pages(0), Document() {}
Book::Book(string name, string author, int yearofp, int librarycode, int isbn, bool status, int pages)
    : Document(name, author, yearofp, librarycode, isbn, status) {}

void Book::setpages(int pages)
{
    this->pages = pages;
}
int Book:: getpages()
{
    return pages;
}





void Book::prinbookinfo(){
    cout << "Name: " << getname() << endl;
    cout << "Author: " << getauthor() << endl;
    cout << "Year of Publication: " << getyearofp() << endl;
    cout << "Library Code: " << getlibrarycode() << endl;
    cout << "ISBN: " << getisbn() << endl;
    cout << "Status: " << (getstatus() ? "Available" : "Unavailable") << endl;
}



