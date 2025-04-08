#include "User.h"
#include "historyMeeting.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

// Основно меню за избор между регистрация, вход или изход
void showMainMenu() {
    cout << "Select an option:" << endl
        << "1: Register" << endl
        << "2: Login" << endl
        << "0: Exit" << endl;
}

// Меню за управление на исторически събития
void showHistoryMenu() {
    cout << "Select an option:" << endl
        << "1: Add a historical event" << endl
        << "2: Show historical events" << endl
        << "3: Search event by year" << endl
        << "4: Search event by title" << endl
        << "5: Go back to main menu" << endl;
}

int main() {
    UserManager manager; // Обект за управление на потребителите
    int choice;
    int historyChoice;

    while (true) {
        showMainMenu();
        cout << "Your choice: ";
        cin >> choice;

        // Проверка за невалиден вход
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            system("cls"); // Изчистване на екрана
            string username, password;
            cout << "Select a username: ";
            cin >> username;
            cout << "Select a password: ";
            cin >> password;

            manager.Register(username, password); // Регистрация на нов потребител
        }
        else if (choice == 2) {
            system("cls");
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            // Опит за вход
            if (manager.LoggingIn(username, password)) {
                cout << "Login Successful" << endl;
                system("pause");
                system("cls");

                while (true) {
                    // Меню след вход
                    cout << "What would you like to do?" << endl
                        << "1: Manage Historical Events" << endl
                        << "2: Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> historyChoice;

                    // Проверка за невалиден вход
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input! Please enter a valid option." << endl;
                        continue;
                    }

                    if (historyChoice == 1) {
                        system("cls");

                        HistoryMeeting history;  // Обект за работа със събития
                        history.loadFromFile();  // Зареждане на събития от файл

                        while (true) {
                            showHistoryMenu();
                            cout << "Enter your choice: ";
                            cin >> historyChoice;

                            // Проверка за невалиден вход
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid input! Please enter a valid option." << endl;
                                continue;
                            }

                            if (historyChoice == 1) {
                                system("cls");
                                history.addEvent(); // Добавяне на събитие
                            }
                            else if (historyChoice == 2) {
                                system("cls");
                                history.showEvents(); // Показване на всички събития
                            }
                            else if (historyChoice == 3) {
                                system("cls");
                                history.searchByYear(); // Търсене по година
                            }
                            else if (historyChoice == 4) {
                                system("cls");
                                history.searchByTitle(); // Търсене по заглавие
                            }
                            else if (historyChoice == 5) {
                                break; // Връщане към горното меню
                            }
                            else {
                                cout << "Invalid choice. Try again!" << endl;
                            }
                        }
                    }
                    else if (historyChoice == 2) {
                        cout << "Exiting the program. Bye!" << endl;
                        return 0;
                    }
                    else {
                        cout << "Invalid option. Try again!" << endl;
                    }
                }
            }
            else {
                cout << "Incorrect information, try again!" << endl;
            }
        }
        else if (choice == 0) {
            cout << "Exiting the program. Bye!" << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again!" << endl;
        }
    }
}