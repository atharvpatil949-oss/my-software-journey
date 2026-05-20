#include <iostream>
#include <string>
#include <bitset> // New library! Allows us to easily manipulate binary bits

using namespace std;

int main() {
    string inputNumber;
    int choice, inputBase;

    cout <<"--- ENTC Number Base Converter ---" << endl;
    cout << "1. Binary (Base-2)\n2. Decimal (Base-10)\n3. Hexadecimal (Base-16)" << endl;
    cout << "Select the base of your starting number (1-3): ";
    cin >> choice;

    // Map menu choice to actual mathematical base
    if (choice == 1) inputBase = 2;
    else if (choice == 2) inputBase = 10;
    else if (choice == 3) inputBase = 16;
    else {
        cout << "Invalid choice! System shutting down." << endl;
        return 1;
    }

    cout << "Enter the number: ";
    cin >> inputNumber;

    // The 'try-catch' block acts as a safety net. 
    // If a user types "XYZ" for a binary number, it catches the crash.
    try {
        // THE ANCHOR: Convert any string input into a standard Decimal integer
        // stoll() stands for "String To Long Long integer"
        long long decimalValue = stoll(inputNumber, nullptr, inputBase);

        cout << "\n======================================" << endl;
        cout << "         CONVERSION RESULTS           " << endl;
        cout << "======================================" << endl;
        
        // 1. Output as Decimal (Standard format)
        cout << dec << "Decimal (Base-10):     " << decimalValue << endl;
        
        // 2. Output as Hexadecimal 
        // 'hex' and 'uppercase' are built-in C++ formatters
        cout << hex << uppercase << "Hexadecimal (Base-16): " << decimalValue << endl;
        
        // 3. Output as Binary 
        // bitset<16> forces the number into a 16-bit binary format
        cout << "Binary (Base-2):       " << bitset<16>(decimalValue) << endl;
        
        cout << "======================================" << endl;

    } catch (...) {
        cout << "\nError: The number you entered does not match the base you selected!" << endl;
    }

    return 0;
}
