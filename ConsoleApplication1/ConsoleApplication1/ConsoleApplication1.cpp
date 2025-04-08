#include "history.h"
#include "historyMeeting.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void showMainMenu() {
    cout << "Select an option:" << endl
        << "1: Register" << endl
        << "2: Login" << endl
        << "0: Exit" << endl;
}

void showHistoryMenu() {
    cout << "Select an option:" << endl
        << "1: Add a historical event" << endl
        << "2: Show historical events" << endl
        << "3: Search event by year" << endl
        << "4: Search event by title" << endl
        << "5: Go back to main menu" << endl;
}

int main() {
    UserManager manager;
    int choice;
    int historyChoice;

    while (true) {
        showMainMenu();
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            system("cls");
            string username, password;
            cout << "Select a username: ";
            cin >> username;
            cout << "Select a password: ";
            cin >> password;

            manager.Register(username, password);
        }
        else if (choice == 2) {
            system("cls");
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (manager.LoggingIn(username, password)) {
                cout << "Login Successful" << endl;
                system("pause");
                system("cls");

                while (true) {
                    cout << "What would you like to do?" << endl
                        << "1: Manage Historical Events" << endl
                        << "2: Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> historyChoice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input! Please enter a valid option." << endl;
                        continue;
                    }

                    if (historyChoice == 1) {
                        system("cls");

                        HistoryMeeting history;
                        history.loadFromFile();

                        while (true) {
                            showHistoryMenu();
                            cout << "Enter your choice: ";
                            cin >> historyChoice;

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid input! Please enter a valid option." << endl;
                                continue;
                            }

                            if (historyChoice == 1) {
                                system("cls");
                                history.addEvent();
                            }
                            else if (historyChoice == 2) {
                                system("cls");
                                history.showEvents();
                            }
                            else if (historyChoice == 3) {
                                system("cls");
                                history.searchByYear();
                            }
                            else if (historyChoice == 4) {
                                system("cls");
                                history.searchByTitle();
                            }
                            else if (historyChoice == 5) {
                                break;
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
