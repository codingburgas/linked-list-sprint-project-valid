#include "User.h"
#include <fstream>
#include <iostream>

// Конструктор – инициализира началото на списъка с потребители
UserManager::UserManager() {
    head = nullptr;
}

// Деструктор – освобождава паметта на всички потребители
UserManager::~UserManager() {
    ClearUsers();
}

// Регистрация на нов потребител
void UserManager::Register(string username, string password) {
    // Създаване на нов потребител и добавяне към списъка
    User* newUser = new User{ username, password, head };
    head = newUser;

    // Записване на потребителските данни във файл
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
}

// Функция за вход на потребител
bool UserManager::LoggingIn(string username, string password) {
    // Опит за отваряне на файл с потребителско име
    ifstream read(username + ".txt");
    if (!read) {
        cout << "User not found!" << endl;
        return false;
    }

    // Прочитане на записаното потребителско име и парола
    string storedUser, storedPass;
    getline(read, storedUser);
    getline(read, storedPass);
    read.close();

    // Сравняване с въведените данни
    return (storedUser == username && storedPass == password);
}

// Освобождаване на всички потребители от паметта
void UserManager::ClearUsers() {
    while (head != nullptr) {
        User* temp = head;
        head = head->next;
        delete temp;
    }
}