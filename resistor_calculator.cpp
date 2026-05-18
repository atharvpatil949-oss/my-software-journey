#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath> // Needed for the pow() function

using namespace std;

int main() {
    // Creating our electronic color code "dictionary"
    map<string, int> colorValues = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
        {"gray", 8}, {"white", 9}
    };

    string band1, band2, band3;

    cout << "--- ENTC Resistor Color Code Calculator ---" << endl;
    cout << "Enter the color of Band 1: ";
    cin >> band1;
    cout << "Enter the color of Band 2: ";
    cin >> band2;
    cout << "Enter the color of Band 3 (Multiplier): ";
    cin >> band3;
    // Logic: Checking if the entered colors actually exist in our dictionary
    if (colorValues.find(band1) == colorValues.end() || 
        colorValues.find(band2) == colorValues.end() || 
        colorValues.find(band3) == colorValues.end()) {
        
        cout << "Error: One or more invalid colors entered!" << endl;
        return 1; // Exit the program because of invalid input
    }

    // Mathematical Formula Logic:
    // Resistance = (Digit1 * 10 + Digit2) * 10^(MultiplierDigit)
    int digit1 = colorValues[band1];
    int digit2 = colorValues[band2];
    int multiplierExponent = colorValues[band3];

    // Using the math library pow(base, exponent) function
    double resistance = (digit1 * 10 + digit2) * pow(10, multiplierExponent);

    cout << "\n======================================" << endl;

    // If resistance is 1 Million Ohms or more
    if (resistance >= 1000000) {
        cout << "Calculated Resistance: " << (resistance / 1000000.0) << "MOhms (Megaohms)" << endl;
    }
    // If resistance is 1 Thousand Ohms or more
    else if (resistance >= 1000) {
        cout << "Calculated Resistance: " << (resistance / 1000.0) << "kOhms (Kiloohms)" << endl;
    }
    // Otherwise, keep it in standard Ohms
    else {
        cout << "Calculated Resistance: " << resistance << " ohms" << endl;
    }
    cout << "======================================" << endl;

    return 0;
}