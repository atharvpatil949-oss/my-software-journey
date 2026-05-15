#include <iostream>
#include <vector>
#include <string> // We definitely need this now!

using namespace std;

int main() {
    string subjectName; // A variable to hold text
    vector<int> marks;
    int input;

    cout << "Enter the Subject Name: ";
    getline(cin, subjectName); // Use getline for strings to include spaces

    cout << "--- Recording marks for " << subjectName << " ---" << endl;
    cout << "Enter marks (Type -1 to stop):" << endl;

    while (true) {
        cout << "> ";
        cin >> input;
        if (input == -1) break;
        marks.push_back(input);
    }

    // Final Report
    cout << "\n--- " << subjectName << " Detailed Report ---" << endl;
    for (int m : marks) {
        string grade;
        //Logic: Assigning a grade based on the mark
        if (m>= 90) {
            grade="A+";
        } else if (m>= 75) {
            grade="A";
        } else if (m>=60) {
            grade="B";
        } else if (m>=40) {
            grade="C";
        } else {
            grade="F";
        }
        cout << "Mark: " << m << " - Grade: " << grade << endl;

        }
         return 0;
}