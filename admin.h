#pragma once
#include"user.h"


class Admin : public User {
private:
    string password;
    string securityQuestion;
    string securityAnswer;

public:
    Admin();
    Admin(string name, int id, string email, string password, string securityQuestion, string securityAnswer);

    void setPassword(string password);
    void setSecurityQuestion(string question);
    void setSecurityAnswer(string answer);

    string getPassword();
    string getSecurityQuestion();
    string getSecurityAnswer();


    void printAdminDetails();
};