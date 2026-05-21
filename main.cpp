
#include <iostream>
#include "resistor_calc.h"
#include "mark_tracker.h"
#include "signal_generator.h"
#include "logic_gates.h"
#include "base_converter.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n======================================" << endl;
        cout << "         COEP ENTC TOOLKIT            " << endl;
        cout << "======================================" << endl;
        cout << "1. Run Resistor Color Code Calculator" << endl;
        cout << "2. Run Student Mark Tracker & Analyzer" << endl;
        cout << "3. Run Digital Signal Generator & Plotter" << endl;
        cout << "4. Run Digital Logic Gate Simulator" << endl;
        cout << "5. Run Number Base Converter" << endl;
        cout << "6. Exit System" << endl;
        cout << "======================================" << endl;
        cout << "Select a module option (1-6): ";
        
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
            runSignalGenerator();
        } else if (choice == 4) {
            runLogicGates();
        } else if (choice == 5) {
            runBaseConverter();
        } else if (choice == 6) {
            cout << "\nShutting down Toolkit. Thank you, Engineer!" << endl;
            break; // Breaks the infinite loop and gracefully exits the program
        } else {
            cout << "\nInvalid choice! Please select a number between 1 and 3." << endl;
        }
    }

    return 0;
}