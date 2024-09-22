#include "magazine.h"

Magazine::Magazine() : issueNumber(0), Document() {}

Magazine::Magazine(string name, string author, int yearofp, int librarycode, int isbn, bool status, int issueNumber) {}

void Magazine::setissueNumber(int issueNumber1) {
    issueNumber = issueNumber1;
}

int Magazine::getissueNumber() {
    return issueNumber;
}

void Magazine::printmagazineinfo() {
    cout << "Name: " << getname() << endl;
    cout << "Author: " << getauthor() << endl;
    cout << "Year of Publication: " << getyearofp() << endl;
    cout << "Library Code: " << getlibrarycode() << endl;
    cout << "ISBN: " << getisbn() << endl;
    cout << "Status: " << (getstatus() ? "Available" : "Unavailable") << endl;
    cout << "Issue Number: " << getissueNumber() << endl;
}
