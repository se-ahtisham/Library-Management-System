#include"user.h"


User::User() : name(""), id(0), email("") {}
User::User(string name, int id, string email) : name(name), id(id), email(email) {}

string User::getName() { return name; }
int User::getId() { return id; }
string User::getEmail() { return email; }

void User::setName(string name) { this->name = name; }
void User::setId(int id) { this->id = id; }
void User::setEmail(string email) { this->email = email; }