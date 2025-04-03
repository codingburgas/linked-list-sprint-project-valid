#include "user.h"

UserManager::UserManager() {
    head = nullptr;
}

UserManager::~UserManager() {
    ClearUsers();
}

void UserManager::Register(string username, string password) {
    User* newUser = new User{ username, password, head };
    head = newUser;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
}

bool UserManager::LoggingIn(string username, string password) {
    ifstream read(username + ".txt");
    if (!read) {
        cout << "User not found!" << endl;
        return false;
    }

    string storedUser, storedPass;
    getline(read, storedUser);
    getline(read, storedPass);
    read.close();

    return (storedUser == username && storedPass == password);
}

void UserManager::ClearUsers() {
    while (head) {
        User* temp = head;
        head = head->next;
        delete temp;
    }
}