#pragma once

#include "document.h"

class Journal : public Document {
protected:
    string volume; 

public:
    Journal();
    Journal(string name, string author, int yearofp, int librarycode, int isbn, bool status, string volume);

    void setvolume( string volume1);
    string getvolume();

    void printjournalinfo();
};