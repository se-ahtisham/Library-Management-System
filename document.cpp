#include "Document.h"


Document::Document() : name(""), author(""), yearofp(0), librarycode(0), isbn(0), status(true) {}

Document::Document(string name, string author, int yearofp, int librarycode, int isbn, bool status)
    : name(name), author(author), yearofp(yearofp), librarycode(librarycode), isbn(isbn), status(status) {}

void Document::setname( string name1) {
    name = name1;
}

void Document::setauthor(string author1) {
    author = author1;
}

void Document::setyearofp(int yearofp1) {
    yearofp = yearofp1;
}

void Document::setlibrarycode(int librarycode1) {
    librarycode = librarycode1;
}

void Document::setisbn(int isbn1) {
    isbn = isbn1;
}

void Document::setstatus(bool status1) {
    status = status1;
}

string Document::getname()  {
    return name;
}

string Document::getauthor() {
    return author;
}

int Document::getyearofp() {
    return yearofp;
}

int Document::getlibrarycode() {
    return librarycode;
}

int Document::getisbn() {
    return isbn;
}

bool Document::getstatus()  {
    return status;
}
