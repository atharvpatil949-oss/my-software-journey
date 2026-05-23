#include <iostream>
using namespace std;

// THE REAL TOOL
// Notice the asterisks (*). We are specifically asking for Pointers (Addresses), not normal numbers.
void realSwap(int* a, int* b) {
    // We use the asterisk (*) inside the function to DEREFERENCE the pointers.
    // This means "Go inside the house at this address and get the value."
    int temp = *a; 
    *a = *b;       
    *b = temp;     
}

int main() {
    int x = 10;
    int y = 99;

    cout << "--- BEFORE SWAP ---" << endl;
    cout << "x is: " << x << " | y is: " << y << endl;

    // We use the ampersand (&) to pass the exact physical RAM coordinates of x and y
    realSwap(&x, &y);

    cout << "\n--- AFTER REAL SWAP ---" << endl;
    cout << "x is: " << x << " | y is: " << y << endl;

    return 0;
}