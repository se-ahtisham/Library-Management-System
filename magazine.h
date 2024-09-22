#pragma once
#include "document.h"


class Magazine : public Document {
private:
    int issueNumber; 

public:
    Magazine();
    Magazine(string name, string author, int yearofp, int librarycode, int isbn, bool status, int issueNumber);

    void setissueNumber(int issueNumber1);
    int getissueNumber();

    void printmagazineinfo();
};

