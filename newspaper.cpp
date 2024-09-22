#include "Newspaper.h"

Newspaper::Newspaper() : edition(""), Document() {}

Newspaper::Newspaper(string name, string author, int yearofp, int librarycode, int isbn, bool status, string edition) {}

void Newspaper::setedition(string edition1) {
    edition = edition1;
}

string Newspaper::getedition() {
    return edition;
}

void Newspaper::printnewspaperinfo() {
    cout << "Name: " << getname() << endl;
    cout << "Author: " << getauthor() << endl;
    cout << "Year of Publication: " << getyearofp() << endl;
    cout << "Library Code: " << getlibrarycode() << endl;
    cout << "ISBN: " << getisbn() << endl;
    cout << "Status: " << (getstatus() ? "Available" : "Unavailable") << endl;
    cout << "Edition: " << getedition() << endl;
}

