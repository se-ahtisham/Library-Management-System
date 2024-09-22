#include"admin.h"


Admin::Admin() : User(), password(""), securityQuestion(""), securityAnswer("") {}

Admin::Admin(string name, int id, string email, string password, string securityQuestion, string securityAnswer) {}

void Admin::setPassword(string password) { this->password = password; }
void Admin::setSecurityQuestion(string question) { this->securityQuestion = question; }
void Admin::setSecurityAnswer(string answer) { this->securityAnswer = answer; }

string Admin::getPassword() { return password; }
string Admin::getSecurityQuestion() { return securityQuestion; }
string Admin::getSecurityAnswer() { return securityAnswer; }

void Admin::printAdminDetails() {
    cout << "Admin Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Security Question: " << securityQuestion << endl;
    cout << "Security Answer: " << securityAnswer << endl;
}