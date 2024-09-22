#include "bookArray.h"


Bookarray::Bookarray(int capacity) {
    this->capacity = capacity;
    size = 0;
    bk = new Book[capacity];
}

Bookarray::~Bookarray() {
    delete[] bk;
}


void Bookarray::addBook(Book book) {
    for (int i = 0; i < size ; i++)
    {
        if (book.getisbn() == bk[i].getisbn())
        {
            cout << "Already Found!!!" << endl;
        }
    }
   


    if (size < capacity) {
        bk[size++] = book;
    }
    else {
        cout << "Array is full. Cannot add more books." << endl;
    }
}

bool Bookarray::searchBookByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (bk[i].getisbn() == isbn) {
            return true;
        }
    }
    return false;
}



void Bookarray::searchBook(int isbn) {
    for (int i = 0; i < size; i++) {
        if (bk[i].getisbn() == isbn && bk[i].getstatus() == true) {
            cout << "Book Found" << endl;
            cout << "Book Name: " << bk[i].getname() << endl;
            cout << "Book ISBN: " << bk[i].getisbn() << endl;
            cout << "Book Author: " << bk[i].getauthor() << endl;
            cout << "Book Library Code: " << bk[i].getlibrarycode() << endl;  
        }
        else if (bk[i].getisbn() == isbn && bk[i].getstatus() == false) {
            cout << "Book Found" << endl;
            cout << "But Not Avaiable at this Time" << endl;
        }

    }
   
}

void Bookarray::deleteBookByISBN(int isbn) {
    for (int i = 0; i < size; i++) {
        if (bk[i].getisbn() == isbn) {
            for (int j = i; j < size - 1; ++j) {
                bk[j] = bk[j + 1];
            }
            --size;
            return;
        }
    }
}

void Bookarray::updateBookByISBN(int isbn, Book book) {
    for (int i = 0; i < size; i++) {
        if (bk[i].getisbn() == isbn) {
            bk[i] = book;
            return;
        }
    }
}

void Bookarray::printAllBooks() {
    for (int i = 0; i < size; i++) {
        bk[i].prinbookinfo();
        cout << "Pages: " << bk[i].getpages() << endl;    
        cout << "----------------------------------------------" << endl;
    }
}


void Bookarray::printOrderedBook() {

     for (int i = 0; i < size; i++) {
         if (bk[i].getstatus() == false)
         {
             bk[i].prinbookinfo();
             cout << "Pages: " << bk[i].getpages() << endl;
             cout << "----------------------------------------------" << endl;
         }
       
    }


} 
void Bookarray::printreturnBook() {
    for (int i = 0; i < size; i++) {
        if (bk[i].getstatus() == true)
        {
            bk[i].prinbookinfo();
            cout << "Pages: " << bk[i].getpages() << endl;
            cout << "----------------------------------------------" << endl;
        }
            
    }
}


Book Bookarray::getbookobj(int isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (bk[i].getisbn() == isbn) {
            return bk[i];           
        }
    }
    
}







