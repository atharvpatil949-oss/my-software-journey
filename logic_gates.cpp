#include <iostream>
#include <string>

using namespace std;

int main() {
    int gateChoice;
    int inputA, inputB;

    cout <<"--- ENTC Digital Logic Simulator ---" << endl;
    cout << "1. AND Gate\n2. OR Gate\n3. NOT Gate" << endl;
    cin >> gateChoice;

    if (gateChoice == 1) {
        cout << "\nEnter binary input A (0 or 1): "; cin >> inputA;
        cout <<"Enter binary input B (0 or 1): "; cin >> inputB;

        // The C++ bitwise AND operator is & (or logical &&)
        int result = inputA && inputB;

        cout << "\n--- TRUTH TABLE (AND) ---" << endl;
        cout << "A | B | Output" << endl;
        cout << "-----------------" << endl;
        cout << "0 | 0 |  0" << endl;
        cout << "0 | 1 |  0" << endl;
        cout << "1 | 0 |  0" << endl;
        cout << "1 | 1 |  1" << endl;
        cout << "------------------------" << endl;
        cout << "Your Input Result: " << inputA << " AND " << inputB << " = " << result << endl;
    } 
    else if (gateChoice == 2) {
        cout << "\nEnter binary input A (0 or 1): "; cin >> inputA;
        cout << "Enter binary input B (0 or 1): "; cin >> inputB;
        
        // The C++ logical OR operator is ||
        int result = inputA || inputB;
        
        cout << "\n--- TRUTH TABLE (OR) ---" << endl;
        cout << "A | B | Output" << endl;
        cout << "--------------" << endl;
        cout << "0 | 0 |   0" << endl;
        cout << "0 | 1 |   1" << endl;
        cout << "1 | 0 |   1" << endl;
        cout << "1 | 1 |   1" << endl;
        cout << "------------------------" << endl;
        cout << "Your Input Result: " << inputA << " OR " << inputB << " = " << result << endl;
    }
    else if (gateChoice == 3) {
        cout << "\nEnter single binary input A (0 or 1): "; cin >> inputA;
        
        // The C++ logical NOT operator is !
        int result = !inputA;
        
        cout << "\n--- TRUTH TABLE (NOT) ---" << endl;
        cout << "A | Output" << endl;
        cout << "----------" << endl;
        cout << "0 |   1" << endl;
        cout << "1 |   0" << endl;
        cout << "------------------------" << endl;
        cout << "Your Input Result: NOT " << inputA << " = " << result << endl;
    }
    else {
        cout << "Invalid gate selection!" << endl;
    }

    return 0;
}
    