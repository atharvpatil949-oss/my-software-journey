#include <iostream>
#include <vector>
#include <cmath> // Needed for sin() and M_PI (the value of pi)
#include <string>

using namespace std;

int main() {
    double amplitude, frequency;

    cout <<"--- ENTC Digital Signal Generator ---"<< endl;
    cout <<"Enter the peak amplitude (e.g., 5 for 5V):";
    cin >> amplitude;
    cout <<"Enter the frequency in Hz(e.g., 1 or 2):";
cin >> frequency;

// We will use 40 discrete time steps to plot one timeline
int totalsteps = 40;
cout << "\nGenerating Digital Signal Plot:\n" << endl;

for (int i=0; i < totalsteps; i++) {
    // Convert the loop step into a time value (t) between 0.0 and 1.0 second
    double t = (double)i / totalsteps;

    // The exact ENTC mathematical formula: y=A*sin(2*pi*f*t)
    // M_PI is a built-in constant in <cmath> representing 3.14159..
    double voltage = amplitude * sin(2*M_PI* frequency * t);

    // Map the voltage value to a number of spaces so we can visually print it
    // We add 'amplitude' to shift the negati ve values of the wave into positive spaces
    int spaces = static_cast<int>((voltage + amplitude) * 4);

    // Print spaces followed by an asterik to "draw" the wave point
    string waveline(spaces, ' ');
    cout << waveline << "*" << " (" << voltage << " V)" << endl;
    }
    return 0;
}