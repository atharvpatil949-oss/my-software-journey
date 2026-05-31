#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

int main() {
    cout << "=== PHASE 1: RAW BITWISE LOGIC (Hardware Gates) ===" << endl;
    // 8-bit integers (0 to 255). We use unsigned to prevent sign-bit interference.
    uint8_t regA = 0b00001100; // Decimal 12
    uint8_t regB = 0b00001010; // Decimal 10

    cout << "Register A: " << bitset<8>(regA) << endl;
    cout << "Register B: " << bitset<8>(regB) << endl;

    // Bitwise AND (&): Output is 1 only if BOTH bits are 1 (Series Circuit)
    cout << "A AND B   : " << bitset<8>(regA & regB) << endl;

    // Bitwise OR (|): Output is 1 if AT LEAST ONE bit is 1 (Parallel Circuit)
    cout << "A OR B    : " << bitset<8>(regA | regB) << endl;

    // Bitwise XOR (^): Output is 1 if bits are DIFFERENT
    cout << "A XOR B   : " << bitset<8>(regA ^ regB) << endl;


    cout << "\n=== PHASE 2: BIT SHIFTING (Hardware Multiplication/Division) ===" << endl;
    uint8_t baseValue = 0b00000001; // Decimal 1
    
    cout << "Base Value     : " << bitset<8>(baseValue) << " (Decimal: " << (int)baseValue << ")" << endl;
    
    // Left Shift (<<): Shifts all bits left. Physically multiplies the integer by 2 per shift.
    uint8_t shiftedLeft = baseValue << 3;
    cout << "Shift Left (x8): " << bitset<8>(shiftedLeft) << " (Decimal: " << (int)shiftedLeft << ")" << endl;

    // Right Shift (>>): Shifts all bits right. Physically divides the integer by 2 per shift.
    uint8_t shiftedRight = shiftedLeft >> 1;
    cout << "Shift Right(/2): " << bitset<8>(shiftedRight) << " (Decimal: " << (int)shiftedRight << ")" << endl;


    cout << "\n=== PHASE 3: std::bitset (Automated Register Control) ===" << endl;
    // std::bitset is an STL container designed to safely manage hardware flags without raw arithmetic.
    
    // Simulating an 8-bit status register on a microcontroller
    bitset<8> statusRegister("00000000"); 
    cout << "Initial Status : " << statusRegister << endl;

    // Setting a specific pin high (e.g., turning on an LED at index 2)
    statusRegister.set(2);
    cout << "Pin 2 SET High : " << statusRegister << endl;

    // Flipping a specific pin (e.g., toggling a relay at index 5)
    statusRegister.flip(5);
    cout << "Pin 5 FLIPPED  : " << statusRegister << endl;

    // Checking a specific hardware flag
    if (statusRegister.test(2)) {
        cout << "System Diagnostic: Pin 2 circuit is currently ACTIVE." << endl;
    }

    return 0;
}