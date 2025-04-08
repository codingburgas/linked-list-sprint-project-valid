#pragma once
#include <string>

// Структура за събитие – съдържа година, заглавие и указател към следващото събитие
struct Event {
    int year;
    std::string title;
    Event* next;
};

// Клас за управление на историческите събития
class HistoryMeeting {
private:
    Event* head; // Указател към първото събитие в свързания списък

public:
    HistoryMeeting();  // Конструктор
    ~HistoryMeeting(); // Деструктор

    void loadFromFile();     // Зарежда събития от файл
    void saveToFile();       // Записва събития във файл
    void addEvent();         // Добавя ново събитие
    void showEvents();       // Показва всички събития
    void searchByYear();     // Търси събитие по година
    void searchByTitle();    // Търси събитие по заглавие или част от него
};