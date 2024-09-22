#include "newspaperArray.h"

Newspaperarray::Newspaperarray(int capacity) {
    this->capacity = capacity;
    size = 0;
    news = new Newspaper[capacity];
}

Newspaperarray::~Newspaperarray() {
    delete[] news;
}

void Newspaperarray::addNewspaper(Newspaper newspaper) {
    for (int i = 0; i < size; i++) {
        if (newspaper.getisbn() == news[i].getisbn()) {
            cout << "Already Found!!!" << endl;
            return;
        }
    }

    if (size < capacity) {
        news[size++] = newspaper;
    }
    else {
        cout << "Array is full. Cannot add more newspapers." << endl;
    }
}

bool Newspaperarray::searchNewspaperByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (news[i].getisbn() == isbn) {
            return true;
        }
    }
    return false;
}



void Newspaperarray:: searchnewspaper(int isbn)
{
    for (int i = 0; i < size; i++) {
        if (news[i].getisbn() == isbn && news[i].getstatus() == true) {
            cout << "Newspaper Found" << endl;
            cout << "Newspaper Name: " << news[i].getname() << endl;
            cout << "Newspaper ISBN: " << news[i].getisbn() << endl;
            cout << "Newspaper Author: " << news[i].getauthor() << endl;
            cout << "Newspaper Library Code: " << news[i].getlibrarycode() << endl;
        }
        else if (news[i].getisbn() == isbn && news[i].getstatus() == false) {
            cout << "Newspaper Found" << endl;
            cout << "But Not Avaiable at this Time" << endl;
        }

    }
}

void Newspaperarray::deleteNewspaperByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (news[i].getisbn() == isbn) {
            for (int j = i; j < size - 1; ++j) {
                news[j] = news[j + 1];
            }
            --size;
            return;
        }
    }
}

void Newspaperarray::updateNewspaperByISBN(int isbn, Newspaper newspaper) {
    for (int i = 0; i < size; i++) {
        if (news[i].getisbn() == isbn) {
            news[i] = newspaper;
            return;
        }
    }
}

void Newspaperarray::printAllNewspapers() {
    for (int i = 0; i < size; i++) {
        news[i].printnewspaperinfo();
        cout << "Edition: " << news[i].getedition() << endl;
        cout << "----------------------------------------------" << endl;
    }
}



void Newspaperarray::printOrderedNewspaper() {

    for (int i = 0; i < size; i++) {
        if (news[i].getstatus() == false)
        {
            news[i].printnewspaperinfo();
            cout << "Edition: " << news[i].getedition() << endl;
            cout << "----------------------------------------------" << endl;
        }
          
    }


}
void Newspaperarray:: printreturnNewspaper() {
    for (int i = 0; i < size; i++) {
        if (news[i].getstatus() == true)
        {
            news[i].printnewspaperinfo();
            cout << "Edition: " << news[i].getedition() << endl;
            cout << "----------------------------------------------" << endl;
        }
            
    }
}


Newspaper Newspaperarray::getnewspaperobj(int isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (news[i].getisbn() == isbn) {
            return news[i];
        }
    }
}