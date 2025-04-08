#pragma once

#include <string>

struct Event {
    int year;
    std::string title;
    Event* next;
};

void saveToFile();
void loadFromFile();
void addEvent();
void showEvents();
void searchByYear();
void searchByTitle();