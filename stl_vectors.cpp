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
    cout << "\n--- " << subjectName << " Report ---" << endl;
    for (int m : marks) {
        cout << m << " ";
    }
    cout << "\nTotal entries: " << marks.size() << endl;

    return 0;
}
