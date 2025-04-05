#include "quiz.h"
#include <iostream>
#include <string>

using namespace std;

void QuizManager::StartQuiz() {
    int score = 0;
    string answer;
    int levelChoice;

    cout << "Choose Difficulty Level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Hard" << endl;
    cout << "Enter your choice: ";
    cin >> levelChoice;

    if (cin.fail() || levelChoice < 1 || levelChoice > 3) {
        cout << "Invalid input. Starting Normal level by default." << endl;
        levelChoice = 2;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "--- Quiz Time! ---" << endl;

    if (levelChoice == 1) {
        // Easy
        cout << "1. What is the main color of the Greece" << endl;
        cout << "A) Blue" << endl << "B) Green" << endl <<" C) Red" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "A" || answer == "a") score++;

        cout << "2.On how much seas does Bulgaria border?" << endl;
        cout << "A) 2" << endl << "B) 3" << endl << "C) 1" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "C" || answer == "c") score++;
    }
    else if (levelChoice == 2) {
        // Normal
        cout << "1. What is the capital of France?" << endl;
        cout << "A) Paris" << endl << "B) Berlin" << endl << "C) Rome" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "A" || answer == "a") score++;

        cout << "2. How many presidents has the USA had?";
        cout << "A) 46" << endl << "B) 41" << endl << "C) 44" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "C" || answer == "c") score++;
    }
    else if (levelChoice == 3) {
        // Hard
        cout << "1. In what year did Bulgaria fall under Ottoman rule?" << endl;
        cout << "A) 1421" << endl << "B) 1393" << endl << "C) 1880" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "B" || answer == "b") score++;

        cout << "2. Who developed the theory of relativity?" << endl;
        cout << "A) Newton" << endl << "B) Tesla" << endl << "C) Einstein" << endl << "Your answer : ";
        cin >> answer;
        if (answer == "C" || answer == "c") score++;
    }

    cout << "You got " << score << " out of 2 correct!" << endl;
}

