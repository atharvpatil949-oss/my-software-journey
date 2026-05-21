#include "resistor_calc.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath> // Needed for the pow() function

using namespace std;

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
