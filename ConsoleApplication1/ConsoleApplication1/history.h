#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
    User* next;
};

class UserManager {
private:
    User* head;

public:
    UserManager();
    ~UserManager();
    void Register(string username, string password);
    bool LoggingIn(string username, string password);
    void ClearUsers();
};