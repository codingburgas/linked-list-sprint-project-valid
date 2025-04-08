#include "historyMeeting.h"
#include <fstream>
#include <iostream>

HistoryMeeting::HistoryMeeting() : head(nullptr) {}

HistoryMeeting::~HistoryMeeting() {
    Event* current = head;
    while (current != nullptr) {
        Event* temp = current;
        current = current->next;
        delete temp;
    }
}

void HistoryMeeting::saveToFile() {
    std::ofstream file("events.txt");
    Event* current = head;
    while (current != nullptr) {
        file << current->year << "|" << current->title << "\n";
        current = current->next;
    }
    file.close();
}

void HistoryMeeting::loadFromFile() {
    std::ifstream file("events.txt");
    if (!file) return;

    std::string line;
    while (getline(file, line)) {
        size_t sep = line.find('|');
        if (sep == std::string::npos) continue;

        Event* e = new Event;
        e->year = stoi(line.substr(0, sep));
        e->title = line.substr(sep + 1);
        e->next = nullptr;

        if (head == nullptr) {
            head = e;
        }
        else {
            Event* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = e;
        }
    }
    file.close();
}

void HistoryMeeting::addEvent() {
    Event* e = new Event;
    std::cout << "Enter year: ";
    std::cin >> e->year;
    std::cin.ignore();
    std::cout << "Enter the title of the event: ";
    std::getline(std::cin, e->title);
    e->next = nullptr;

    if (head == nullptr) {
        head = e;
    }
    else {
        Event* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = e;
    }

    saveToFile();
    std::cout << "The event is added.\n" << std::endl;
}

void HistoryMeeting::showEvents() {
    if (head == nullptr) {
        std::cout << "There is no events." << std::endl;
        return;
    }

    Event* current = head;
    while (current != nullptr) {
        std::cout << current->year << ": " << current->title << std::endl;
        current = current->next;
    }
}

void HistoryMeeting::searchByYear() {
    int y;
    std::cout << "Enter the year of the event ot search : ";
    std::cin >> y;

    Event* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->year == y) {
            std::cout << current->year << ": " << current->title << std::endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
        std::cout << "There is no events with that year." << std::endl;
}

void HistoryMeeting::searchByTitle() {
    std::cin.ignore();
    std::string searchTitle;
    std::cout << "Enter a title or part of the name of the event: ";
    std::getline(std::cin, searchTitle);

    Event* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->title.find(searchTitle) != std::string::npos) {
            std::cout << current->year << ": " << current->title << std::endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
        std::cout << "There is no events with title like this." << std::endl;
}
