#pragma once
#include "document.h"

class Newspaper : public Document {
protected:
    string edition;

public:
    Newspaper();
    Newspaper(string name, string author, int yearofp, int librarycode, int isbn, bool status, string edition);

    void setedition(string edition1);
    string getedition();

    void printnewspaperinfo();
};

