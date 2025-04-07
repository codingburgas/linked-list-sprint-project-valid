#include "quiz.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

// Function for asking the question (for easy and normal)
void askQuestion(const string& question, const string& a, const string& b, const string& c, char correct, const string& hint, int& score) {
    string answer;
    bool hintShown = false;

    while (true) {
        cout << question << endl;
        cout << "A) " << a << endl;
        cout << "B) " << b << endl;
        cout << "C) " << c << endl;
        cout << "Type A/B/C or H for a hint: ";
        cin >> answer;

        if (answer == "H" || answer == "h") {
            if (!hintShown) {
                cout << "Hint: " << hint << endl;
                hintShown = true;
                cout << "Do you want another hint (map)? (Y/N): ";
                string extraHint;
                cin >> extraHint;

                if (extraHint == "Y" || extraHint == "y") {
                    cout << "Please look at the map for help.\n";
                }
                continue; // Re-ask the question
            }
            else {
                cout << "Hint already shown.\n";
            }
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

// Function for asking hard questions with map
void askQuestion(const string& question, const string& a, const string& b, const string& c, char correct, const string& hint, const string& mapFile, int& score) {
    string answer;
    bool hintShown = false;

    while (true) {
        cout << question << endl;
        cout << "A) " << a << endl;
        cout << "B) " << b << endl;
        cout << "C) " << c << endl;
        cout << "Type A/B/C or H for a hint: ";
        cin >> answer;

        if (answer == "H" || answer == "h") {
            if (!hintShown) {
                cout << "Hint: " << hint << endl;
                hintShown = true;
                cout << "Do you want another hint (map)? (Y/N): ";
                string extraHint;
                cin >> extraHint;

                if (extraHint == "Y" || extraHint == "y") {
                    ifstream file(mapFile);
                    if (file.is_open()) {
                        cout << "\n=== ASCII Map ===\n";
                        string line;
                        while (getline(file, line)) {
                            cout << line << endl;
                        }
                        cout << "=================\n";
                        file.close();
                    }
                    else {
                        cout << "Could not load map file.\n";
                    }
                }
                continue; // Re-ask the question
            }
            else {
                cout << "Hint already shown.\n";
            }
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

// Main Quiz Manager
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
            "1. When was Bulgaria's independence declared?",
            "1908", "1878", "1944",
            'A',
            "Check your history textbook!",
            score
        );

        askQuestion(
            "2. Who was the first Bulgarian khan?",
            "Asparuh", "Krum", "Samuil",
            'A',
            "Asparuh founded Danubian Bulgaria in 681 AD.",
            score
        );

        askQuestion(
            "3. What was the name of the first Bulgarian state?",
            "Sofia Kingdom", "First Bulgarian Empire", "Northern Kingdom",
            'B',
            "The First Bulgarian Empire existed from 681 to 1018.",
            score
        );

        askQuestion(
            "4. Who created the Bulgarian alphabet?",
            "Levski and Botev", "Cyril and Methodius", "Simeon and Boris",
            'B',
            "Cyril and Methodius created the Glagolitic alphabet.",
            score
        );

        askQuestion(
            "5. When did Bulgaria fall under Ottoman rule?",
            "1396", "1876", "681",
            'A',
            "Look up when the Vidin Tsardom fell!",
            score
        );

        askQuestion(
            "6. Who was Vasil Levski?",
            "A king", "A revolutionary", "A teacher",
            'B',
            "He was known as the Apostle of Freedom.",
            score
        );

        askQuestion(
            "7. What was the most famous uprising in 1876?",
            "April Uprising", "September Uprising", "Chiprovtsi Uprising",
            'A',
            "It was a major step in the fight for freedom.",
            score
        );

        askQuestion(
            "8. When was Bulgaria liberated from Ottoman rule?",
            "1908", "1944", "1878",
            'C',
            "The Treaty of San Stefano was signed in this year.",
            score
        );

        askQuestion(
            "9. Who was the ruler during Bulgaria's Golden Age?",
            "Tsar Ivan Asen II", "Tsar Simeon the Great", "Tsar Peter",
            'B',
            "Simeon ruled from 893 to 927.",
            score
        );

        askQuestion(
            "10. What was the capital of the Second Bulgarian Empire?",
            "Sofia", "Veliko Tarnovo", "Plovdiv",
            'B',
            "Tarnovgrad – the pride of Bulgarian tsars!",
            score
        );
    }

    else if (levelChoice == 2) {
        askQuestion(
            "1. Which Bulgarian tsar defeated the Byzantines at the Battle of Kleidion?",
            "Tsar Ivan Shishman", "Tsar Kaloyan", "Tsar Samuel",
            'C',
            "Samuel fought fiercely against Byzantium.",
            score
        );

        askQuestion(
            "2. What year did the Second Bulgarian Empire begin?",
            "1185", "1018", "1230",
            'A',
            "Think of the Asen and Peter brothers' uprising.",
            score
        );

        askQuestion(
            "3. Where was Khan Krum's victory against the Byzantines?",
            "Pliska", "Varbitsa Pass", "Preslav",
            'B',
            "He ambushed Emperor Nicephorus there.",
            score
        );

        askQuestion(
            "4. What title did Bulgarian rulers use during the First Empire?",
            "Tsar", "Emperor", "Khan",
            'C',
            "Khan was the title before Christianity.",
            score
        );

        askQuestion(
            "5. Which Bulgarian ruler introduced Christianity as official religion?",
            "Tsar Simeon", "Khan Boris I", "Tsar Peter",
            'B',
            "He was baptized and converted the country.",
            score
        );

        askQuestion(
            "6. What city was the cultural center during the Golden Age of Bulgaria?",
            "Plovdiv", "Preslav", "Sofia",
            'B',
            "It became a major literary and spiritual hub.",
            score
        );

        askQuestion(
            "7. Which alphabet replaced Glagolitic in Bulgaria?",
            "Greek", "Latin", "Cyrillic",
            'C',
            "It was based on the Glagolitic alphabet.",
            score
        );

        askQuestion(
            "8. Which battle marked the end of the First Bulgarian Empire?",
            "Battle of Adrianople", "Battle of Kleidion", "Fall of Vidin",
            'B',
            "Basil II crushed Samuel’s army.",
            score
        );

        askQuestion(
            "9. Who ruled during Bulgaria's territorial peak?",
            "Tsar Boris I", "Tsar Simeon I", "Tsar Ivan Alexander",
            'B',
            "Under his rule, Bulgaria reached three seas.",
            score
        );

        askQuestion(
            "10. Who led the uprising that restored Bulgarian independence in 1185?",
            "Khan Krum", "Asen and Peter", "Tsar Ivan Asen II",
            'B',
            "They founded the Second Bulgarian Empire.",
            score
        );
    }
    else if (levelChoice == 3) {
        askQuestion(
            "1. Which treaty officially recognized Bulgaria’s independence in 1908?",
            "Treaty of Berlin", "Treaty of Bucharest", "Treaty of Constantinople",
            'C',
            "It was signed after the declaration of independence.",
            "Independence Treaty.txt",
            score
        );

        askQuestion(
            "2. What was the name of Bulgaria’s last medieval capital before Ottoman rule?",
            "Plovdiv", "Vidin", "Tarnovo",
            'B',
            "Tsar Ivan Sratsimir ruled from there.",
            "Vidin.txt",
            score
        );

        askQuestion(
            "3. In which year was the Tarnovo Constitution adopted?",
            "1878", "1879", "1885",
            'B',
            "It was Bulgaria's first modern constitution.",
            "Tarnovo Constitution.txt",
            score
        );

        askQuestion(
            "4. What event triggered the April Uprising of 1876?",
            "Assassination of Levski", "Failed tax reforms", "Brutality of Ottoman authorities",
            'C',
            "People rose against harsh treatment and injustice.",
            "April Uprising.txt",
            score
        );

        askQuestion(
            "5. Who led the Bulgarian delegation at the Berlin Congress (1878)?",
            "Dragan Tsankov", "Petko Slaveykov", "There was no Bulgarian representative",
            'C',
            "Bulgaria was not invited to defend its interests.",
            "Berlin Congress.txt",
            score
        );

        askQuestion(
            "6. What was the main goal of the Internal Macedonian Revolutionary Organization (IMRO)?",
            "Unite all Slavs", "Fight against Austria-Hungary", "Autonomy for Macedonia and Adrianople",
            'C',
            "Their slogan was 'Autonomy within the Ottoman Empire'.",
            "IMRO Map.txt",
            score
        );

        askQuestion(
            "7. When was the Battle of Anchialos (one of Bulgaria’s largest medieval victories)?",
            "917", "1014", "811",
            'A',
            "Simeon I crushed the Byzantines there.",
            "Anchialos Battle.txt",
            score
        );

        askQuestion(
            "8. Who was the Bulgarian PM during the Balkan Wars?",
            "Alexander Stambolijski", "Vasil Radoslavov", "Ivan Geshov",
            'C',
            "He led the country into the First Balkan War.",
            "Balkan Wars.txt",
            score
        );

        askQuestion(
            "9. What was the codename of the secret Bulgarian resistance network during WWII?",
            "Zname", "Tsar Kaloyan", "Chavdar",
            'C',
            "It operated as a partisan unit.",
            "WWII Resistance.txt",
            score
        );

        askQuestion(
            "10. Who was the leader of Bulgaria during the 1944 communist coup?",
            "Simeon II", "Konstantin Muraviev", "Todor Zhivkov",
            'B',
            "He was overthrown after just a few days in office.",
            "1944 Coup.txt",
            score
        );
    }

    cout << "You got " << score << " out of 10 correct!" << endl;
}
