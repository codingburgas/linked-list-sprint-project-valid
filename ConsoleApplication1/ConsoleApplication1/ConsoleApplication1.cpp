#include "history.h"

int main() {
    UserManager manager;
    int choice;

    while (true) {
        cout << "Select a choice!" << endl
            << "1: Register" << endl
            << "2: Login" << endl
            << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            string username, password;
            cout << "Select a username: ";
            cin >> username;
            cout << "Select a password: ";
            cin >> password;

            manager.Register(username, password);
        }
        else if (choice == 2) {
            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (manager.LoggingIn(username, password)) {
                cout << "Login Successful" << endl;
                break;
            }
            else {
                cout << "Incorrect Information, Try Again!" << endl;
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
