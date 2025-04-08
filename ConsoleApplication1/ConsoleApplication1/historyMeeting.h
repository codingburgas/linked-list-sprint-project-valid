#pragma once
#include <string>

struct Event {
    int year;
    std::string title;
    Event* next;
};

class HistoryMeeting {
private:
    Event* head;

public:
    HistoryMeeting();
    ~HistoryMeeting();

    void loadFromFile();
    void saveToFile();
    void addEvent();
    void showEvents();
    void searchByYear();
    void searchByTitle();
};
