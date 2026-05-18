#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// TOOL 1; RESISTOR COLOR CODE CALCULATOR

void runResistorCalculator() {
map<string, int> colorValues = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
        {"gray", 8}, {"white", 9}
    };
    map<string, string> tolerancevalues = {
        {"brown", "+/- 1%"}, {"red", "+/ -2%"},
        {"green", "+/- 0.5%"}, {"blue", "+/- 0.25%"},
        {"violet", "0.1%"}, {"gray", "+/- 0.05%"},
        {"gold", "+/-5%"}, {"silver", "+/- 10%"}
    };

    string band1, band2, band3, band4;

    cout << "\n--- ENTC Resistor Color Code Calculator ---" << endl;
    cout << "Enter the color of Band 1: "; cin >> band1;
    cout << "Enter the color of Band 2: "; cin >> band2;
    cout << "Enter the color of Band 3 (Multiplier): "; cin >> band3;
    cout << "Enter the color of Band 4 (Tolerance): "; cin >> band4;

    if (colorValues.find(band1) == colorValues.end() || 
        colorValues.find(band2) == colorValues.end() || 
        colorValues.find(band3) == colorValues.end() || 
        tolerancevalues.find(band4) == tolerancevalues.end()) {
        
        cout << "Error: One or more invalid colors entered!" << endl;
        return; // 'return' inside a void function simply exits the function early
    }

    int digit1 = colorValues[band1];
    int digit2 = colorValues[band2];
    int multiplierExponent = colorValues[band3];
    string tolerance = tolerancevalues[band4];

    double resistance = (digit1 * 10 + digit2) * pow(10, multiplierExponent);

    cout << "\n======================================" << endl;
    if (resistance >= 1000000) {
        cout << "Calculated Resistance: " << (resistance / 1000000.0) << " MOhms (Megaohms) " << tolerance << endl;
    } else if (resistance >= 1000) {
        cout << "Calculated Resistance: " << (resistance / 1000.0) << " kOhms (Kiloohms) " << tolerance << endl;
    } else {
        cout << "Calculated Resistance: " << resistance << " Ohms " << tolerance << endl;
    }
    cout << "======================================" << endl;
}

// TOOL 2: STUDENT MARK TRACKER & ANALYZER

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
// ==========================================
// MAIN COMMAND CENTER
// ==========================================
int main() {
    int choice;

    while (true) {
        cout << "\n======================================" << endl;
        cout << "         COEP ENTC TOOLKIT            " << endl;
        cout << "======================================" << endl;
        cout << "1. Run Resistor Color Code Calculator" << endl;
        cout << "2. Run Student Mark Tracker & Analyzer" << endl;
        cout << "3. Exit System" << endl;
        cout << "======================================" << endl;
        cout << "Select a module option (1-3): ";
        
        cin >> choice;

        // Validation for menu system
        if (cin.fail()) {
            cin.clear();
            string junk;
            cin >> junk;
            cout << "\nInvalid choice! Please select a valid option number." << endl;
            continue;
        }

        if (choice == 1) {
            runResistorCalculator();
        } else if (choice == 2) {
            runMarkTracker();
        } else if (choice == 3) {
            cout << "\nShutting down Toolkit. Thank you, Engineer!" << endl;
            break; // Breaks the infinite loop and gracefully exits the program
        } else {
            cout << "\nInvalid choice! Please select a number between 1 and 3." << endl;
        }
    }

    return 0;
}