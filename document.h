#pragma once

#include <iostream>
#include <string>

using namespace std;

class Document {
protected:
    string name;         
    string author;
    int yearofp;
    int librarycode;
    int isbn;
    bool status;  // False "Not Avaiable" True means "Avaiable"

public:
    Document();
    Document(string name, string author, int yearofp, int librarycode, int isbn, bool status);

    void setname(string name1);
    void setauthor(string author1);
    void setyearofp(int yearofp1);
    void setlibrarycode(int librarycode1);
    void setisbn(int isbn1);
    void setstatus(bool status1);

    string getname();
    string getauthor();
    int getyearofp();
    int getlibrarycode();
    int getisbn();
    bool getstatus();

};
