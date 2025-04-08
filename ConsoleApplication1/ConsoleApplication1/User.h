#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура за съхранение на потребителско име, парола и указател към следващия потребител
struct User {
    string username;
    string password;
    User* next;
};

// Клас за управление на потребителите
class UserManager {
private:
    User* head; // Указател към първия потребител в свързания списък

public:
    UserManager();                // Конструктор
    ~UserManager();               // Деструктор
    void Register(string username, string password); // Регистрира нов потребител
    bool LoggingIn(string username, string password); // Проверява потребителско име и парола
    void ClearUsers();           // Изтрива всички потребители от паметта
};