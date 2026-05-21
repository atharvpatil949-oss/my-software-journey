#include "base_converter.h" // Links back to your menu promise
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// The actual kitchen recipe for your tool
void runBaseConverter() {
    string inputNumber;
    int choice, inputBase;

    cout << "\n--- ENTC Number Base Converter ---" << endl;
    cout << "1. Binary (Base-2)\n2. Decimal (Base-10)\n3. Hexadecimal (Base-16)" << endl;
    cout << "Select the base of your starting number (1-3): ";
    cin >> choice;

    if (choice == 1) inputBase = 2;
    else if (choice == 2) inputBase = 10;
    else if (choice == 3) inputBase = 16;
    else {
        cout << "Invalid choice! Returning to main menu." << endl;
        return; 
    }

    cout << "Enter the number: ";
    cin >> inputNumber;

    try {
        long long decimalValue = stoll(inputNumber, nullptr, inputBase);

        cout << "\n======================================" << endl;
        cout << "         CONVERSION RESULTS           " << endl;
        cout << "======================================" << endl;
        cout << dec << "Decimal (Base-10):     " << decimalValue << endl;
        cout << hex << uppercase << "Hexadecimal (Base-16): " << decimalValue << endl;
        cout << "Binary (Base-2):       " << bitset<16>(decimalValue) << endl;
        cout << "======================================" << endl;

    } catch (...) {
        cout << "\nError: The number you entered does not match the base you selected!" << endl;
    }
}