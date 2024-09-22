#include "journalArray.h"

using namespace std;

Journalarray::Journalarray(int capacity) {
    this->capacity = capacity;
    size = 0;
    journals = new Journal[capacity];
}

Journalarray::~Journalarray() {
    delete[] journals;
}

void Journalarray::addJournal(Journal journal) {
    for (int i = 0; i < size; i++) {
        if (journal.getisbn() == journals[i].getisbn()) {
            cout << "Already Found!!!" << endl;
            return;
        }
    }

    if (size < capacity) {
        journals[size++] = journal;
    }
    else {
        cout << "Array is full. Cannot add more journals." << endl;
    }
}

bool Journalarray::searchJournalByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (journals[i].getisbn() == isbn) {
            return true;
        }
    }
    return false;
}


void Journalarray::searchjournal(int isbn) {
    for (int i = 0; i < size; i++) {
        if (journals[i].getisbn() == isbn && journals[i].getstatus() == true) {
            cout << "Newspaper Found" << endl;
            cout << "Newspaper Name: " << journals[i].getname() << endl;
            cout << "Newspaper ISBN: " << journals[i].getisbn() << endl;
            cout << "Newspaper Author: " << journals[i].getauthor() << endl;
            cout << "Newspaper Library Code: " << journals[i].getlibrarycode() << endl;
        }
        else if (journals[i].getisbn() == isbn && journals[i].getstatus() == false) {
            cout << "Journal Found" << endl;
            cout << "But Not Avaiable at this Time" << endl;
        }

    }



}

void Journalarray::deleteJournalByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (journals[i].getisbn() == isbn) {
            for (int j = i; j < size - 1; ++j) {
                journals[j] = journals[j + 1];
            }
            --size;
            return;
        }
    }
}

void Journalarray::updateJournalByISBN(int isbn, Journal journal) {
    for (int i = 0; i < size; i++) {
        if (journals[i].getisbn() == isbn) {
            journals[i] = journal;
            return;
        }
    }
}

void Journalarray::printAllJournals() {
    for (int i = 0; i < size; i++) {
        journals[i].printjournalinfo();
        cout << "Volumn: " << journals[i].getvolume() << endl;
        cout << "----------------------------------------------" << endl;
    }
}



void Journalarray::printOrderedJournals() {

    for (int i = 0; i < size; i++) {
        if (journals[i].getstatus() == false)
        {
            journals[i].printjournalinfo();
            cout << "Volumn: " << journals[i].getvolume() << endl;
            cout << "----------------------------------------------" << endl;
        }
           
    }

}
void Journalarray::printreturnJournals() {
    for (int i = 0; i < size; i++) {
        if (journals[i].getstatus() == true)
        {
            journals[i].printjournalinfo();
            cout << "Volumn: " << journals[i].getvolume() << endl;
            cout << "----------------------------------------------" << endl;
        }
          
    }
}


Journal Journalarray::getjournalobj(int isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (journals[i].getisbn() == isbn) {
            return journals[i];
        }
    }
}
