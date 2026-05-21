#include "mark_tracker.h"
#include <iostream>
#include <vector>
#include <string> // We definitely need this now!

using namespace std;

void runMarkTracker() {
    vector<int> marks;
    int input;

    cout << "\n--- Student Mark Tracker & Analyzer ---" << endl;
    cout << "Enter student marks out of 100 (Type -1 to finish grading):" << endl;

    while (true) {
        cout << "> ";
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            string garbage;
            cin >> garbage;
            cout << "Invalid input! Please enter a whole number integer (or -1 to stop)." << endl;
            continue;
        }

        if (input == -1) break;
        marks.push_back(input);
    }

    cout << "\n--- INDIVIDUAL REPORT ---" << endl;
    for (int m : marks) {
        cout << "Mark: " << m << " -> Grade: ";
        if (m >= 90) cout << "A+" << endl;
        else if (m >= 80) cout << "A" << endl;
        else if (m >= 70) cout << "B" << endl;
        else if (m >= 60) cout << "C" << endl;
        else if (m >= 50) cout << "D" << endl;
        else cout << "F (Fail)" << endl;
    }

    // Statistics Engine
    if (!marks.empty()) {
        double sum = 0;
        int highest = marks[0];

        for (int m : marks) {
            sum += m;
            if (m > highest) {
                highest = m;
            }
        }

        double average = sum / marks.size();

        cout << "\n===============================" << endl;
        cout << "       MARK STATISTICS         " << endl;
        cout << "===============================" << endl;
        cout << "Average Mark of the Class: " << average << endl;
        cout << "Highest Mark Scored:       " << highest << endl;
        cout << "===============================" << endl;
    } else {
        cout << "\nNo marks were entered to calculate statistics." << endl;
    
    }
}