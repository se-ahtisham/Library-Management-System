#pragma once

#include "newspaper.h"

class Newspaperarray
{
private:
    int capacity;             
    int size;                 
    Newspaper* news;          

public:
    Newspaperarray(int capacity);    
    ~Newspaperarray();                

    void addNewspaper(Newspaper newspaper);       
    bool searchNewspaperByISBN(int isbn);          
    void deleteNewspaperByISBN(int isbn);          
    void updateNewspaperByISBN(int isbn, Newspaper newspaper);  



   void printOrderedNewspaper();
    void printreturnNewspaper();
    void printAllNewspapers();    

    void searchnewspaper(int isbn);

    Newspaper getnewspaperobj(int isbn);
};