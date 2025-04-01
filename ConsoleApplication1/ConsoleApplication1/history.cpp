#include "history.h"

bool LoggingIn() {
    string username, password, user, pass;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream read(username + ".txt");
    if (!read) {
        cout << "User not found!\n";
        return false;
    }

    getline(read, user);
    getline(read, pass);
    read.close();

    return (user == username && pass == password);
}

void Register() {
    string username, password;

    cout << "Select a username: ";
    cin >> username;
    cout << "Select a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
}
