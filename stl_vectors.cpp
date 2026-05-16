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

        // Safety check: Did the user type a decimal or text?
        if (cin.fail()) {
            cin.clear(); // Reset the stream error flag
            string garbage;
            cin >> garbage; // Clear the invalid input (like the .5) out of the buffer
            cout << " Invalid input! Please enter a whole number integer (or -1 to stop)." << endl;
            continue; // Skip the rest of the loop and ask for input again
        }
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
         // --- STATISTICS SCETION ---
         if (!marks. empty()) {
            double sum = 0;
            int highest = marks[0]; // Assume the first marks are the highest marks

            for (int m : marks) {
                sum += m; // Add every mark to the total sum

                if (m > highest) {
                    highest = m; // We found a new highest mark!
                }
            }
            double average = sum / marks.size();

            cout << "\n==========================" << endl;
            cout << "    MARKS STATISTICS         " << endl;
            cout << "==========================" << endl;
            cout << " Average Mark of tthe Class: " << average << endl;
            cout << " Highest Mark: " << highest << endl;
            cout << "==========================" << endl;
        } else {
            cout << "\nNo marks were entered to calculate statistics." << endl;
        }
                
        return 0;
}