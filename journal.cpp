#include "journal.h"


Journal::Journal() : Document(), volume("") {}

Journal::Journal(string name, string author, int yearofp, int librarycode, int isbn, bool status, string volume) {}

void Journal::setvolume(string volume1) {
    volume = volume1;
}

string Journal::getvolume() {
    return volume;
}

void Journal::printjournalinfo() {
    cout << "Name: " << getname() << endl;
    cout << "Author: " << getauthor() << endl;
    cout << "Year of Publication: " << getyearofp() << endl;
    cout << "Library Code: " << getlibrarycode() << endl;
    cout << "ISBN: " << getisbn() << endl;
    cout << "Status: " << (getstatus() ? "Available" : "Unavailable") << endl;
}