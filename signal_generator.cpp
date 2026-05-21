#include "signal_generator.h"
#include <iostream>
#include <vector>
#include <cmath> // Needed for sin() and M_PI (the value of pi)
#include <string>

using namespace std;

void runSignalGenerator() {
    double amplitude, frequency;
    
    cout << "\n--- ENTC Digital Signal Generator ---" << endl;
    cout << "Enter the peak amplitude (e.g., 5 for 5V): ";
    cin >> amplitude;
    cout << "Enter the frequency in Hz (e.g., 1 or 2): ";
    cin >> frequency;

    int totalSteps = 40; 
    cout << "\nGenerating Digital Signal Plot:\n" << endl;

    for (int i = 0; i < totalSteps; i++) {
        double t = (double)i / totalSteps;
        // Using M_PI from <cmath>
        double voltage = amplitude * sin(2 * M_PI * frequency * t);
        int spaces = static_cast<int>((voltage + amplitude) * 4);

        string waveLine(spaces, ' ');
        cout << waveLine << "*" << " (" << voltage << " V)" << endl;
    }
}