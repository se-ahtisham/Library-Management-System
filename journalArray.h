#pragma once

#include "journal.h"

class Journalarray
{
private:
    int capacity;         
    int size;              
    Journal* journals;     

public:
    Journalarray(int capacity);   
    ~Journalarray();                

    void addJournal(Journal journal);              
    bool searchJournalByISBN(int isbn);              
    void deleteJournalByISBN(int isbn);               
    void updateJournalByISBN(int isbn, Journal journal); 

    void printAllJournals();  
    void printOrderedJournals();
    void printreturnJournals();

    void searchjournal(int isbn);

    Journal getjournalobj(int isbn);

};