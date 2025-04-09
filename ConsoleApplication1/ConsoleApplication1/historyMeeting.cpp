#include "historyMeeting.h"
#include <fstream>
#include <iostream>

using namespace std;

// Конструктор – инициализира началото на списъка със събития
HistoryMeeting::HistoryMeeting() : head(nullptr) {}

// Деструктор – освобождава всички събития от паметта
HistoryMeeting::~HistoryMeeting() {
    Event* current = head;
    while (current != nullptr) {
        Event* temp = current;
        current = current->next;
        delete temp;
    }
}

// Запазване на всички събития във файл
void HistoryMeeting::saveToFile() {
    ofstream file("events.txt");
    Event* current = head;
    while (current != nullptr) {
        file << current->year << "|" << current->title << "\n";
        current = current->next;
    }
    file.close();
}

// Зареждане на събития от файл
void HistoryMeeting::loadFromFile() {
    ifstream file("events.txt");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        size_t sep = line.find('|');
        if (sep == string::npos) continue;

        // Създаване на ново събитие и добавяне към списъка
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

// Добавяне на ново събитие от потребителя
void HistoryMeeting::addEvent() {
    Event* e = new Event;
    cout << "Enter year: ";
    cin >> e->year;
    cin.ignore();
    cout << "Enter the title of the event: ";
    getline(cin, e->title);
    e->next = nullptr;

    // Добавяне в края на списъка
    if (head == nullptr) {
        head = e;
    }
    else {
        Event* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = e;
    }

    saveToFile(); // Записване във файл
    cout << "The event is added.\n" << endl;
}

// Показване на всички събития
void HistoryMeeting::showEvents() {
    if (head == nullptr) {
        cout << "There is no events." << endl;
        return;
    }

    Event* current = head;
    while (current != nullptr) {
        cout << current->year << ": " << current->title << endl;
        current = current->next;
    }
}

// Търсене на събитие по година
void HistoryMeeting::searchByYear() {
    int y;
    cout << "Enter the year of the event ot search : ";
    cin >> y;

    Event* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->year == y) {
            cout << current->year << ": " << current->title << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
        cout << "There is no events with that year." << endl;
}

// Търсене на събитие по заглавие или част от него
void HistoryMeeting::searchByTitle() {
    cin.ignore();
    string searchTitle;
    cout << "Enter a title or part of the name of the event: ";
    getline(cin, searchTitle);

    Event* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->title.find(searchTitle) != string::npos) {
            cout << current->year << ": " << current->title << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
        cout << "There is no events with title like this." << endl;
}
// Изтриване на събитие по година или заглавие
void HistoryMeeting::deleteEvent() {
    if (head == nullptr) {
        cout << "There are no events to delete." << endl;
        return;
    }

    int option;
    cout << "Delete by:" << endl;
    cout << "1. Year" << endl;
    cout << "2. Title" << endl;
    cout << "Choose: ";
    cin >> option;
    cin.ignore();

    if (option == 1) {
        int y;
        cout << "Enter year of the event to delete: ";
        cin >> y;

        Event* current = head;
        Event* previous = nullptr;

        while (current != nullptr) {
            if (current->year == y) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Event deleted successfully." << endl << endl;
                saveToFile();
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Event with that year not found." << endl;
    }
    else if (option == 2) {
        string title;
        cout << "Enter title or part of it to delete: ";
        getline(cin, title);

        Event* current = head;
        Event* previous = nullptr;

        while (current != nullptr) {
            if (current->title.find(title) != string::npos) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Event deleted successfully." << endl << endl;
                saveToFile();
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Event with that title not found." << endl;
    }
    else {
        cout << "Invalid option." << endl;
    }
}