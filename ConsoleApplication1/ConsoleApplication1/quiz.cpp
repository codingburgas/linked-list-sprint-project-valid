#include "quiz.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void askQuestion(const string& question, const string& a, const string& b, const string& c, char correct, const string& hint, int& score) {
    string answer;

    while (true) {
        cout << question << endl;
        cout << "A) " << a << endl;
        cout << "B) " << b << endl;
        cout << "C) " << c << endl;
        cout << "Type A/B/C or H for a hint: ";
        cin >> answer;

        if (answer == "H" || answer == "h") {
            cout << "Hint: " << hint << endl;
            continue; // Re-ask the question
        }

        if (answer == "A" || answer == "a" || answer == "B" || answer == "b" || answer == "C" || answer == "c") {
            if (toupper(answer[0]) == correct) score++;
            break;
        }
        else {
            cout << "Invalid choice. Please enter A, B, C, or H." << endl;
        }
    }

    system("cls");
}

void QuizManager::StartQuiz() {
    int score = 0;
    string input;
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

    system("cls");
    cout << "--- Quiz Time! ---" << endl;

    if (levelChoice == 1) {
        askQuestion(
            "1. What is the main color of Greece?",
            "Blue", "Green", "Red",
            'A',
            "Think of the flag!",
            score
        );

        askQuestion(
            "2. On how many seas does Bulgaria border?",
            "2", "3", "1",
            'C',
            "Check a map of the Black Sea region.",
            score
        );

        askQuestion(
            "3. Who was the first President of the United States?",
            "George Washington", "Abraham Lincoln", "John Adams",
            'A',
            "He appears on the U.S. one-dollar bill.",
            score
        );

        askQuestion(
            "4. In which year did World War II end?",
            "1940", "1945", "1950",
            'B',
            "It ended the same year Germany and Japan surrendered.",
            score
        );

        askQuestion(
            "5. What famous wall divided Berlin from 1961 to 1989?",
            "Berlin Wall", "Iron Wall", "Wall of Germany",
            'A',
            "It was a symbol of the Cold War between East and West.",
            score
        );
    }
    else if (levelChoice == 2) {
        askQuestion(
            "1. What is the capital of France?",
            "Paris", "Berlin", "Rome",
            'A',
            "It's known as the City of Light.",
            score
        );

        askQuestion(
            "2. How many presidents has the USA had?",
            "46", "41", "44",
            'C',
            "Think of the number before Joe Biden.",
            score
        );

        askQuestion(
            "3. What event started World War I?",
            "The invasion of Poland", "The bombing of Pearl Harbor", "The assassination of Archduke Franz Ferdinand",
            'C',
            "It involved a royal figure being shot in Sarajevo.",
            score
        );

        askQuestion(
            "4. What country gifted the Statue of Liberty to the U.S.?",
            "Italy", "France", "Germany",
            'B',
            "This country is also famous for the Eiffel Tower.",
            score
        );

        askQuestion(
            "5. What ancient civilization built Machu Picchu?",
            "Incas", "Aztecs", "Mayans",
            'A',
            "This civilization was based in the Andes Mountains of Peru.",
            score
        );
    }
    else if (levelChoice == 3) {
        askQuestion(
            "1. In what year did Bulgaria fall under Ottoman rule?",
            "1421", "1393", "1880",
            'B',
            "It happened in the late 14th century.",
            score
        );

        askQuestion(
            "2. Who developed the theory of relativity?",
            "Newton", "Tesla", "Einstein",
            'C',
            "E=mc²",
            score
        );

        askQuestion(
            "3. In which year did the Russian Revolution begin?",
            "1905", "1917", "1921",
            'B',
            "Same year the U.S. entered World War I.",
            score
        );

        askQuestion(
            "What African empire was ruled by Mansa Musa?",
            "Ghana Empire", "Songhai Empire", "Mali Empire",
            'C',
            "He was the richest man in history and went on a legendary pilgrimage to Mecca.",
            score
        );

        askQuestion(
            "5. Who was the longest-reigning monarch in European history before Queen Elizabeth II?",
            "Louis XIV of France", "Queen Victoria", "Emperor Franz Joseph I",
            'A',
            "He was called the 'Sun King'",
            score
        );
    }

    cout << "You got " << score << " out of 5 correct!" << endl;
}