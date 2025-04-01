#include "history.h"

int main() {
    int choice;

    while (true) {
        cout << "Select a choice!" << endl << "1: Register" << endl << "2: Login" << endl << "Your choice : ";
        cin >> choice;

        if (choice == 1) {
            Register();
        }
        else if (choice == 2) {
            if (LoggingIn()) {
                cout << "Login Successful" << endl;
                break;
            }
            else {
                cout << "Incorrect Information, Try Again!" << endl;
            }
        }
        else {
            cout << "Invalid option. Try again!" << endl;
        }
    }
}
