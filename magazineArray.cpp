#include "magazineArray.h"

Magazinearray::Magazinearray(int capacity) {
    this->capacity = capacity;
    size = 0;
    mag = new Magazine[capacity];
}

Magazinearray::~Magazinearray() {
    delete[] mag;
}

void Magazinearray::addMagazine(Magazine magazine) {
    for (int i = 0; i < size; i++) {
        if (magazine.getisbn() == mag[i].getisbn()) {
            cout << "Already Found!!!" << endl;
            return;
        }
    }

    if (size < capacity) {
        mag[size++] = magazine;
    }
    else {
        cout << "Array is full. Cannot add more magazines." << endl;
    }
}

bool Magazinearray::searchMagazineByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (mag[i].getisbn() == isbn) {
            return true;
        }
    }
    return false;
}


void Magazinearray::searchmagazine(int isbn) {
    for (int i = 0; i < size; i++) {
        if (mag[i].getisbn() == isbn && mag[i].getstatus() == true) {
            cout << "Magazine Found" << endl;
            cout << "Magazine Name: " << mag[i].getname() << endl;
            cout << "Magazine ISBN: " << mag[i].getisbn() << endl;
            cout << "Magazine Author: " << mag[i].getauthor() << endl;
            cout << "Magazine Library Code: " << mag[i].getlibrarycode() << endl;
        }
        else if (mag[i].getisbn() == isbn && mag[i].getstatus() == false) {
            cout << "Magazine Found" << endl;
            cout << "But Not Avaiable at this Time" << endl;
        }

    }

}




void Magazinearray::deleteMagazineByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (mag[i].getisbn() == isbn) {
            for (int j = i; j < size - 1; ++j) {
                mag[j] = mag[j + 1];
            }
            --size;
            return;
        }
    }
}

void Magazinearray::updateMagazineByISBN(int isbn, Magazine magazine) {
    for (int i = 0; i < size; i++) {
        if (mag[i].getisbn() == isbn) {
            mag[i] = magazine;
            return;
        }
    }
}

void Magazinearray::printAllMagazines() {
    for (int i = 0; i < size; i++) {
        mag[i].printmagazineinfo();
        cout << "Issue Number: " << mag[i].getissueNumber() << endl;
        cout << "----------------------------------------------" << endl;
    }
}


void Magazinearray::printOrderedMagazines() {

    for (int i = 0; i < size; i++) {
        if (mag[i].getstatus() == false)
        {
            mag[i].printmagazineinfo();
            cout << "Issue Number: " << mag[i].getissueNumber() << endl;
            cout << "----------------------------------------------" << endl;
        }
           
    }


}
void Magazinearray::printreturnMagazines() {
    for (int i = 0; i < size; i++) {
        if (mag[i].getstatus() == false)
        {
            mag[i].printmagazineinfo();
            cout << "Issue Number: " << mag[i].getissueNumber() << endl;
            cout << "----------------------------------------------" << endl;
        }
           
    }
}


Magazine Magazinearray::getmagazineobj(int isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (mag[i].getisbn() == isbn) {
            return mag[i];
        }
    }

}